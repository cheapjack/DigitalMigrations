// Setup a variable for the width of the rectangles
let rectWidth;

// This is the setup function all sketches need
function setup() {
    //size of your screen on the web page
  createCanvas(400, 400);
  // Dont bother doing an outline on the shape
  noStroke();
  // set the background color
  background(230);
  // set the size of the rectWidth variable 
  rectWidth = width / 2;
}

function draw() {
  // keep draw() here to continue looping while waiting for keys
  keyPressed()
}

// function to listen for key presses
function keyPressed() {
  let keyIndex = -1;
  if (key >= 'a' && key <= 'z') {
    keyIndex = key.charCodeAt(0) - 'a'.charCodeAt(0);
  }
  if (keyIndex === -1) {
    // If it's not a letter key, clear the screen
    background(230);
  } else {
    // It's a letter key, fill a rectangle
    // generate random numbers for r,g,b color values
    randFill_r = Math.floor(Math.random() * 255 + 1);
    randFill_g = Math.floor(Math.random() * 200 + 2);
    randFill_b = Math.floor(Math.random() * 255 + 1);
    // a for loop iterates thru the value of i and then sticks into the way we fill our rectangle and color it
    for (let i = 1; i < 10; i++){
        //fill it
      fill(randFill_r, randFill_g, randFill_b, i);
    }
    // map the index of key press values to a minimum and maximum value
    // map(x,y,min, max)
    // and assign it to the value x
    let x = map(keyIndex, 0, 25, 0, width - rectWidth);
    // the rect function to draw our rectangle, so we plug the x value into the 
    // x coordinate of rect(x, y, width, height) so each keypress changes the position of where to draw a rectangle left to right
    rect(x, 0, rectWidth, height);
  }
}
