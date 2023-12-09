

/*

    PERSONAL NOTES: (These are just ideas)
        MAKE EVERYTHING A CERTAIN TEXT ONCE THE WHOLE GAME IS COMPLETED

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


// Bug Fixes (1)
var firstGameChoiceMade = false;
var firstGameUserChoice = null;
/* ---------------------- GAME ELEMENTS END ---------------------- */

/* ---------------------- GAME FUNCTIONS ---------------------- */
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
        thirdGameQuestion.textContent = "So you picked image " + secondGameUserChoice + " from the last question."
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
document.body.addEventListener('click', function(event) {
    if (event.target && event.target.classList.contains('fourth-game-finish')) {
        console.log('');
        console.log('-------- Fifth Game Logs --------');

        // Div swap
        gameFourthElement.style.display = 'none';
        gameFifthElement.style.display = 'block';

        console.log("Third game div replaced!");

        // First question
        document.getElementById('fourth-game-q1-answer').addEventListener('submit', function(event) {
            event.preventDefault();

            var currentVal = parseFloat(document.querySelector('.fourth-game-q1').textContent);
            var firstQuestionInput = parseFloat(document.getElementById('fourth-game-q1-answer-input').value);

            currentVal += firstQuestionInput;

            document.querySelector('.fourth-game-q1').textContent = currentVal;
        })

        // Second question
        document.getElementById('fourth-game-q2-answer').addEventListener('submit', function(event) {
            event.preventDefault();

            // LEFT OFF HERE
        })
    }
})
/* ---------------------- FIFTH GAME END ---------------------- */