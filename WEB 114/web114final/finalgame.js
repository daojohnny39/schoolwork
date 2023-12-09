

/*

    Johnny (Nhat) Dao
    12/9/2023
    WEB 114 Final Project

    NOTE: Sorry, I kinda got sluggish with the notes about 3/4ths of the way through

    BUG FIXES:
        (1): User was able to spam click the pElement and buttonElement generation
                (User is still able to spam click the opposite choice)

*/

"use strict";

/* ---------------------- GAME ELEMENTS ---------------------- */
// Introduction
const gameElement = document.querySelector('.game');
const gameIntroElement = document.querySelector('.game-introduction');
var username;

// First Game
const gameFirstElement = document.querySelector('.game-first');

// Second Game
const gameSecondElement = document.querySelector('.game-second');
var secondGameUserChoice = 0;
var spamClickPrevent = 0;

// Third Game
const gameThirdElement = document.querySelector('.game-third');
var thirdGameUserChoice;

// Fourth Game
const gameFourthElement = document.querySelector('.game-fourth');
const fourthGameAnswerStatus = document.querySelector('.fourth-game-answer-status');
var fourthGameUserInput = null;
var fourthGameUserTries = 0;

// Fifth Game
const gameFifthElement = document.querySelector('.game-fifth');
const fifthGameAnswerStatusQ2 = document.querySelector('.fifth-game-answer-status-q2');
const fifthGameAnswerStatusQ3 = document.querySelector('.fifth-game-answer-status-q3');
var fifthGameUserInputQ2 = 0;
var fifthGameUserInputQ3 = 0;

var firstQuestionStatus = false;
var secondQuestionStatus = false;
var thirdQuestionStatus = false;

// Game Finished
const gameFinishedElement = document.querySelector('.game-finished');
const gameFinishedAnswers = document.querySelector('.game-finished-answers');
var reviewList = [];


// Bug Fixes (1)
var firstGameChoiceMade = false;
var firstGameUserChoice = null;
/* ---------------------- GAME ELEMENTS END ---------------------- */

/* ---------------------- GAME FUNCTIONS ---------------------- */
// First game ----------
function updateGameFirstExt(choice) {
    var gameFirstExtElement = document.querySelector('.game-first-ext');
    let pElement = document.createElement('p');
    let buttonElement = document.createElement('button');
    buttonElement.classList.add('second-game')

    // Checks if a choice was already made
    if (firstGameUserChoice && firstGameUserChoice !== choice && firstGameChoiceMade) {
        pElement.textContent = "Ah! Switching choices... really confidence inspiring...";
        gameFirstElement.appendChild(pElement);
        return;
    }
    
    // Bug Fixes (1)
    if (firstGameChoiceMade) {
        return;
    }

    firstGameUserChoice = choice;
    firstGameChoiceMade = true;

    console.log("--------- First Game Logs ---------");
    console.log("firstGameUserChoice: " + firstGameUserChoice);
    console.log("choice: " + choice);
    console.log("firstGameChoiceMade" + firstGameChoiceMade);

    if (choice === 'first') {
        pElement.textContent = "You think you're confident enough to select the first choice??? (You still have a chance to change it!)";
        buttonElement.textContent = "Let's handle the next one then";
    }
    else if (choice === 'second') {
        pElement.textContent = "Not confident enough to pick the first choice huh... (You still have a chance to change it!)";
        buttonElement.textContent = "Moving on...";
    }

    gameFirstElement.appendChild(pElement);
    gameFirstElement.appendChild(buttonElement);
}
// First game END ----------

// Fifth Game ----------
function checkGameStatus() {
    if (firstQuestionStatus && secondQuestionStatus && thirdQuestionStatus) {
        let buttonElement = document.createElement('button');
        buttonElement.classList.add('fifth-game-finish');
        buttonElement.textContent = "LET'S GOOO WE'RE DONE!!!";
        gameFifthElement.appendChild(buttonElement);
    }
}
// Fifth Game END ----------
/* ---------------------- GAME FUNCTIONS END ---------------------- */

