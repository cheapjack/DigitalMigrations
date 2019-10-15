## Simple Tutorial sketches for Processing in the Browser

Processing can be downloaded and used to develop projects on your own computer but we are going to look at the most recent developments in p5.js which is processing for the contemporary browser. It means you can display it on any browser and offers scope for mobile devices while also cheap ways to build installations on more modest platforms like Raspberry Pi rather than having to have a big energy hungry PC hidden behind the scenes.

I like it because learning processing this way you also learn javascript which most of the web is run on so plenty of transferable skills.

It also makes playing and sharing with other people really easy as we shall see by using [openprocessing](http://openprocessing.org) to hack and play with processing code

## Publishing

One of the easiest ways to leave openprocessing is to host project files on a computer or server on the internet. All you need is an `.html` file with a link to the processing libraries, a `sketch.js` javascript file; other resources like snazzy css etc can be added later; and any browser can run your code. You could do this in any text editor or use [Thimble](https://thimble.mozilla.org/en-US/) or after December 2019 it's successor [glitch](https://glitch.com) or other things like [CodePen](https://codepen.io/pen/). 

You can see this working locally, (ie on your computer) by downloading or `git clone`'ing  this repo, onto your computer and opening [index.html](index.html) and this minimal webpage will load the processing library, and run your code. 

To run different sketches just make new `.js` files with different names and make the `.html` file load the new sketch javascript file.


