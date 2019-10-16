/////////////////////////////////////////////////////////////////////////////////////////
// Simplified Data Visualisation Tutorial from                                          /
// https://vda-lab.github.io/2015/10/hands-on-data-visualization-using-p5               /
// made by Jan Aerts, Professor of BioInformatics from the Visual Data Analysis group   /
// at UHasselt University in Belgium (formerly at KU Leuven)                            /
//                                                                                      /
/////////////////////////////////////////////////////////////////////////////////////////

var table;

function preload() {
  table = loadTable("flights.csv","csv","header")
  // When using this on the internet you can't load in files locally
  // for security reasons, so we are using the version stored on the
  // openprocessing site 
  //table = loadTable("https://openprocessing-usercontent.s3.amazonaws.com/files/user139972/visual767728/hdb4c399dfc7d9fbe5651da848669c4ed/flights.csv","csv","header")
}

function setup() {
	display_width = 600
	display_height = 300
  createCanvas(display_width,display_height)
  noStroke()
  fill(0,0,255,10)
  background(255,255,255)
  var rows = table.getRows()
  for (var r = 0; r < rows.length; r++) {
    var from_long = rows[r].getNum("from_long")
    var from_lat = rows[r].getNum("from_lat")
    var x = map(from_long,-180,180,0,width)
    var y = map(from_lat,-90,90,height,0)
    ellipse(x,y,3,3)
  }
	let s="Density of Global Domestic Flights visualisation"
	textSize(12)
	fill(50)
	text(s, 5, (display_height-20), 400, 200)
}