/* ---------------------- GETTING USERNAME ---------------------- */
document.getElementById('username-form').addEventListener('submit', function(event) {
    // Prevents page from reloading when user hits submit button
    event.preventDefault();

    username = document.getElementById('username-input').value;
    var userGreetElement = document.getElementById('user-greeting');
    userGreetElement.textContent = 'Welcome, ' + username + '!';

    console.log("Username: " + username);

    //var introGame = document.querySelector('.game').style.display = 'block';
    gameElement.style.display = 'block';
    gameIntroElement.style.display = 'block';
}); 
/* ---------------------- GETTING USERNAME END ---------------------- */

/* ---------------------- FIRST GAME ---------------------- */
// Starting game
document.getElementById('start-game').addEventListener('click', function() {
    gameIntroElement.style.display = 'none';
    gameFirstElement.style.display = 'block';
})

document.getElementById('first-choice').addEventListener('click', function() {
    updateGameFirstExt('first');
})

document.getElementById('second-choice').addEventListener('click', function() {
    updateGameFirstExt('second');
})
/* ---------------------- FIRST GAME END ---------------------- */

/* ---------------------- SECOND GAME ---------------------- */
// After the first game, the "next game" buttons don't work because it hadn't been generated yet at
// the time DOM is rendered
document.body.addEventListener('click', function(event) {
    if (event.target && event.target.classList.contains('second-game')) {
        console.log('');    // console divider
        console.log("--------- Second Game Logs ---------");

        // Div swap
        gameFirstElement.style.display = 'none';
        gameSecondElement.style.display = 'block';

        console.log("First game div replaced successful");
    }
});

// First Image Selection
document.getElementById('first-interior-image').addEventListener('click', function() {
    console.log('first image was clicked!');

    if (spamClickPrevent !== 0) {
        return;
    }
    else if (secondGameUserChoice > 0) {
        console.log('CHOICE SWITCHING CAUGHT');

        let catchElement = document.createElement('p');
        catchElement.textContent = "Trying to switch choices again... I thought we went over this";
        gameSecondElement.appendChild(catchElement);

        spamClickPrevent = 1;
        console.log("Spam click Prevention: " + spamClickPrevent);

        return;
    }

    secondGameUserChoice = 1;
    console.log("secondGameUserChoice: " + secondGameUserChoice);

    let pElement = document.createElement('p');
    pElement.textContent = "So you're a normal person...";
    gameSecondElement.appendChild(pElement);

    let buttonElement = document.createElement('button');
    buttonElement.textContent = "Don\'t question me. Let\'s move on";
    buttonElement.classList.add('third-game');
    gameSecondElement.appendChild(buttonElement);
})

// Second Image Selection
document.getElementById('second-interior-image').addEventListener('click', function() {
    console.log('second image was clicked!');

    if (spamClickPrevent !== 0) {
        return;
    }
    else if (secondGameUserChoice > 0) {
        console.log('CHOICE SWITCHING CAUGHT');

        let catchElement = document.createElement('p');
        catchElement.textContent = "Trying to switch choices again... I thought we went over this";
        gameSecondElement.appendChild(catchElement);

        spamClickPrevent = 1;
        console.log("Spam click Prevention: " + spamClickPrevent);

        return;
    }

    secondGameUserChoice = 2;
    console.log("secondGameUserChoice: " + secondGameUserChoice);

    let pElement = document.createElement('p');
    pElement.textContent = "That interior is really white and shiny. Seems like you're super confident...";
    gameSecondElement.appendChild(pElement);

    let buttonElement = document.createElement('button');
    buttonElement.textContent = "Yeah I am. So what?";
    buttonElement.classList.add('third-game');
    gameSecondElement.appendChild(buttonElement);
})

// Third Image Selection
document.getElementById('third-interior-image').addEventListener('click', function() {
    console.log('third image was clicked');

    if (spamClickPrevent !== 0) {
        return;
    }
    else if (secondGameUserChoice > 0) {
        console.log('CHOICE SWITCHING CAUGHT');

        let catchElement = document.createElement('p');
        catchElement.textContent = "Trying to switch choices again... I thought we went over this";
        gameSecondElement.appendChild(catchElement);

        spamClickPrevent = 1;
        console.log("Spam click Prevention: " + spamClickPrevent);

        return;
    }

    secondGameUserChoice = 3;
    console.log("secondGameUserChoice: " + secondGameUserChoice);

    let pElement = document.createElement('p');
    pElement.textContent = "I see that you've chosen the dark interior. You got something to hide??";
    gameSecondElement.appendChild(pElement);

    let buttonElement = document.createElement('button');
    buttonElement.textContent = "Just doing my thing, don't mind me.";
    buttonElement.classList.add('third-game');
    gameSecondElement.appendChild(buttonElement);
})
/* ---------------------- SECOND GAME END ---------------------- */

