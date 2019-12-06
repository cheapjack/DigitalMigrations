# Digital Migrations

## Year 1 Class 2

<img src="images/walters.png" width="400">
## Introduction to Data Tools with Processing and Javascript.

### Year 1 Class 2

Join this workshop to introduce you to the powerful programme [Processing](https://processing.org/) and [P5.js](https://p5js.org/). No coding experience required: develop simple digital literacy and hacking skills, take part in an exciting online community and spin up simple online artworks. This introduces a literacy in digital image manipulation, generation and interactivity with simple practical approaches to help you critically engage and distribute your work digitally.

 * Introduction to simple image manipulation, generative and interactive digital work with Processing and Javascript.
 * Basic data visualisation.
 * Simple instant publishing on the web with [glitch](http://glitch.com/) and [OpenProcessing](http://openprocessing.org/)

# 1

<img src="images/boromir_meme.jpg" width="400">

### Adventures in Processing

![Skill Covered](https://img.shields.io/badge/skill-Processing-magenta.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-JavaScript-blue.svg?longCache=true&style=plastic)

Processing can be downloaded (for free!) and used to develop projects on your own computer. We are going to look at the most recent developments in [p5.js](https://p5js.org) which is processing for the contemporary browser. It means you can display it on pretty much any browser and offers scope for mobile devices and cheap ways to build installations on more modest platforms like Raspberry Pi rather than having to have a big energy hungry PC hidden behind the scenes.

I like it because learning processing this way you also learn javascript which most of the web is run on so plenty of transferable skills.

It also makes playing and sharing with other people really easy as we shall see by using [openprocessing](http://openprocessing.org) to hack and play with processing code


## Getting Started

We'll be working through some of the [Learning Resources](https://p5js.org/learn/). We'll start with shape making and the basic coordinate system in Processing. Then we'll look into images. You can look up everything in the [Reference](https://p5js.org/reference/)
and play with [Examples](https://p5js.org/examples/). Finally when it comes to publishing ie displaying your work beyond openprocessing and your own computer we'll look into the the [Get Started Tutorial](https://p5js.org/get-started/) 

First off let's get setup on [openprocessing](http://openprocessing.org) where we are going to work

### Throw Some Shapes

Let's start simply 

We are going to follow the [Basic shape drawing](https://p5js.org/learn/coordinate-system-and-shapes.html) tutorials by reading along and pasting into an openprocessing sketch.

I've also combined it into a [sketch file called robotmover.js on openprocessing here](https://www.openprocessing.org/sketch/771430) 

The code is below

```
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
    createCanvas(100, 100);
    rectMode(CENTER);
    //noLoop();
    //rectMode(CORNERS);
}

function draw(){
    point(40, 50); // point(x, y)
    //line(10, 20, 50, 20); // line(x1, y1, x2, y2)
    //rect(10, 20, 40, 30); // rect(x, y, width, height)
    //ellipse(30, 30, 40, 60); // ellipse(x, y, width, height)
    //background(200);
    //robot(x,100);
    //x++;
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

```


We can follow up other basics like [Color](https://p5js.org/learn/color.html) later

# 2

### Gonna Make Memes

Adding text onto images is obviously a well known internet skill.

We'll be remaking the meme above in open processing which get's us using our coordinate knowledge while learning how to do text and cope with loading files and other assets  

First off paste this code into a new open processing sketch

```
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
```

Then go to the 3 dots on the top right for more options, click the file tab and import the `boromir` file you'll find in `DigitalMigrations/docs/images/boromir.jpg` and `DigitalMigrations/p5Tutorials/assets/Impact.ttf`

You'll see how the code 'pre-loads' the images and font files the sketch needs

# 3

## Publishing

![Skill Covered](https://img.shields.io/badge/skill-html-green.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-JavaScript-blue.svg?longCache=true&style=plastic)

One of the easiest ways to leave the cosy safety of openprocessing and onto the world wild web is to host project files on a computer or server on the internet. All you need is an `.html` file with a link to the processing libraries, a `sketch.js` javascript file; other resources like snazzy css etc can be added later; and any browser can run your code. 

Have a look at the [Get Started](https://p5js.org/get-started/) templates and try it out in a text editor or use [Thimble](https://thimble.mozilla.org/en-US/) or it's successor [glitch](https://glitch.com) or other things like [CodePen](https://codepen.io/pen/). 

You can just copy and paste code from the Get Started page and see this working locally, (ie on your computer) or by downloading or `git clone`'ing the [DigitalMigrations](https://github.com/cheapjack/DigitalMigrations) repo, onto your computer and opening [index.html](https://github.com/cheapjack/DigitalMigrations/blob/master/p5Tutorials/index.html) and this minimal webpage will load the processing library, and run your code. 

To run different sketches just make new `.js` files with different names and make the `.html` file load the new sketch javascript file.

Have a look at my [Example Robot Code on Glitch](https://glitch.com/~uncovered-sesame)


## Data Tables

![Skill Covered](https://img.shields.io/badge/skill-Processing-magenta.svg?longCache=true&style=plastic)
![Skill](https://img.shields.io/badge/skill-data-yellowgreen)
![Skill](https://img.shields.io/badge/skill-csv-pink)

Quick Recap on variables and drawing. Login in (or sign up if you havent already) to [openprocessing](https://www.openprocessing.org) and go to my [recap on variables](https://www.openprocessing.org/sketch/792463) sketch, fork it and see what we can change.

### Maps and CSV

Using `.csv` files with latitude and longitude data in them can be really effective. Login in (or sign up if you havent already) to [openprocessing](https://www.openprocessing.org) and go to my [Tutorial](https://www.openprocessing.org/sketch/790439)

This uses the `flights.csv` file to map out flight density. What's intersting is that only a list of two sets of numbers generates a recognisable map of the world; notice there is no world map data included just 2 floating point numbers. You actually have the data 'schema' for this kind of map intuitively available in your head thanks to your experience looking at maps at school and in general modernist (and colonial) culture. 

You'll notice you can also change to another much smaller dataset showing locations of air quality sensors in York.

See if you can find more data sets or [make your own](#csv-diy)


### Adventures in Text

![Skill Covered](https://img.shields.io/badge/skill-DataMaking-magenta.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-html-green.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-JavaScript-blue.svg?longCache=true&style=plastic)

Thinking of data as a practice means you can make present and manipulate text and images in interactive ways. 

The most ubiquitous space for manipulating and presenting data is the humble old webpage built on the `HTML` protocol. It's on our phones and laptops and computers. It's even at our supermarket till and sometimes not even connected to a screen.

We are going to hack an example webpage that uses `HTML` `CSS` and `JavaScript` to display a random image and glue together strings of text.

It's based on this [Silly Story Generator](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/Silly_story_generator) tutorial by my pal [Chris Mills](https://developer.mozilla.org/en-US/profiles/chrisdavidmills) who is a senior writer at [Mozilla Developer Network](https://developer.mozilla.org) and really cares for the web and it's potential. 

If at the end of this you want to learn more I heartily recommend his and his colleagues [tutorials on Getting Started With the Web](https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web).

I'd also *always* refer to the [MDN Web Docs](https://developer.mozilla.org/en-US/) if you ever want to know how to do or use anything on the web (especially if you want it made by people who really care for their community and the internet and hate advert filled webpages. If you followed their tutorials and learnt [Open Processing](https://www.openprocessing.org/) you are well on your way to having all the data and creative coding skills to develop nuanced, meaningful and powerful digital work and participate in creative digital culture. Well for as long as the internet is still turned on all the time, anyway.

For us we are going to make a really simple web page that:

 * Randomly picks from 3 images every time you click on the image
 * Asks **"Who's Reading"** in a text box and then addresses this person in a block of text
 * Provides an `Add to Story` Button which provides a prompt in the web page where you can add as many strings of text you like, which gets saved in a `variable` in the web page's `JavaScript` file 

First off make sure you're using Chrome or Mozilla Firefox and have a play with the finished webpage [here](adventuresintext/index.html)

Now have a look at these 2 files in the [DigitalMigrations repository](https://github.com/cheapjack/DigitalMigrations)

`DigitalMigrations/adventuresintext/index.html` [here](https://github.com/cheapjack/DigitalMigrations/blob/master/adventuresintext/index.html) and  `DigitalMigrations/adventuresintext/main.js` [here](https://github.com/cheapjack/DigitalMigrations/blob/master/adventuresintext/main.js)

We're going to use Mozilla's [Thimble](https://thimble.mozilla.org) service to edit and play with these files. Open up the site and **Start a Project From Scratch**. 

Now download the [DigitalMigrations repository](https://github.com/cheapjack/DigitalMigrations) to somewhere on your workspace, it will appear as a directory called `DigitalMigrations-master`.

Now delete the existing `index.html` and `style.css` files in the Thimble window and drag in the files from the `adventuresintext` folder (not the folder itself). Only Chrome will let you do that; please dont use the default Windows Edge browser it's horrible. If for some reason it wont let you drag and drop try to cut and paste the text from the `index.html` & `main.js` files from the repo online into new files called `index.html`, `style.css` and `main.js`. You also need a folder of images called `images`  

These files are well commented and we'll walk through them together.

Don't worry if this is all new and looks crazily complicated, I'm going to guide you through hacking these 2 files to make them your own. You'll soon be generating stuff and learn really simple ways of displaying some of our experiments on the web. You are going to understand what you can change to make it your own and I'll introduce some of the concepts best I can. I'm not a programmer I've just become literate in some of the basics and picked up resources that help people and help me do things that are useful in my practice and research and hopefully yours.

By the end you will have picked up an introduction to how we can play with webpages to make work, present the other skills we learnt last class and generally sketch things out using the web browser as canvas.

All of this course content is available and downloadable from the [DigitalMigrations github](https://github.com/cheapjack/DigitalMigrations)

**Tutorial and walkthrough continues in lesson with some more supporting info**

### Examples of similar work online

[J.R.Carpenters Notes on the Voyage of Owl and Girl](http://luckysoap.com/owlandgirl/)
[Simple python version](https://gist.github.com/samplereality/d82f5c2d8abe2b5d45cd)


# 2



### Cool text games

These two games do some quite clever maths and javascript to make things that don't seem possible and that you could not do in any other way...

[Library of Babel](https://libraryofbabel.info/)
[Universal Paperclips by Frank Lansz](http://www.decisionproblem.com/paperclips/)

