/*  
    Johnny (Nhat) Dao 
    WEB 114 Midterm Project
    11/19/2023

    Project Requirements:
        Numbers within "()" are references within the code.

        Modify a web page's content by using the JavaScript textContent property to send information back to the user.  
        Do not use window.alert() to send information to the user.
            - (1) Use of replacing textContent

        1. How JavaScript expressions evaluate user data using +, -, *, /,  %, and **
            - (2) Use of the * operator
*/

window.onload = function() {
    var cpuButton = document.querySelector('#CPU');
    cpuButton.addEventListener('click', addOnCart);

    var gpuButton = document.querySelector('#GPU');
    gpuButton.addEventListener('click', addOnCart);

    /* ----------------- HIDDEN CHECKOUT DISPLAY ----------------- */
    var popUpElement = document.getElementById("pop-up");

    var span = document.getElementsByClassName("close")[0];

    var checkoutButton = document.getElementById("checkout-button");
    checkoutButton.onclick = function() {
        popUpElement.style.display = "block";
        generateCheckoutItems();
    }

    span.onclick = function() {
        popUpElement.style.display = "none";
    }
}

/* ----------------- CART COUNTERS ----------------- */
var cartCounter = 0; 
var totalPrice = 0;
var cartItems = {};
/* ----------------- CART COUNTERS END ----------------- */


/* ----------------- CART FUNCTIONS ----------------- */
function addOnCart(event) {

    var productDiv = event.target.parentNode;

    var quantity = productDiv.querySelector('select').value;
    cartCounter += Number(quantity);

    var cartCount = document.getElementById('cart-counter');
    cartCount.textContent = cartCounter;    // (1)

    var price =  productDiv.querySelector('.price').textContent;    // (1)
    price = Number(price.replace('$', ''));

    totalPrice += price * quantity; // (2)

    var totalPriceElement = document.getElementById('total-price');
    totalPriceElement.textContent = '$' + totalPrice;   // (1)

    var itemName = event.target.id; 

    if (!cartItems[itemName]) {
        cartItems[itemName] = Number(quantity);
    }
    else {
        cartItems[itemName] += Number(quantity);
    }

    localStorage.setItem('cartItems', JSON.stringify(cartItems));
}
/* ----------------- CART FUNCTIONS END ----------------- */

/* ----------------- CHECKOUT FUNCTIONS ----------------- */
function generateCheckoutItems() {
    var checkoutItemsElement = document.getElementById('checkout-item');

    var cartItems = JSON.parse(localStorage.getItem('cartItems'));

    for (var key in cartItems) {
        var itemElement = document.createElement('div');
        itemElement.classList.add('each-item');
        itemElement.textContent = key + ': ' + cartItems[key];  // (1)
        checkoutItemsElement.appendChild(itemElement);
    }
}