/* ---------------------- THIRD GAME ---------------------- */
document.body.addEventListener('click', function(event) {
    if (event.target && event.target.classList.contains('third-game')) {
        console.log('');    // console divider
        console.log("--------- Third Game Logs ---------");

        // Div swap
        gameSecondElement.style.display = 'none';
        gameThirdElement.style.display = 'block';

        console.log("Second game div replaced successful");


        // Third question generation
        const thirdGameDiv = document.querySelector('.from-second-choice');
        let thirdGameQuestion = document.createElement('p');
        thirdGameQuestion.textContent = "You picked image " + secondGameUserChoice + " from the last question."
        thirdGameDiv.appendChild(thirdGameQuestion);

        // Creating image element for third question
        let thirdGameImg = document.createElement('img');

        // Pulling secondGameUserChoice to generate image
        switch(secondGameUserChoice) {
            case (1):
                thirdGameImg.src = "https://i.pinimg.com/originals/24/be/1d/24be1d174c4fd7b8d47f9ca59ecea08f.jpg";
                break;

            case (2):
                thirdGameImg.src = "https://i.pinimg.com/736x/37/68/be/3768beb6730402ea0201cabef9f78808.jpg";
                break;
            
            case (3):
                thirdGameImg.src = "https://strattondesigngroup.com/wp-content/uploads/2018/09/stratton-design-group-portfolio-modern-dream-home-02.jpg";
                break;
        }

        thirdGameImg.classList.add('third-game-image');
        console.log("thirdGameImg: " + thirdGameImg.className); // not exactly document.getElementById("something4").className, but uses .className
        thirdGameDiv.appendChild(thirdGameImg);

        // Third Game Question
        let pElement = document.createElement('p');
        pElement.textContent = "What about this interior did you like?";

        // Select Options:
        let selectDiv = document.createElement('select');
        selectDiv.style.display = "flex";
        selectDiv.style.margin = "20px auto";

        let defaultOptionElement = document.createElement('option');
        defaultOptionElement.textContent = "Select an option";
        defaultOptionElement.id = "third-game-default";
        selectDiv.appendChild(defaultOptionElement);

        let option1Element = document.createElement('option');
        option1Element.textContent = "The Chairs";
        option1Element.id = "third-game-option1";
        selectDiv.appendChild(option1Element);

        let option2Element = document.createElement('option');
        option2Element.textContent = "The Lights";
        option2Element.id = "third-game-option2";
        selectDiv.appendChild(option2Element);

        thirdGameDiv.appendChild(selectDiv);

        // Preventing spam generation
        var thirdGameMessageGeneratedElement = false;

        selectDiv.addEventListener('change', function() {
            // Takes the option elements' id as input
            let selectedOption = this.options[this.selectedIndex].id;

            if (thirdGameMessageGeneratedElement) {
                let catchPElement = document.getElementById('third-game-message');
                catchPElement.textContent = "Come on now...";
                //gameThirdElement.appendChild(catchPElement);
                return;
            }

            let message;

            switch(selectedOption) {
                case 'third-game-option1':
                    message = "You know that chair probably costs more than what you can afford...";
                    thirdGameUserChoice = 1;
                    break;
                case 'third-game-option2':
                    message = "Are the lights really that good??";
                    thirdGameUserChoice = 2;
                    break;
            }

            console.log("thirdGameUserChoice = " + thirdGameUserChoice);

            let pElement = document.createElement('p');
            pElement.id = 'third-game-message';
            pElement.textContent = message;
            gameThirdElement.appendChild(pElement);

            let buttonElement = document.createElement('button');
            buttonElement.textContent = "I don't like this game, take me to the next one!";
            buttonElement.classList.add('third-game-finish');
            gameThirdElement.appendChild(buttonElement);

            thirdGameMessageGeneratedElement = true;
        })
    }
});
/* ---------------------- THIRD GAME END ---------------------- */

