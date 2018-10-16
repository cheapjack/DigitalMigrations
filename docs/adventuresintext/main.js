// This is our main.js script file. it refers to various elements in our index.html file, which contains 
// lets grab a reference to all the img tags in our index.html document
// and call it var myImage 
var myImage = document.querySelector('img');

// now we define what happens when we click the tag
// This really should be done with event listener

myImage.onclick = function() {
    var myImageArray = ['images/1.png','images/2.png','images/3.png'];
    var imageIndex = getRandomInt(myImageArray.length);
    //var mySrc = myImage.getAttribute('src');
    myImage.setAttribute('src', myImageArray[imageIndex]);
    }

// define how we get a random integer from the number of items in the myImageArray array
function getRandomInt(max) {
      return Math.floor(Math.random() * Math.floor(max));
}

// Grab the elements from our index.html
var customName = document.getElementById('customname');
var randomize = document.querySelector('.randomize');
var story = document.querySelector('.story');
var newContent = document.querySelector('newItemX');

// A function to return a random choice from our arrays of strings
function randomValueFromArray(array){
  var random = Math.floor(Math.random()*array.length);
  return array[random];
}
// use the :replace: tags to replace the :text: with something else
var storyText = 'Listen Bob, let me tell you a story. :insertx: followed by :inserty: A few moments pass, :insertz:';
var insertX = ["Once upon a time, ", "I'm not interested in seeing a film just made by a woman - not unless she is looking for new images."];
var insertY = ['randomness'];
var insertZ = ['Drake and his crew'];

// add to theses arrays
function setNewItemX() {
    var myContent = prompt('Give me some text!?');
    var newX = insertX.push(myContent);
}

var myButton = document.querySelector('button');

myButton.onclick = function() {
         setNewItemX();
          }

randomize.addEventListener('click', result);

function result() {
    // set newStory to the main story text with replaceable tags
  var newStory = storyText;

  var xItem = randomValueFromArray(insertX);
  var yItem = randomValueFromArray(insertY);
  var zItem = randomValueFromArray(insertZ);
  newStory = newStory.replace(':insertx:',xItem);
  newStory = newStory.replace(':insertx:',xItem);
  newStory = newStory.replace(':inserty:',yItem);
  newStory = newStory.replace(':insertz:',zItem);
// Check for a customname and replace it otherwise use 
  if(customName.value !== '') {
    var name = customName.value;
    newStory = newStory.replace('Bob',name);
  }

  story.textContent = newStory;
  story.style.visibility = 'visible';
}
