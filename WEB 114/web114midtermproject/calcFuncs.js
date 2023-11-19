/*
    Johnny (Nhat) Dao
    WEB 114 Midterm Project
    11/19/2023

    Project Requirement References and Explanations:
    ------------------------------------------------------------------------------------------

        JS Functionalities:
        - (JS 1) - Using the HTML textContent of "this" which is the button.

        - (JS 2) - "screen" is defined as the calculator's screen. The textContent of the screen
                    is then updated to the result. 
                    (Modifying textContent)

        - (JS 3) - Once the user hits the "=" button, the program automatically follows up with
                    switch case statements based on what operation the user wants.

        - (JS 4) - Originally when I wrote this, it didn't display the ".", so I rewrote it to also
                    check whether the user inputted "."

    ------------------------------------------------------------------------------------------

        Operator Usage:
        - Quick note: All number values as well as operations is stored as the "value" variable.

        - (OP 1) - Once the user clicks on an operator (value which is not a number), the program 
                    will store the operator as "currentOperation".
                    (Usage of operators: + - * /)

        - (OP 2) - Using the => operator to create functionality for each button.

    ------------------------------------------------------------------------------------------

        "=", "==", and "===" Usage:
        - (=) - Every variable assignment is used with the "=" operator. This is just the first use.

        - (==) - I didn't use this because I found it to be unreliable in terms of just the calculator so I 
                    used the "===" instead.

        - (===) - I used the "===" because I wanted a strict comparison to make sure that the value 
                    of the operator is exactly the same type as the value of the "currentOperation" variable.
                    Once again, this is only the first use.

    ------------------------------------------------------------------------------------------

        Usage of "||" and "&&":
        - (||) - Originally, this was statement only checked for operators but was rewritten to also take
                    into account ".".

        - (&&) - This was used to check whether the user inputted a "." and if the operand already had a "."

    ------------------------------------------------------------------------------------------
*/

/* --------------------------------------------------------- THE CALCULATOR --------------------------------------------------------- */
// Used querySelectorAll to select all of the buttons (The value of each button is later determined by HTML textContent)
const buttons = document.querySelectorAll('.calc-buttons button');  // (=)

// Defining the p element within the screen (Used later to replace textContent)
const screen = document.querySelector('.calc-screen p');

// Operation variables
let currentOperation = null;
let firstOperand = '';
let secondOperand = '';

// This allows the screen to actually display the "." (JS 4)
function appendToOperand(operand, char) {
    if (char === '.' && operand.includes('.')) {    // (&&)
        return operand;
    }
    return operand + char;
}

// Actually getting the values from each button
buttons.forEach(button => { // (OP 2)
    button.addEventListener('click', function() {
        const value = this.textContent; // (JS 1)
        if (!isNaN(value) || value === '.') {   // (JS 4) (||)
            if (currentOperation === null) {    // (===)
                firstOperand = appendToOperand(firstOperand, value);
                screen.textContent = firstOperand;

                // OLD CODE
                //firstOperand += value;
            } 
            else {
                secondOperand = appendToOperand(secondOperand, value);
                screen.textContent = secondOperand;

                // OLD CODE
                //secondOperand += value;
            }
        } 
        else if (['+', '-', '*', '/', '^'].includes(value)) {
            currentOperation = value;
        } 
        else if (value === '=') {   // (===), (JS 3)
            let result;
            switch (currentOperation) { // (OP 1)
                case '+':
                    result = parseFloat(firstOperand) + parseFloat(secondOperand);  // parseFloat is used to make sure that the values are
                    break;                                                          // float numbers even if the user inputs an integer 
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
            screen.textContent = result;    // (JS 2)
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

/* --------------------------------------------------------- THE EXTRAS --------------------------------------------------------- */
// ---- NAME FUNCTION ---- //
let nameElement = document.getElementById("name-change");
let submitButton = document.getElementById("name-button");
let nameInput = document.getElementById("name");

function changeText() {
    let nameValue = nameInput.value;
    nameElement.textContent = "Hello, " + nameValue + "!";
}

submitButton.addEventListener("click", changeText);
// ---- NAME FUNCTION END ---- //

// ---- STORE FUNCTION ---- //
// Selecting the elements that display the counts for each item
const cpuCountElement = document.getElementById('CPU-count');
const gpuCountElement = document.getElementById('GPU-count');

// Selecting the counts from the options
const cpuSelect = document.querySelector('#CPU-select');
const gpuSelect = document.querySelector('#GPU-select');

function updateCount(event) {
    const selectedValue = event.target.value;
    const productId = event.target.id;

    if (productId === 'CPU-select') {
        cpuCountElement.textContent = 'CPU: ' + selectedValue;
    } 
    else if (productId === 'GPU-select') {
        gpuCountElement.textContent = 'GPU: ' + selectedValue;
    }
}

cpuSelect.addEventListener('change', updateCount);
gpuSelect.addEventListener('change', updateCount);
// ---- STORE FUNCTION END ---- //
/* --------------------------------------------------------- THE EXTRAS END --------------------------------------------------------- */