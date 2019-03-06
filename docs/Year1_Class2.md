# Digital Migrations

## Year 1 Class 2

<img src="images/walters.png" width="400">

# 1

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

### Cool text games

These two games do some quite clever maths and javascript to make things that don't seem possible and that you could not do in any other way...

[Library of Babel](https://libraryofbabel.info/)
[Universal Paperclips by Frank Lansz](http://www.decisionproblem.com/paperclips/)

# 2

### Databending Images into Sound and back

![Skill Covered](https://img.shields.io/badge/skill-glitching-brightgreen.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-Audacity-lightblue.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-DataMaking-magenta.svg?longCache=true&style=plastic)

<img src="images/tigerseries.png" width="400">

That's enough `html` and code hacking! Lets turn images into sound, play with the sound and turn the sound back into an image. Let's do Audiobending!

Follow my [Instructions](AudioBending.md) simplified from this Introduction to [Databending images with sound software](http://www.hellocatfood.com/databending-using-audacity/)

We are using [Audacity](https://www.audacityteam.org/download/)

## Cross Student Experiments

Stephen discovered you can apply the same **audiobending** process to video; `.avi` file extension works so you may want to experiment with `.mpeg` etc. You can only use short clips we think. 

Connor was beautifully hand masking and glitching his video frames for a project which was taking a horrendous amount of time: I was looking at custom [ImageMagick](http://www.imagemagick.org/) scripts that could apply effects to big batches of image files like this [custom glitch ImageMagick script by Fred Weinhaus](http://www.fmwconcepts.com/imagemagick/videoglitch/index.php) but Stephen's experimentation since our last workshop showed you could do the same thing to video files. Audiobending has sped things up considerably! Someone tell glitchy hiphop director of Cole Bennett as he's still doing it by hand! 

So just follow the same databending instructions but use `.avi`, `.mov`, `.mp4` and `.mpeg` files, so make sure when you export the uncompressed 'Other audio format' you add the appropriate file ending as your source file. Also make sure you use `A-law` in your Encoding.

You can explore the different things ImageMagick can do with [JQMagick](http://jqmagick.imagemagick.org/) but it's quite an advanced text based coding tool for dealing with multiple image files of all kinds, particular if you wanted to automate your manipulations, so takes a bit of experience using the command line and if you want to do it on Windows you'll need to install [cygwin](http://www.cygwin.com/install.html) I made some setup notes for cygwin [here](https://gitlab.com/DomesticScience/InteractiveNonFiction/blob/master/cygwin/README.md)

## Mo' `webgl` Mo' Problems 

Since writing this I've noticed that some recent auto updates of Chrome means google have messed up `webgl` which drives stuff like openjscad

A fix that worked for me was to enable webgl related flags in Chrome settings by typing in these addresses into the address bar: `chrome://flags/#ignore-gpu-blacklist` and `chrome://flags/#enable-webgl-draft-extensions` 

Then goto `chrome://settings/` show *Advanced Settings* and under *System* enable the switch *Use hardware acceleration when available* so it's on.

Failing that use Firefox. It's nicer anyway.