/* ---------------------- FOURTH GAME ---------------------- */
document.body.addEventListener('click', function(event) {
    if (event.target && event.target.classList.contains('third-game-finish')) {
        console.log('');
        console.log('-------- Fourth Game Logs --------');

        // Div swap
        gameThirdElement.style.display = 'none';
        gameFourthElement.style.display = 'block';

        console.log("Third game div replaced!");

        /* --------------------------------------------------------- THE CALCULATOR --------------------------------------------------------- */
        // Used querySelectorAll to select all of the buttons (The value of each button is later determined by HTML textContent)
        const buttons = document.querySelectorAll('.calc-buttons button');  

        // Defining the p element within the screen (Used later to replace textContent)
        const screen = document.querySelector('.calc-screen p');

        // Operation variables
        let currentOperation = null;
        let firstOperand = '';
        let secondOperand = '';

        // This allows the screen to actually display the "." 
        function appendToOperand(operand, char) {
            if (char === '.' && operand.includes('.')) {   
                return operand;
            }
            return operand + char;
        }

        // Actually getting the values from each button
        buttons.forEach(button => { 
            button.addEventListener('click', function() {
                const value = this.textContent; 
                if (!isNaN(value) || value === '.') { 
                    if (currentOperation === null) { 
                        firstOperand = appendToOperand(firstOperand, value);
                        screen.textContent = firstOperand;
                    } 
                    else {
                        secondOperand = appendToOperand(secondOperand, value);
                        screen.textContent = secondOperand;
                    }
                } 
                else if (['+', '-', '*', '/', '^'].includes(value)) {
                    currentOperation = value;
                } 
                else if (value === '=') {   
                    let result;
                    switch (currentOperation) { 
                        case '+':
                            result = parseFloat(firstOperand) + parseFloat(secondOperand);  
                            break;                                                          
                        case '-':
                            result = parseFloat(firstOperand) - parseFloat(secondOperand);
                            break;
                        case '*':
                            result = parseFloat(firstOperand) * parseFloat(secondOperand);
                            break;
                        case '/':
                            result = parseFloat(firstOperand) / parseFloat(secondOperand);
                            break;
                        case '^':
                            result = parseFloat(firstOperand) ** parseFloat(secondOperand);
                            break;
                    }
                    screen.textContent = result;    
                    firstOperand = result;
                    secondOperand = '';
                    currentOperation = null;
                }
                // Clear button functionality
                else if (value === 'C') {
                    firstOperand = '';
                    secondOperand = '';
                    currentOperation = null;
                    screen.textContent = '0';
                } 
            });
        });
        /* --------------------------------------------------------- THE CALCULATOR END --------------------------------------------------------- */

        // Answer status
        let pElement = document.createElement('p');
        fourthGameAnswerStatus.appendChild(pElement);

        document.getElementById('answer-form').addEventListener('submit', function (event) {
            event.preventDefault();
            fourthGameUserInput = parseInt(document.getElementById('answer-input').value);
            console.log("fourthGameUserInput = " + fourthGameUserInput);

            let fourthGameAnswer = 31;
            console.log("Answer = " + fourthGameAnswer);

            if (!isNaN(fourthGameUserInput)) {
                if (fourthGameUserInput < fourthGameAnswer - 5) {
                    fourthGameAnswerStatus.style.backgroundColor = 'red';
                    fourthGameAnswerStatus.style.display = 'block';
                    fourthGameUserTries++;

                    pElement.textContent = "Not quite, think HIGHER!!";
                } 
                else if (fourthGameUserInput < fourthGameAnswer) {
                    fourthGameAnswerStatus.style.backgroundColor = 'blue';
                    fourthGameAnswerStatus.style.display = 'block';
                    fourthGameUserTries++;

                    pElement.textContent = "Almost there! Just a little higher!";
                }
                else if (fourthGameUserInput > fourthGameAnswer + 5) {
                    fourthGameAnswerStatus.style.backgroundColor = 'red';
                    fourthGameAnswerStatus.style.display = 'block';
                    fourthGameUserTries++;

                    pElement.textContent = "Not quite, think LOWER!!";
                }
                else if (fourthGameUserInput > fourthGameAnswer) {
                    fourthGameAnswerStatus.style.backgroundColor = 'blue';
                    fourthGameAnswerStatus.style.display = 'block';
                    fourthGameUserTries++;
                    
                    pElement.textContent = "Almost there! Just a little lower!"
                }
                else {
                    fourthGameAnswerStatus.style.backgroundColor = 'green';
                    fourthGameAnswerStatus.style.display = 'block';
                    fourthGameUserTries++;
                    
                    if (fourthGameUserTries >= 3) {
                        pElement.textContent = "CONGRATS! You got it!! It only took you " + fourthGameUserTries + " tries...";
                    }
                    else if (fourthGameUserTries >= 2) {
                        pElement.textContent = "CONGRATS! You got it!! Wow, it only took you " + fourthGameUserTries + " tries, good job!";
                    }
                    else if (fourthGameUserTries == 1) {
                        pElement.textContent = "CONGRATS! You got it!! Wow, it only took you " + fourthGameUserTries + " try, good job! " + username + " is a math genius!";
                    }

                    let fourthGameNextButton = document.createElement('button');
                    fourthGameNextButton.classList.add('fourth-game-finish');
                    fourthGameNextButton.textContent = "Let's move on!";
                    fourthGameAnswerStatus.appendChild(fourthGameNextButton);
                }
            } 
            else {
                fourthGameAnswerStatus.style.backgroundColor = 'red';
                fourthGameAnswerStatus.style.display = 'block';

                pElement.textContent = "Answer must be a number!";
            }
        });
}})
/* ---------------------- FOURTH GAME END ---------------------- */

