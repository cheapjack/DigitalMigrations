/*************************************************** 
  This is taken from the Adafruit VS1053 Codec Breakout
  example code and combined with the Examples/06.Sensors/Ping code

  Uses the sensor SRF05 described
  ----> https://www.dfrobot.com/wiki/index.php/SRF05_Ultrasonic_sensor_(SKU:SEN0006) 
  
  Designed specifically to work with the Adafruit VS1053 Codec Breakout 
  ----> https://www.adafruit.com/products/1381

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Yes! we did but via Pimoroni 'cos they live in Halifax

  Written by Limor Fried/Ladyada for Adafruit Industries.
  Modded by Ross Dalziel for Stephen Willis  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 
  // create breakout-example object!
  //Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

// Setup our variables

const int pingPin = 5; //pin that triggers a ping and reads it back on the same pin
const int ledPin = 13;       // pin that the LED is attached to
const int startVolume = 10;   // an arbitrary volume level to start with, with VS1053 smaller numbers are louder volumes!
const int threshold = 20; // arbitrary distance threshold to cross to play a file 
const float multiplier = 1.0; // a multiplier to adjust the effect of distance changes the volume, 
//can be changed to 0.5, 2.0 etc. float as we'll need decimals

// Setup and print some helpful debugging with Serial

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Library Test");
  digitalWrite(ledPin, LOW);
  // initialise the music player
  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?")); // Throw error if musicPlayer fails to begin
     while (1); // keep the error while its True ie 1
  }
  
  Serial.println(F("VS1053 found")); // 's ok working
  musicPlayer.sineTest(0x44, 500);    // Make a tone to indicate VS1053 is working
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  
  if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more while theres no SD present
  }
  
  Serial.println("SD OK!"); // yay it works!
  Serial.println();
  // list files
  printDirectory(SD.open("/"), 0);
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(startVolume,startVolume);

  // Two interrupt options! // 
  // Interrupt just means we can have a file playing but do something else, but with a minor cost.
  // OPTION 1
  // This option uses timer0, this means timer1 & t2 are not required
  // (so you can use 'em for Servos, etc) BUT millis() can lose time
  // since we're hitchhiking on top of the millis() tracker
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT);
  // OPTION 2
  // This option uses a pin interrupt. No timers required! But DREQ
  // must be on an interrupt pin. For Uno/Duemilanove/Diecimilla
  // that's Digital #2 or #3
  // See http://arduino.cc/en/Reference/attachInterrupt for other pins
  // *** This method is preferred
  if (! musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT))
    Serial.println(F("DREQ pin is not an interrupt pin"));

}

// this is a function that returns a long variable (a number with lots of floating points) and not an int.
// If we want to compare to an int we can convert later with the native int(x) function

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

// Make a function to keep our PING code tidy. It's not a void function like void loop() because we want to return something, in this case distance.

int ping() {
    // establish variables for duration of the ping,
    // and the distance result in centimeters:
    long duration, cm;
    int distance = 0;
    // The PING is triggered by a HIGH pulse OUT of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    // The same pin is used to read the signal IN from the PING: a HIGH
    // pulse whose duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
    // convert the time into a distance with our function above; you can call a function
    // within another function
    cm = microsecondsToCentimeters(duration);
    // Print to serial for info
    Serial.println();
    Serial.print("Distance from first ping = ");
    Serial.print(cm);
    Serial.print(" cm");
    Serial.println();
    // change it to an integer to make things simple
    distance = int(cm);
    return distance;
    // delay for stability
    delay(100);
}

// our main loop

void loop() {
    int distance;
    // do a ping to get the distance to sensor, whatever it returns call it distance
    distance = ping();
    // if the returned ping() distance value is close (low) enough, turn on the LED and playMusic()
    if (distance < threshold) {
        digitalWrite(ledPin, HIGH);
        Serial.print("Distance under threshold so play music");
        Serial.println();
        playMusic();
        // dont bother otherwise & set LED to off
        } else {
            Serial.print("You're not close enough! So not playing the file");
            digitalWrite(ledPin, LOW);
            }
        delay(1000);        // delay in between reads for stability
        }

// here's our play music function, void because we dont need to return anything

void playMusic() {  
  int latestDistance;
  // Start playing a file, then we can do stuff while waiting for it to finish
  if (! musicPlayer.startPlayingFile("/track001.mp3")) {
    Serial.print("Could not open file track001.mp3"); // error message if we find musicPlayer NOT (!) playing 
    while (1);
  }
  Serial.println(F("Started playing"));
  while (musicPlayer.playingMusic) {
    // file is now playing in the 'background' so now's a good time
    // to do something else like handling our sensor and doing a PING :)
    Serial.print(".");
    latestDistance = ping();
    Serial.print("Distance is now: ");
    Serial.print(latestDistance);
    Serial.print(" cm");
    Serial.println();
    // Add the distance value to the volume value because lower values mean louder sound
    // so big distance == bigger volume value == lower actual volume
    // tweak this if its too extreme
    int newVolume = startVolume + latestDistance * multiplier;
    Serial.print("Volume is now:");
    Serial.print(newVolume);
    musicPlayer.setVolume(newVolume,newVolume);
    delay(1000); // delay for stability
    // this loops as long as musicPlayer is playingMusic
    }
    Serial.println("Done playing music");
    // turn LED off when done playing
    digitalWrite(ledPin, LOW);
    }


/// File listing helper
void printDirectory(File dir, int numTabs) {
   while(true) {
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
