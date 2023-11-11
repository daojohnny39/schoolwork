/* cabin details js */
window.onload = function() {
    updateSignIn();
    const signOutButton = document.getElementById('signOutButton');
    if (signOutButton) {
        signOutButton.addEventListener('click', signOut);
    }
}

function extractGoogleDriveId(url) {
    const regex = /\/file\/d\/(.*?)\//;
    const match = url.match(regex);
    return match ? match[1] : null;
}

function changeTitle(cabinName) {
    var title = document.querySelector('title');
    title.textContent = '';
    title.textContent = "CRRUS - " + cabinName;
}

function displayPropertyDetails(cabinId) {
    // Getting cabin details from API
    fetch(`http://127.0.0.1:8000/cabins/${cabinId}`)
        .then(response => response.json())
        .then(data => {
            // JSON format was updated where everything is now nested under the "cabin" key
            let cabin = data.cabin;

            // Generating the HTML for the cabin
            var cabinElement = document.createElement('div');
            cabinElement.className = 'cabin'; // Assign a string class name

            // Checking and replacing Google Drive image URL
            let imageURL = cabin.ImageURL; // Using separate variable to store the transformed URL
            if (cabin.ImageURL.includes("drive.google.com/file/d/")) {
                let googleDriveId = extractGoogleDriveId(cabin.ImageURL);
                const templateURL = "https://drive.google.com/uc?id=DRIVE_FILE_ID";
                imageURL = templateURL.replace("DRIVE_FILE_ID", googleDriveId);
            }

            // Displaying Image of property
            var imgElement = document.createElement('img');
            imgElement.src = imageURL; 
            imgElement.alt = cabin.CabinName;

            //for pop up image
            imgElement.id = 'pop-up'; 
            cabinElement.appendChild(imgElement);
            imgElement.setAttribute('onclick', `window.location.href = '${cabin.ImageURL}';`);

            // Displaying Name of property
            var nameElement = document.createElement('h3');
            nameElement.textContent = cabin.CabinName;
            cabinElement.appendChild(nameElement);
            
            // Displaying Address of property
            var addressElement = document.createElement('h4');
            addressElement.textContent = cabin.Address;
            cabinElement.appendChild(addressElement);

            var cityStateElement = document.createElement('h5');
            cityStateElement.textContent = cabin.City + ", " + cabin.State;
            cabinElement.appendChild(cityStateElement);

            var zipCodeElement = document.createElement('h6');
            zipCodeElement.textContent = cabin.ZipCode;
            cabinElement.appendChild(zipCodeElement);

            // Displaying Price of property
            var priceElement = document.createElement('h3');
            priceElement.style.marginTop = "-120px";
            priceElement.style.color = "#0070cc";
            priceElement.style.fontSize = "1.3rem";
            priceElement.style.textAlign = "right";
            priceElement.style.fontFamily = "Arial, Helvetica, sans-serif";
            priceElement.textContent = "$" + cabin.BasePricePerNight + " / night";
            cabinElement.appendChild(priceElement);

            // Displaying "Book Now" Button
            var bookButton = document.createElement('button');
            bookButton.textContent = "Book Now";
            cabinElement.appendChild(bookButton);

            // Displaying Description of property
            var descDeclarationElement = document.createElement('h7');
            descDeclarationElement.style.marginTop = "50px";
            descDeclarationElement.textContent = "Description";
            cabinElement.appendChild(descDeclarationElement);

            var descElement = document.createElement('p');
            descElement.className = 'description';
            descElement.textContent = cabin.Description;
            cabinElement.appendChild(descElement);

            var amenitiesElement = document.createElement('p');
            amenitiesElement.className = 'description';
            amenitiesElement.textContent = "Amenities: " + cabin.Amenity;
            cabinElement.appendChild(amenitiesElement);

            // Add the cabin to the page
            var propertyDetails = document.getElementById('cabinDetails');
            propertyDetails.innerHTML = ''; 
            propertyDetails.appendChild(cabinElement);

            changeTitle(cabin.CabinName);
        })
        .catch(error => console.log(error));
};

function openImagePopup() {
    window.href.location = imageURL;
}

// Login functionality (using session storage)
function updateSignIn() {
    const renter = sessionStorage.getItem('renter');
    console.log(renter);

    if (renter) {
        const signIn = document.querySelector('.sign-in');
        signIn.innerHTML = ''; //clears .sign-in

        // Welcome message
        const welcomeMessage = document.createElement('span');
        welcomeMessage.id = 'welcomeText';
        welcomeMessage.textContent = `Welcome, ${renter}`;
        signIn.appendChild(welcomeMessage);

        // Sign out button displays once user is logged in
        const signOutButton = document.createElement('button');
        signOutButton.id = 'signOutButton';
        signOutButton.textContent = 'Sign Out';
        signOutButton.addEventListener('click', updateSignOut);
        signIn.appendChild(signOutButton);
    }
}

function updateSignOut() {
    sessionStorage.removeItem('renter');
    location.reload();
}
