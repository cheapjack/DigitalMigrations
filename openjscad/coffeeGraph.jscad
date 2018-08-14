// title      : Rectangular Extrude from graph coordinates
//              of how many times I drank coffee over 4 hours
// author     : Ross Dalziel
// license    : WTFPL License
// description: testing rectangular_extrude() function
//              by calling another function which returns
//              an array of coordinates
// file       : coffeeGraph.jscad

// define an array to draw a polygon
// a list of coordinates, say from a hand drawn
// graph of number of time you have coffee
function getShapeCoords() {
    // define an area called c
    var c = [[0, 0], [1, 1], [2, 1], [3, 0], [4, 1], [4, 0]];
    // make it spit out the contents of c when you
    // call the function
    return c;
}

// define a scalar, how much to scale the shape
var scalar = 8;
// define the main function that returns the 3D shape
function main () {
      // square brackets after return means you can return a 
      // list or array of shapes
      return [
          // getShapeCoords() just gets all the
          // coordinates of your graph points and returns
          // the shape by extruding within the bounds
          // of the graph
          rectangular_extrude(getShapeCoords(), {closed: true}).scale([scalar,scalar,scalar])
          ];
}
