// Get all the buttons
const buttons = document.querySelectorAll('.calc-buttons button');

// Get the screen
const screen = document.querySelector('.calc-screen p');

// Variables to hold the current operation
let currentOperation = null;
let firstOperand = '';
let secondOperand = '';

// Attach event listeners to buttons
buttons.forEach(button => {
    button.addEventListener('click', function() {
        const value = this.textContent;
        if (!isNaN(value)) {
            if (currentOperation === null) {
                firstOperand += value;
                screen.textContent = firstOperand;
            } else {
                secondOperand += value;
                screen.textContent = secondOperand;
            }
        } else if (['+', '-', '*', '/'].includes(value)) {
            currentOperation = value;
        } else if (value === '=') {
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
            }
            screen.textContent = result;
            firstOperand = result;
            secondOperand = '';
            currentOperation = null;
        }
    });
});