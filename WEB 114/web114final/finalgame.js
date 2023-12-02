

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

// First Game
const gameFirstElement = document.querySelector('.game-first');

// Second Game
const gameSecondElement = document.querySelector('.game-second');
var secondGameUserChoice = 0;
var spamClickPrevent = 0;

// Third Game
const gameThirdElement = document.querySelector('.game-third');


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

    var username = document.getElementById('username-input').value;
    var userGreetElement = document.getElementById('user-greeting');
    userGreetElement.textContent = 'Welcome, ' + username + '!';

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
        console.log("thirdGameImg: " + thirdGameImg.className);
        thirdGameDiv.appendChild(thirdGameImg);

        // NOTE: Make sure image isn't interactable. (Hovering Animation)

        // Third Game Question
        let pElement = document.createElement('p');
        pElement.textContent = "What about this interior did you like?";
        thirdGameDiv.appendChild(pElement);

        // Select Options:
        let selectDiv = document.createElement('select');

        let option1Element = document.createElement('option');
        option1Element.textContent = "The Chairs";

        selectDiv.appendChild(optionElement);
        thirdGameDiv.appendChild(selectDiv);
    }
});
/* ---------------------- THIRD GAME END ---------------------- */