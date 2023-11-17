/*  
    Johnny (Nhat) Dao 
    WEB 114 Midterm Project
    11/19/2023

    Project Requirements:
        1. How JavaScript expressions evaluate user data using +, -, *, /,  %, and **
            - (1) Use of the * operator: Line 34
*/

window.onload = function() {
    var cpuButton = document.querySelector('#CPU');
    cpuButton.addEventListener('click', addOnCart);

}

/* ----------------- CART COUNTERS ----------------- */
var cartCounter = 0; 
var totalPrice = 0;
/* ----------------- CART COUNTERS END ----------------- */


/* ----------------- CART FUNCTIONS ----------------- */
function addOnCart() {
    console.log("addOnCart was ran");
    cartCounter++; // Increment the cartCounter variable

    var cartCount = document.getElementById('cart-counter');
    cartCount.textContent = cartCounter;

    var quantity = document.querySelector('.product select').value;
    var price =  document.querySelector('.product .price').textContent;
    price = Number(price.replace('$', '')); // converting price to number

    // (1) Use of the * operator
    totalPrice += price * quantity; 

    var totalPriceElement = document.getElementById('total-price');
    totalPriceElement.textContent = '$' + totalPrice;
}
