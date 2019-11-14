# Digital Migrations

## Year 2 Class 4

# 6

## Data Tables

![Skill Covered](https://img.shields.io/badge/skill-Processing-magenta.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-lat-long-pink.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-Data-Wrangling-brightgreen.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-CSV-magenta.svg?longCache=true&style=plastic)


Quick Recap on variables and drawing. Login in (or sign up if you havent already) to [openprocessing](https://www.openprocessing.org) and go to my [recap on variables](https://www.openprocessing.org/sketch/792463) sketch, fork it and see what we can change.

We previously looked at `.json` files in [our first data workshop](https://cheapjack.github.io/DigitalMigrations/Year2_Class1.html#gestures-are-data) and had a go at [making our own](). The humbel table or spreadsheet is one of the most simple and oldest forms of organising data.

Computers can easily deal with tables translated into `.csv` files which stand for **C** ommma **S** eperated **V** alues. All spreadsheet software can export their data in this format and you'll find it in my [Data sources](#data-sources) section below.

### Bar Charts

We are going to use some disturbing [real data](https://data.humdata.org/dataset/yemen-cholera-outbreak-daily-epidemiology-update/resource/06f74fb8-9194-476d-8d35-343f951c90f6?view_id=9e32d6b7-b4da-4fba-8299-e01fb26a93e9) of reported Cholera deaths in Syria to draw some graphs. Login in (or sign up if you havent already) to [openprocessing](https://www.openprocessing.org) and go to my [Tutorial](https://www.openprocessing.org/sketch/790798) sketch, fork it and see what we can change.

We can then experiment looking for other data sets from our list of [data sources](#data-sources) or [make your own](#csv-diy)

### Maps and CSV

Using `.csv` files with latitude and longitude data in them can be really effective. Login in (or sign up if you havent already) to [openprocessing](https://www.openprocessing.org) and go to my [Tutorial](https://www.openprocessing.org/sketch/790439)

This uses the `flights.csv` file to map out flight density. But you'll notice you can also change to another much smaller dataset showing locations of air quality sensors.

See if you can find more data sets or [make your own](#csv-diy)


# 8

### Back to Interactivity

![Skill Covered](https://img.shields.io/badge/skill-Processing-magenta.svg?longCache=true&style=plastic)
![Skill Covered](https://img.shields.io/badge/skill-Interactivity-brightgreen.svg?longCache=true&style=plastic)

<img src="https://imgs.xkcd.com/comics/machine_learning_captcha.png" sidth ="300">

Have a look at [this sketch based on the iconic Joy Division Album cover](https://www.openprocessing.org/sketch/792422) that looks like data, in fact it's generating the data which is then drawn which really show the connection between data and interaction.

Just as a recap, we can work our way through [the p5 Interactivity Page](https://p5js.org/learn/interactivity.html)

If there's time we'll visit a bit more advanced stuff with Matt DesLauriers below.

## Further Explorations

### Throw More Data Shapes

### Plotting

[Allison Parrish](http://www.decontextualize.com/)'s continues with some more sophisticated methods of plotting from files like this.
[CSV files in p5](https://creative-coding.decontextualize.com/csv-files/)

### More Interaction with Glitch

[Matt DesLauriers AKA @mattdesl](https://twitter.com/mattdesl) made some really nice tutorials for some [@shapeofdata](https://twitter.com/shapeofdata) workshops. It uses the [Glitch](https://glitch.com/) platform and is really good for seeing what we've learnt entangled with contemporary javascript.

🗒️  [Course Notes](https://github.com/mattdesl/workshop-p5-intro)

🎨  [p5.js Demos](https://p5-demos.glitch.me)

🔊  [Tone.js Demos](https://tone-demos.glitch.me)

### Computational Media

[Allison Parrish](http://www.decontextualize.com/)'s work on the NYU ITP [Foundation course in Computational Media](https://github.com/ITPNYU/ICM-2017), where Daniel Schiffman (founder of Processing) works

Also Allison runs an excellent introductory syllabus to [Creative Coding](https://creative-coding.decontextualize.com/) in javascript & p5.js the [Computational approaches to Narrative](http://catn.decontextualize.com/) syllabus

### The Nature Of Code

You can learn some really advanced stuff by following the course materials from the [Nature of Code}(https://natureofcode.com/book/)

It's made for using with the Processing application but [there are p5.js implementations here](https://github.com/nature-of-code/noc-examples-p5.js)

It's well worth working your way through if you really want to take this further as it helps you get to grips with working with object orientated programming in depth and adding simulations of natural like physics using forces and gravitation.

### Bots Should Punch Up

Taking data out onto social media is another interesting form of activism worth looking into. When you make your sketches it would be interesting to send them out as posts and generate responses or even a whole new audience.

You'll notice that with an election looming in Dec 2019 and various contested regime change conflicts around the world the amount of bot activity is pretty intense. Got some data that might help deliberate over geopolitical power? Favourite poetry dumped into a `.csv` file?  Use it to power a twitter bot!

Start with  Leonard Richardson’s [Bots should punch up.](https://www.crummy.com/2013/11/27/0) and then browse all the content of [BotWiki](https://botwiki.org/)


# Data Sources

Name|Link|Notes
---|---|---
UK Data Service|[UK Data Service](https://www.ukdataservice.ac.uk/get-data/key-data)|UK's largest collection of social, economic and population data for research and teaching purposes covering a range of different disciplines.
Planet Parts|[Planet Parts](https://planet.parts/)|All kinds of environmental data
`data.gov.uk`|[data.gov.uk](https://data.gov.uk/)|Official big and small UK Government data
DroneWars|[UK Drone Strikes against 'ISIS'](https://dronewars.net/2019/11/05/uk-drones-more-likely-to-target-individuals-than-infrastructure-data-analysis-reveals/)|Tracking drone strikes for journalism
Armed Conflict Location & Event Data Project (ACLED)|[ACLED](https://www.acleddata.com/dashboard/)|disaggregated data collection, analysis, and crisis mapping project

### CSV DIY

Caveat of finding CSV files is that you can still 'quote' data presented online and make your own table `.csv` files, which you can make with spreadsheet software and exporting or just text using a text editing program like Notepad. Just remember to follow the format below and save as `.csv`:

```
Column_Name_1,Column_Name_2,Column_Name_3,Column_Name_4
String_or_value_1,String_or_value_1,String_or_value_1,String_or_value_1
String_or_value_2,String_or_value_2,String_or_value_2,String_or_value_2
String_or_value_3,String_or_value_3,String_or_value_3,String_or_value_3
```



Also good practice to include a link to the data set you are quoting.

Name|Link|Notes
---|---|---
Air quality monitoring York|[Air-quality-monitoring-stations York](https://data.gov.uk/dataset/c6ea7dab-5b1e-428f-aba8-ec409ae9296f/local-air-quality-monitoring-stations)|Air quality data is an all too common data set, popular as it indicates environmental change and awareness in urban settings. This one has lat long data so you can plot it map-like and Ive used it as an alternative to the fight density sketch.
Yemen Cholera Epidemiology Data|[Yemen Cholera Epidemiology](https://data.humdata.org/dataset/yemen-cholera-outbreak-daily-epidemiology-update/resource/06f74fb8-9194-476d-8d35-343f951c90f6?view_id=9e32d6b7-b4da-4fba-8299-e01fb26a93e9)|Humanitarian data where cholera can indicate extreme infrastructure collapse as a consequence of conflict. Not a good way to die. This data is almost too horrible to be true.

## Twine

Kristen and Hugh both liked [Twine](http://twinery.org/) as a possible way of interlinking processing pages and datasets and seemed useful for 2 of their recent projects.

You can use it [online](http://twinery.org/2/)

Find documentation on the [Twine wiki](http://twinery.org/wiki/)
Full instructions on [Harlowe](https://twine2.neocities.org/) the default theme.

I made a [cheatsheet to get started](https://github.com/cheapjack/ForkingLibraries/blob/master/workshop/cheatsheet.md) from my general guide [Twine for Librarians](https://github.com/cheapjack/ForkingLibraries)

Once you've made something in twine, included links to cool data and openprocessing sketches you can publish your data easily using glitch

`<a href="my_processing_sketch_address">the displayed link</a`

You can even embed audio in Twine games like I did in this story made around [Bertrand Russell positivist monologues](https://domesticscience.org.uk/games/abcOfRelativity/abcOfRelativity.html).

## Publishing with Glitch

Sign up and use [Glitch](https://glitch.com/) to host and edit all your p5 codes, `.csv` files, Twine html etc.

Start a project, preview it and then view it as an html app.

Don't forget to display a twine file at your glitch project address **first**, choose `publish to web` and place the file in a fresh `hello-webpage` glitch project and rename it to `index.html`. Otherwise you can just make your own index page with links to twine, other glitch projects, datasets or openprocessing pages.

Checkout the [p5.js documentation on displaying your processing sketch in an html page]()