/* ---------------------- FIFTH GAME ---------------------- */
// Answer status
let pElementQ2 = document.createElement('p');
fifthGameAnswerStatusQ2.appendChild(pElementQ2);

// Answer status
let pElementQ3 = document.createElement('p');
fifthGameAnswerStatusQ3.appendChild(pElementQ3);

document.body.addEventListener('click', function(event) {
    if (event.target && event.target.classList.contains('fourth-game-finish')) {
        console.log('');
        console.log('-------- Fifth Game Logs --------');

        // Div swap
        gameFourthElement.style.display = 'none';
        gameFifthElement.style.display = 'block';

        console.log("Fourth game div replaced!");

        // First question
        document.getElementById('fourth-game-q1-answer').addEventListener('submit', function(event) {
            event.preventDefault();

            var currentVal = parseFloat(document.querySelector('.fourth-game-q1').textContent);
            var firstQuestionInput = parseFloat(document.getElementById('fourth-game-q1-answer-input').value);

            currentVal += firstQuestionInput;

            document.querySelector('.fourth-game-q1').textContent = currentVal;

            firstQuestionStatus = true;
            console.log("First question status: " + firstQuestionStatus);

            checkGameStatus();
        })

        // Second question
        document.getElementById('fourth-game-q2-answer').addEventListener('submit', function(event) {
            event.preventDefault();

            var secondQuestionInput = document.getElementById('fourth-game-q2-answer-input').value;

            if (secondQuestionInput != '5') {
                fifthGameAnswerStatusQ2.style.backgroundColor = 'green';
                fifthGameAnswerStatusQ2.style.display = 'block';
                pElementQ2.textContent = "CONGRATS! You got it!!";
            } else {
                fifthGameAnswerStatusQ2.style.backgroundColor = 'red';
                fifthGameAnswerStatusQ2.style.display = 'block';
                pElementQ2.textContent = "Really?...";
            }

            secondQuestionStatus = true;
            console.log("Second question status: " + secondQuestionStatus);

            checkGameStatus();
        })

        // Third question
        document.getElementById('fourth-game-q3-answer').addEventListener('submit', function(event) {
            event.preventDefault();

            var thirdQuestionInput = document.getElementById('fourth-game-q3-answer-input').value;

            if (thirdQuestionInput <= '5') {
                fifthGameAnswerStatusQ3.style.backgroundColor = 'green';
                fifthGameAnswerStatusQ3.style.display = 'block';
                pElementQ3.textContent = "CONGRATS! You got it!!";
            } else {
                fifthGameAnswerStatusQ3.style.backgroundColor = 'red';
                fifthGameAnswerStatusQ3.style.display = 'block';
                pElementQ3.textContent = "Dude... no way...";
            }

            thirdQuestionStatus = true;
            console.log("Third question status: " + thirdQuestionStatus);

            checkGameStatus();
        })
    }
})
/* ---------------------- FIFTH GAME END ---------------------- */

