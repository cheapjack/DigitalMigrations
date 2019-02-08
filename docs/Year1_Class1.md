
# Digital Migrations

## Year 1 Class 1

<img src="images/walters.png" width="400">

# 1

## Getting Started

### Image Glitching

![Skill Covered](https://img.shields.io/badge/skill-glitching-brightgreen.svg?longCache=true&style=plastic)

We are going to use in-browser tools made by the excellent multimedia designer/technologist [Georg AKA 'Snorpey'](https://fishnation.de/) that let you manipulate images:
 * [Glitching](https://snorpey.github.io/jpg-glitch/)
 * [Triangulation](http://snorpey.github.io/triangulation)
 * [Contrast Distort](http://snorpey.github.io/contrast-distort/)
 * [Distorting Grid](http://snorpey.github.io/distort-grid)

You can get to all of them from [here](http://snorpey.github.io/experiments/) including links to all the javascript code that made them, shared on the popular code sharing platform, github.

Each webpage contains a web application that let's you drag and drop images from the desktop into the browser window and then distort them and export them. Although there are tonnes of things like this online, Snorpey has open sourced all its simple, contemporary javascript code to refer to on github so should someone want to take this on into their practice it is quite translatable into well established artist friendly coding environments like [Processing](https://processing.org/) some interaction software built especially for artists and non-programmers.

Processing itself can be downloaded but also used in a modern Internet Browser as [p5js.org](https://p5js.org/).

### Image Glitching Exercise

 * Try getting an image with yourself onto the computer desktop and drag into the window of one of the webpages above and play with the controls;
 * Export one with the export or Download image button, or with the glitch choose Save in Browser from the menu and Download the image
 * Open another and drag the exported file into that.
 * Repeat until your face is completely destroyed


Even if you know very little digital image work and uninterested in coding you can quickly manipulate and re-manipulate images easily without using more traditional image processing tools like Adobe Photoshop or the open source free alternative [GIMP](https://www.gimp.org/)

### Gestures are data

After we've messed about with these webapps, Return to [Distorting Grid](http://snorpey.github.io/distort-grid) and notice that in the top right of the browser window is a faint `download transform data` button. The transformations you make warping the grid etc. are recorded on clicking this, and then exported as a form of data called `json`. 

#### JSON

This is just an array or list of data with paired *names* and *values* that can be a string of text, numbers or a Boolean (that means either a `true` or `false` statement) that humans and machines can read. An example is below.

```
 var myJson = [
 {
    "first": "John",
    "last": "Doe",
    "age": 39,
    "sex": "male",
    "salary": 70000,
    "registered": true
    },
 {
    "first": "Jane",
    "last": "Smith",
    "age": 42,
    "sex": "female",
    "salary": 80000,
    "registered": true
    },
    ];
```

If you open up the downloaded file with **Notepad** you'll see something a bit more abstract that describes the positions of the grid you transformed. The most basic way of representing position is using variables `x` and `y` which you'll remember is a convention for describing `horizontal` and `vertical` positions on a graph. We could call them `time` or `chocolate eaten` but we only want our position data so it makes sense to use names like `x`.

We are not going to do anything with it but it shows simply how our interactions manipulating an image with Snorpey's little apps can be described as data.

# 2

### 3D object making in the browser

![Skill Covered](https://img.shields.io/badge/skill-JavaScript-blue.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-DataMaking-magenta.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-3DDesign-lightgrey.svg?longCache=true&style=plastic)

[OpenSCAD](http://www.openscad.org/) is a tool for making 3D and 2D shapes with data and code. Like many things, there's now a version that runs in a webpage. So we are going to use OpenJSCAD (javascript implementation of OpenSCAD) in the browser, which presents a fairly sophisticated interface for generating 3D shapes

 * Open [OpenJSCAD.org](https://openjscad.org/) and select ALL of the code in the right panel of the web page and replace with this:

```
    function main(){
           return cube({size: 10, center: true})
              .translate([-20, -10, 12]);
                  }
```

 * Press SHIFT & RETURN (enter) and it will render the new code. Change some numbers, see what happens
 * You can export `.stl` files for 3d printing right from the browser like our [example above](https://github.com/cheapjack/DigitalMigrations/blob/master/models/cube.stl) and [this](https://github.com/cheapjack/DigitalMigrations/blob/master/models/Migrations.stl)
 * You can take screen grabs, clean up and drop into the snorpey glitching sites.
 * You can also export 2D shapes with OpenSCAD as `.svg` files for laser cutting of CNC milling or further image play or processing.

### DIY dataset

![Skill Covered](https://img.shields.io/badge/skill-DataMaking-magenta.svg?longCache=true&style=plastic)

We're going to go back to 2 dimensions for a moment and generate more data, not just with our mouse but with our day to day routine. Data does not have to be big. I'm making my own based on times I drink coffee in a 4 hour period in the office.

Im going to plot the times I do that on a graph.

![graph](https://user-images.githubusercontent.com/128456/44107570-b9cee20c-9fef-11e8-9cdf-35f359650686.png)

Then Im going to turn it into a list of graph plots

`[0, 0], [1, 1], [2, 1], [3, 0], [4, 1], [4, 0]`

In most programming languages this data can be made into a list like this and can be stored in a type of variable called an array. Javascript handles all kinds of variable types, you just have to 'declare' what you want to call it and format it like this.

`var c = [[0, 0], [1, 1], [2, 1], [3, 0], [4, 1], [4, 0]];`

We're going to use this as a data source to draw a shape in the OpenJSCAD browser by copying [this bit of code](https://github.com/cheapjack/DigitalMigrations/blob/master/openjscad/coffeeGraph.jscad) and pasting into the code panel and using SHIFT & RETURN to render it.

You'll notice that line 15 of that code are my graph plots. You could make your own graph and call the axes whatever you want and represent anything you want.

#### Drawing is mapping to

The exercise above maps data spatially into a shape you can 3D print, but of course we could do this with drawing just as well. We've prepared some tracing paper with some [Graph paper](http://www.printfreegraphpaper.com/) printed on it and we'd like you to trace a single line over something and then draw `x` and `y` axes around them and plot this in a regular fashion. Use the grid to help and generate a list of numbers which are the **spatial coordinates** of the line you have drawn.

Then type this list to replace the `var c` list on line 15 and see what happens..


### Why Data

Usually all the data stuff when we make digital images or video happens behind the scenes so you never think about it and for good reason; if you want to manipulate images in creative ways you often just want instant results. Then you can get on with the important stuff of making work.

Computer scientists have abstracted all the data stuff away so you can use it as a tool which is all good. However, thinking on a simple level of how a digital image is made up of individual 'pixels' with numbers assigned to it has it's advantages. When images are turned into a list of numbers; into data with a very specific schema or format, they can be 'translated' and manipulated in powerful ways. Just thinking of an image like this gives you access to a literacy in what your tools are actually doing which could lead to you making your own tools or using your existing ones in new ways. And literacy can lead to the intuition and development we often need in our art practices. 

In many ways a digital image is not an image at all but more like an abstract 'spatial' map of related coordinates and numbers in a colour space that use a format or schema that other people and machines know about so they can be shared on phones, projectors, monitors, or inkjet printers.

So our image data 'maps', can be read into other formats just as someone drawing will map visual experience to marks on paper; images can be turned into sound, manipulated as if they were so and translated back into images. 

You can also make up data that's not referring to sound or colour but perhaps record experiences or find data online.

This is a series of exercises to show that doing that is not that difficult.

### Further Tools & Research

#### 3D design tools toward 3D printing and fabrication
 * [OpenSCAD](http://www.openscad.org/)
 * Or for a more simple design environment setup a free account for [TinkerCAD](https://www.tinkercad.com/)

#### Topography Data

Want to print out `.stl` files from the topography on Google Maps? Have a look at [Terrain2STL](http://jthatch.com/Terrain2STL/) and try importing to tinkerCAD or OPENSCAD. Then mash up/combine with some anonomised personal data geometry you made previously. You can't import with the vanilla OpenJSCAD but you can do if you build your own from [OpenJSCAD on github](https://github.com/jscad/OpenJSCAD.org). I'd recommend merging it in TinkerCAD or a standalone OpenSCAD application. 

I've made a model of the topography around [LICA here for you to look at](https://github.com/cheapjack/DigitalMigrations/blob/master/models/Bailrigg.stl) 

### Interaction and Coding for Artists

Want to find out more about learning this kind of practice it's well worth starting out with [Processing](http://processing.org). Initially check out Dan Shiffman's (Processing inventor) [Highly Enthusiastic video](http://hello.p5js.org/). 

Then browse the work of a huge community of artists and creatives on the [Open Processing](https://www.openprocessing.org/) site which lets you get coding straight away in the browser without downloading anything. You can then move onto downloading to your own computer. 

Then if you want to make physical sensors to generate data it's worth checking out artist [Laura Pullig](https://tactile-electronics.tumblr.com/) workshop tutorial called [What Does Health Look Like](https://github.com/DoESLiverpool/what-does-health-look-like) using Processing and the [BBC Microbit](https://microbit.org/) a £15 computer system for learning Physical computing. 

## Artists who use Data

Example established artistic practices that use data

### Glitchers

<img src="http://farm4.static.flickr.com/3292/3053414349_23240d6190_o.gif" width="200">
Rosa Menkman "vernacular of file formats" 

Nick Briz "glitch codec tutorial" [video](https://www.youtube.com/watch?v=hOemlx2sBIo)

Takeshi Murata ["pink dot"](https://www.youtube.com/watch?v=eZkY6zFbwgQ)

Phillip Sterns ["glitch textiles"](https://www.glitchtextiles.com/)

#### Data Textiles and Painting

<img src="http://danhays.org/images/colorado%20snow%203.jpg" width="300">

[Dan Hays](http://danhays.org/coloradosnow3.html) work hand takes the abstracted cartesian 'image maps' back to their material artefacts through hand painting pixels. Ironic that programmers spend years on the data architecture of images for convenience only for the image makers to un-convenience it almost in protest.

<img src="http://smeech.co.uk/wp-content/uploads/2016/07/Waterside-Horse-01-Export-500.gif" width="300">

[Sam Meech](http://smeech.co.uk) makes very interesting takes on very simple digital images and translates them with knitting machines, video, performance and interaction

#### Data Art & Activism

[James Bridle](http://jamesbridle.com/works) is a journalist and artist uncovering the infrastructure of our now ubiquitous data culture.

[Forensic Architecture](https://www.forensic-architecture.org/) famously won the 2018 Turner Prize and challenge what artists (or architects) are meant to do at all

[Julian Oliver](https://julianoliver.com/output/) started out doing high end yet philosophically straightforward media-interaction work like [Fijuu](https://www.fact.co.uk/projects/dingdong/julian-oliver-pix-fijuu) which I curated back in 2008, to developing the [Critical Engineering Manifesto](https://criticalengineering.org/) and [making work and projects](https://julianoliver.com/output/) on the edge of speculative design and tools for network activism.

[Lucy Kimbell](http://www.lucykimbell.com/LucyKimbell/Projects.html) Artist and researcher, writer and strategic design in social innovation. Considering and participating in wider data cultures can help sustain an artistic practice

Directory of data artists [Big Bang Data Project at Somerset House](http://bigbangdata.somersethouse.org.uk/artists/)

[Ellie Harrison](https://www.ellieharrison.com/), a self confessed recovering data addict who has been recording how much she swims every day for years until she swims the atlantic. Also famously connected a vending machine to austerity data, campaigns to [Bring Back British Rail](https://www.bringbackbritishrail.org/) and got roasted by the Daily Record for an Arts Council Funded Project for her to only work within the Greater Glasgow Strathclyde region to reduce her carbon footprint. 

[Sam Thulin](http://www.lancaster.ac.uk/cemore/author/sthulin/) does a [Data Sensor Drone-By](http://www.lancaster.ac.uk/cemore/drone-over-data-centre/)

# Mo' `webgl` Mo' Problems 

Since writing this I've noticed that with the recent auto updates of Chrome google have messed up `webgl` and have so far failed to do much about it.

A fix that worked for me was to enable webgl related flags by typing in these addresses into the address bar: `chrome://flags/#ignore-gpu-blacklist` and `chrome://flags/#enable-webgl-draft-extensions` 

Then goto `chrome://settings/` show *Advanced Settings* and under *System* enable the switch *Use hardware acceleration when available* so it's on.

Failing that use Firefox. It's nicer anyway.
