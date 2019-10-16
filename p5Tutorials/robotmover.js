// OK the first line of this code is // which processing or javascript ignores
// So you can write comments. We saw this in earlier classes. It's a useful
// convention so that when you or others return to the code they'll 
// understand what you were trying to do!
// for longer commments with multiple lines you can
/* use this
and it will comment
out
all the lines following until you end it with
*/
// now you'll see the code below light back up.
// All processing sketches call a setup() and draw() function
// A function is an object that when you 'call' it it runs the code in it's curly brackets
// 
// Setup a useful value for later
let x = 0;

function setup(){
  createCanvas(200, 500);
	rectMode(CENTER);
	//noLoop();
	//rectMode(CORNERS);
}

function draw(){
	//point(40, 50); // point(x, y)
	//line(10, 20, 50, 20); // line(x1, y1, x2, y2)
  //rect(10, 20, 40, 30); // rect(x, y, width, height)
	//ellipse(30, 30, 40, 60); // ellipse(x, y, width, height)
	background(200);
	robot(x,100);
	x++;
}

// Robot Drawing function
// Don't forget to increase the canvas size
	
function robot(pos_x,pos_y){
	rect(pos_x,pos_y,20,100);
  ellipse(pos_x,pos_y-30,60,60);
  ellipse(pos_x - 19,pos_y-30,16,32);
  ellipse(pos_x+19,pos_y-30,16,32);
  line(pos_x-10,pos_y+50,pos_x-20,pos_y+60);
  line(pos_x+10,pos_y+50,pos_x+20,pos_y+60);
}
/*
function mousePressed() {
  loop();
}
function mouseReleased() {
  noLoop();
}
*/


/* FOR LOOP
for (let i = 0; i < 100; i++) {
		point(40 + i, 50 + i); // point(x, y)
	}
}
*/