document.body.addEventListener('click', function(event) {
    if (event.target && event.target.classList.contains('fifth-game-finish')) {
        console.log('');
        console.log('-------- FINISHED --------');

        // Div swap
        gameFifthElement.style.display = 'none';
        gameFinishedElement.style.display = 'block';

        console.log("Fifth game div replaced!");

        alert("You are now finished with the game!");
        
        while (true) {
            var userLikes = prompt("Please list a couple things you liked about the game! (Enter nothing('') once done)");
            if (userLikes === null || userLikes === '') {
                break;
            }
            reviewList.push(userLikes);
        }

        console.log("Users liked:");

        for (var i = reviewList.length; i >= 0; i--) { // for loop backwards
            let pElement = document.createElement('p');
            pElement.textContent = reviewList[i];
            pElement.style.fontWeight = 'bold';
            gameFinishedAnswers.appendChild(pElement);
            console.log(reviewList[i]);
        }

        // RECAP
        let pElement = document.createElement('p');
        pElement.textContent = "For the first question, you answered:";
        gameFinishedElement.appendChild(pElement);

        if (firstGameUserChoice === 'first') {
            let pElement = document.createElement('p');
            pElement.textContent = "The first button! Very confident!";
            pElement.style.fontWeight = 'bold';
            gameFinishedElement.appendChild(pElement);
        }
        else {
            let pElement = document.createElement('p');
            pElement.textContent = "The second button! Not so confident...";
            pElement.style.fontWeight = 'bold';
            gameFinishedElement.appendChild(pElement);
        }

        // Divider
        let hrElement = document.createElement('hr');
        gameFinishedElement.appendChild(hrElement);

        let pElement2 = document.createElement('p');
        pElement2.textContent = "For the second question, you picked this image:";
        gameFinishedElement.appendChild(pElement2);

        // Creating image element for third question
        let finishedGameImg = document.createElement('img');

        // Pulling secondGameUserChoice to generate image
        switch(secondGameUserChoice) {
            case (1):
                finishedGameImg.src = "https://i.pinimg.com/originals/24/be/1d/24be1d174c4fd7b8d47f9ca59ecea08f.jpg";
                break;

            case (2):
                finishedGameImg.src = "https://i.pinimg.com/736x/37/68/be/3768beb6730402ea0201cabef9f78808.jpg";
                break;
            
            case (3):
                finishedGameImg.src = "https://strattondesigngroup.com/wp-content/uploads/2018/09/stratton-design-group-portfolio-modern-dream-home-02.jpg";
                break;
        }

        finishedGameImg.classList.add('third-game-image');
        gameFinishedElement.appendChild(finishedGameImg);

        // Divider
        let hrElement2 = document.createElement('hr');
        gameFinishedElement.appendChild(hrElement2);

        let pElement3 = document.createElement('p');
        pElement3.textContent = "For the third question, you answered:";
        gameFinishedElement.appendChild(pElement3);

        switch(thirdGameUserChoice) {
            case (1):
                let pElement1 = document.createElement('p');
                pElement1.textContent = "You liked the chair!";
                pElement1.style.fontWeight = 'bold';
                gameFinishedElement.appendChild(pElement1);
                break;
            case (2):
                let pElement2 = document.createElement('p');
                pElement2.textContent = "You liked the lights!";
                pElement2.style.fontWeight = 'bold';
                gameFinishedElement.appendChild(pElement2);
                break;
        }

        // Divider
        let hrElement3 = document.createElement('hr');
        gameFinishedElement.appendChild(hrElement3);

        let pElement4 = document.createElement('p');
        pElement4.textContent = "For the fourth question, it took you ";
        pElement4.textContent += fourthGameUserTries;
        pElement4.textContent += " tries!";
        gameFinishedElement.appendChild(pElement4);

        // Divider
        let hrElement4 = document.createElement('hr');
        gameFinishedElement.appendChild(hrElement4);

        let pElement5 = document.createElement('p');
        pElement5.textContent = "Thanks for playing, ";
        pElement5.textContent += username;
        pElement5.textContent += "!";
        gameFinishedElement.appendChild(pElement5);
    }
})