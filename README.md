
# Digital Migrations

## Digital Skills workshops at LICA

<img src="images/walters.png" width=400>

A series of workshop materials and links to think about simple digital skills for art practice at LICA. Rather than teach digital tools we might know about or can buy and learn elsewhere like Photoshop, our approach is an easy introduction by doing to the idea of manipulating 'data' or information for creative ends. 

More on [why below](https://github.com/cheapjack/DigitalMigrations#why-data)

### Getting Started

We are going to use in-browser tools made by the excellent multimedia designer/technologist [Georg AKA 'Snorpey'](https://fishnation.de/) that let you manipulate images:
 * [Glitching](https://snorpey.github.io/jpg-glitch/)
 * [Triangulation](http://snorpey.github.io/triangulation)
 * [Distorting Grid](http://snorpey.github.io/distort-grid)
 * [Contrast Distort](http://snorpey.github.io/contrast-distort/)

You can get to all of them from [here](http://snorpey.github.io/experiments/) including links to all the javascript code that made them, shared on the popular code sharing platform, github.

Each webpage contains a web application that let's you drag and drop images from the desktop into the browser window and then distort them and export them. Although there are tonnes of things like this online, Snorpey has open sourced all its simple, contemporary javascript code to refer to on github so should someone want to take this on into their practice it is quite translatable into well established artist friendly coding environments like [Processing](https://processing.org/) some interaction software built especially for artists and non-programmers.

This means we dont have to worry about installing new software. It's also how most digital work is carried out now, using the Internet Browser (like Mozilla Firefox or Google Chrome) like a computer's 'operating system'. The `HTML` code loads the Javascript Snorpey has written to make the image processing work: you can really build pretty much anything a computer does into the browser. 

Processing itself can be downloaded but also used in a modern Internet Browser as [p5js.org](https://p5js.org/).

Even if you know very little digital image work and uninterested in coding you can quikcly manipulate and re-manipulate images easily without using more traditional image processing tools like Adobe Photoshop or the open source free alternative [GIMP](https://www.gimp.org/)

### Image Processing Exercise

 * Try getting an image with yourself onto the computer desktop and drag into the window of one of the webpages above and play with the controls;
 * Export one with the export or Download image button, or with the glitch choose Save in Browser from the menu and Download the image
 * Open another and drag the exported file into that.
 * Repeat until your face is completely destroyed

### 3D object making in the browser

[OpesSCAD](http://www.openscad.org/) is a tool for making 3D and 2D shapes with data and code. Like many things, there's now a version that runs in a webpage. So we are going to use OpenJSCAD (javascript implementation of OpenSCAD) in the browser

 * Open [OpenJSCAD.org](https://openjscad.org/) and select ALL of the code in the right panel of the web page and replace with this:

```
    function main(){
           return cube({size: 10, center: true})
              .translate([-20, -10, 12]);
                  }
```

 * Press SHIFT & RETURN (enter) and it will render the new code. Change some numbers, see what happens
 * You can export `.stl` files for 3d printing right from the browser like our [example above](models/cube.stl) and [this](models/Migrations.stl).
 * You can take screen grabs, clean up and drop into the snorpey glitching sites.
 * You can also export 2D shapes with OpenSCAD as `.svg` files for laser cutting of CNC milling or further image play or processing.

### Make your own dataset

Data does not have to be big. I'm making my own based on times I drink coffee in a 4 hour period in the office.

Im going to plot the times I do that on a graph.

![graph](https://user-images.githubusercontent.com/128456/44107570-b9cee20c-9fef-11e8-9cdf-35f359650686.png)

Then Im going to turn it into a list of graph plots

`[0, 0], [1, 1], [2, 1], [3, 0], [4, 1], [4, 0]`

In most programming languages this data can be made into a list like this and can be stored in a type of variable called an array. Javascript handles all kinds of variable types, you just have to 'declare' what you want to call it and format it like this.

`var c = [[0, 0], [1, 1], [2, 1], [3, 0], [4, 1], [4, 0]];`

We're going to use this as a data source to draw a shape in the OpenJSCAD browser by copying [this bit of code](openjscad/coffeeGraph.jscad) and pasting into the code panel and using SHIFT & RETURN to render it.

### Further Tools

Want to find out more about learning Processing maybe check out Dan Shiffman (Processing inventor) [Highly Enthusiastic video](http://hello.p5js.org/). If you want to jump in you can browse the work of a huge community of artists and creatives on the [Open Processing](https://www.openprocessing.org/) site which gets you coding straight away in the browser without downloading anything.

### Databending Images into Sound and back
Make images, sound, play with the sound and turn back to images.

<img src="imageAndSound/tigerseries.bmp" width=400>

Follow my [Instructions](imageAndSound/README.md) simplified from this Introduction to [Databending images with sound software](http://www.hellocatfood.com/databending-using-audacity/)

Using [Audacity](https://www.audacityteam.org/download/)

#### 3D design tools toward 3D printing and fabrication
 * [OpenSCAD](http://www.openscad.org/)
 * Or for a more simple design environment setup a free account for [TinkerCAD](https://www.tinkercad.com/)

#### Text and Data Mining
I made a series of tutorial and workshop materials based on manipulating data for the [Interactive Non Fiction Tools](https://gitlab.com/DomesticScience/InteractiveNonFiction) resources for [Domestic Science](http://domesticscience.org.uk).

You may like to checkout [some example datasets](https://gitlab.com/DomesticScience/InteractiveNonFiction/tree/master/chooseYourOwnAdventure/adventuresInText/datasets) that are 'hackable' in spreadsheet software like Microsoft Excel and use them as data to make shapes.

### Why Data

Usually all the data stuff when we make digital images or video happens behind the scenes so you never think about it and for good reason; if you want to manipulate images in creative ways you often just want instant results. Then you can get on with the important stuff of making work.

Computer scientists have abstracted all the data stuff away so you can use it as a tool which is all good. However, thinking on a simple level of how a digital image is made up of individual 'pixels' with numbers assigned to it has it's advantages. When images are turned into a list of numbers; into data with a very specific schema or format, they can be 'translated' and manipulated in powerful ways. Just thinking of an image like this gives you access to a literacy in what your tools are actually doing which could lead to you making your own tools or using your existing ones in new ways. And literacy can lead to the intuition and development we often need in our art practices. 

In many ways a digital image is not an image at all but more like an abstract 'spatial' map of related coordinates and numbers in a colour space that use a format or schema that other people and machines know about so they can be shared on phones, projectors, monitors, or inkjet printers.

So our image data 'maps', can be read into other formats just as someone drawing will map visual experience to marks on paper; images can be turned into sound, manipulated as if they were so and translated back into images. 

You can also make up data that's not referring to sound or colour but perhaps record experiences or find data online.

This is a series of exercises to show that doing that is not that difficult.

## Artists who use Data

<img src="https://www.slideshare.net/r00s/rosa-menkman-a-vernacular-of-file-formats-4923967" width=400>
Rosa Menkman "vernacular of file formats" 

Nick Briz "glitch codec tutorial" [video](https://www.youtube.com/watch?v=hOemlx2sBIo)

Takeshi Murata ["pink dot"](https://www.youtube.com/watch?v=eZkY6zFbwgQ)

Phillip Sterns ["glitch textiles"](https://www.glitchtextiles.com/)

[James Bridle](http://jamesbridle.com/works)

Directory of data artists [Big Band Data Project at Somerset House](http://bigbangdata.somersethouse.org.uk/artists/)

[Ellie Harrison](https://www.ellieharrison.com/)

[Sam Thulin](http://www.lancaster.ac.uk/cemore/author/sthulin/) does a [Data Sensor Drone-By](http://www.lancaster.ac.uk/cemore/drone-over-data-centre/)
