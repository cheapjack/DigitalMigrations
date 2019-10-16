// Digital Migrations 2019 @cheapjack tutorial for making memes
// with p5.js to get the hang of loading in external assets and drawing text
// and images
// setup the variable memeFont


// setup the variable img & myFont to store our image and font
let img;
let myFont;

// make a function to pre-load it before your sketch runs
// memes often use Impact.ttf a true-type font
function preload() {
  img = loadImage('boromir.jpg');
  myFont = loadFont('Impact.ttf');
}

// setup as usual
function setup() {
	//createCanvas(windowWidth, windowHeight);
	// make the canvas fit the meme img size 
    // you use 'dot notation' which means you can access certain
    // predefined parameters to certain 'objects'
    // so you can also get the screen width of whatever device 
    // you load the sketch on in a browser window  with 
    // window.screen.width or window.screen.height
    createCanvas(img.width, img.height);
	background(0);
	image(img, 0, 0);
    fill(255,255,255);
    textFont(myFont);
	textAlign(CENTER);
    textSize(36);
    text('ONE DOES NOT SIMPLY', img.width/2, 50);
	text('DRAG DIGITAL IMAGES', img.width/2, img.height-60);
    text('INTO OUR PROCESSING SKETCHES', img.width/2, img.height-20);
    }

function draw() {
	// uncomment the below to preview what we'll be moving onto next
    //ellipse(mouseX, mouseY, 20, 20);
    }
