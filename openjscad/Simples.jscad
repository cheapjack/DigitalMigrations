// title      : OpenJSCAD.org Intro
// author     : R Dalziel
// license    : WTFPL
// revision   : 0.001
// tags       : Sphere,Cube
// file       : Simples.jscad

// Always start with the main function that encloses your code in 
// curly brackets
function main(){
    // you always return something
    // so everything after return is what the code 'builds' when you 
    // use SHIFT & RETURN to run your code
    // If you use double forward slash then the code is ignored
    // and treated like a comment. So you can 'comment out' commands you
    // dont want.
    // Try 'uncommenting the return cube() statement (remove the slashes)
    // and 'comment out' the returen sphere() (add the slashes)
    //return cube({size: 10, center: true})
    return sphere({r: 12, center: true})
    .translate([-20, -10, 12]);
    // Dont forget to end your statements with ; or you get an error.
}

    
