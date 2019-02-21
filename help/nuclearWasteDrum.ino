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
////
const int analogPin = A0;    // pin that the sensor is attached to
// so make sure the
const int pingPin = 5;
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 30;   // an arbitrary threshold level that's in the range of the analog input
const int startVolume = 20;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Library Test");
 
  
  // initialise the music player
  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));

  musicPlayer.sineTest(0x44, 500);    // Make a tone to indicate VS1053 is working
 
  if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }
  Serial.println("SD OK!");
  Serial.println();
  // list files
  printDirectory(SD.open("/"), 0);
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(startVolume,startVolume);

  /***** Two interrupt options! *******/ 
  // This option uses timer0, this means timer1 & t2 are not required
  // (so you can use 'em for Servos, etc) BUT millis() can lose time
  // since we're hitchhiking on top of the millis() tracker
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT);
  
  // This option uses a pin interrupt. No timers required! But DREQ
  // must be on an interrupt pin. For Uno/Duemilanove/Diecimilla
  // that's Digital #2 or #3
  // See http://arduino.cc/en/Reference/attachInterrupt for other pins
  // *** This method is preferred
  if (! musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT))
    Serial.println(F("DREQ pin is not an interrupt pin"));
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void loop() {
   // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.println();
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
// delay for stability
  delay(100);

  // if the cm value is high enough, turn on the LED and playMusic()
  if (cm > threshold) {
    digitalWrite(ledPin, HIGH);
    playMusic();
    // dont bother otherwise set LED to off
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1);        // delay in between reads for stability

  
}


void playMusic() {  

  // Start playing a file, then we can do stuff while waiting for it to finish
  if (! musicPlayer.startPlayingFile("/track001.mp3")) {
    Serial.println("Could not open file track001.mp3");
    while (1);
  }
  Serial.println(F("Started playing"));

  while (musicPlayer.playingMusic) {
    // file is now playing in the 'background' so now's a good time
    // to do something else like handling our sensor :)
    Serial.print(".");

    //OK lets check for reading from the echo pin on our sensor
    // read the input on analog pin 0: hopefully this is an ok pin
    // if not we can try pins A1-4
    int sensorValue = analogRead(analogPin);
    // Convert the analog reading (which probably goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    // print out the value you read:
    Serial.println("Voltage is...");
    Serial.println(voltage);
    // really roughly take the voltage off the volume value, we can
    // tweak this and follow the sensor guides to estimate distance
    // but this should get things started
    float newVolume = (20 - voltage);
    Serial.println("Volume is now...");
    Serial.println(newVolume);
    musicPlayer.setVolume(newVolume,newVolume);
    delay(500);
    }
    Serial.println("Done playing music");
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
