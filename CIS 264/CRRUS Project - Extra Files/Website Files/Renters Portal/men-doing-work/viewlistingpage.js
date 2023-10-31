window.onload = function() {
    var bookButton = document.querySelector('.book-button button');
    if (bookButton) { // Check if the button exists
        var originalBookText = bookButton.textContent;
        var newBookText = 'booked !';

        bookButton.addEventListener('click', function() {
            if (bookButton.textContent === originalBookText) {
                bookButton.textContent = newBookText;
                bookButton.style.backgroundColor = '#00cc00';
            } else {
                bookButton.textContent = originalBookText;
                bookButton.style.backgroundColor = '#0070cc';
            }
        });
    } else {
        console.log('Button not found');
    }
}
