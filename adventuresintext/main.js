// This is our main.js script file. it refers to various elements in our index.html file, which contains 
// lets grab a reference to our img tags in our index.html document
// and call it var myImage 
var myImage = document.querySelector('img');
// now we define what happens when we click the tag
// This really should be done with event listener
myImage.onclick = function() {
    // This is our array of image locations in this case they are inside
    // the images/ directory called 'something.png' inside the current directory where this file you are editing is.
    // We can make this list as long as we like, as long as we have files there. So if you saved a tonne of warped images here you can add them all to a list. Naming them numerically just makes it easier to list, they can be called anything so long as the file path is correct, ie not actually saved somewhere else.
    var myImageArray = ['images/1.png','images/2.png','images/3.png'];
    // get a random index number from 0 to the number of items in the array
    var imageIndex = getRandomInt(myImageArray.length);
    //set myImage to the 'src' which is the file name, chosen
    //randomly from the position in the array list
    myImage.setAttribute('src', myImageArray[imageIndex]);
    }

// define how we get a random index number from the number of items in the myImageArray array
function getRandomInt(max) {
      return Math.floor(Math.random() * Math.floor(max));
}

// Define customName from our index.html by it's id 'customname' This is going to replace a placeholder 'Bob'
var customName = document.getElementById('customname');
// Define the other elements in our index.html by it's class name '.classnam'
var randomize = document.querySelector('.randomize');
var story = document.querySelector('.story');

// A function to return a random choice from our arrays of strings
function randomValueFromArray(array){
  var random = Math.floor(Math.random()*array.length);
  return array[random];
}

// use the :replace: tags to replace the :text: with something else
var storyText = 'Listen Bob, let me tell you a story. :insertx: followed by :inserty: A few moments pass, :insertz:';
var insertX = ["Once upon a time, ", "I'm not interested in seeing a film just made by a woman - not unless she is looking for new images."];
var insertY = ['randomness'];
var insertZ = ['Drake and his Crewe'];

// add to the insertX array when the button with class '.moretext' is pressed
// and the user is prompted to 'Give me some text!?'
function setNewItemX() {
    var myContent = prompt('Give me some text!?');
    var newX = insertX.push(myContent);
}

var myButton = document.querySelector('.moretext');
myButton.onclick = function() {
         setNewItemX();
}
// Another way to access a button is to use  .addEventListener on the button with class 'randomize' 
randomize.addEventListener('click', result);
//when the EventListener senses the click on the .randomize button it runs the result funtion below
function result() {
    // set newStory to the main story text with replaceable tags
  var newStory = storyText;
  // get random items in each item array
  var xItem = randomValueFromArray(insertX);
  var yItem = randomValueFromArray(insertY);
  var zItem = randomValueFromArray(insertZ);
  // replace the default items tagged :insertx: :with the random items
  newStory = newStory.replace(':insertx:',xItem);
  newStory = newStory.replace(':inserty:',yItem);
  newStory = newStory.replace(':insertz:',zItem);
  // Finally check for a customname and replace it otherwise use Bob 
  if(customName.value !== '') {
    var name = customName.value;
    newStory = newStory.replace('Bob',name);
  }

  story.textContent = newStory;
  story.style.visibility = 'visible';
}
