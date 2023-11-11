var isSortedByPrice = false;
var originalProperties = [];

window.onload = function() {
    //sorting functionality
    var sortButton = document.getElementById('sort-button');
    sortButton.addEventListener('click', toggleSortByPrice);

    getCabinsFromApi().then(() => {
        displayProperties();
    })

    updateSignIn();
    const signOutButton = document.getElementById('signOutButton');
    if (signOutButton) {
        signOutButton.addEventListener('click', signOut);
    }
}

const options = {
    method: "GET",
    mode: 'no-cors',
};

var properties = [];

function getCabinsFromApi() {
    return  fetch('http://127.0.0.1:8000/cabins')
    .then(response => response.json())
    .then(data => {
         //console.log(cabins);
         properties = data.map(cabin => ({
             id: cabin.Cabinid,
                 city: cabin.City,
                 zipCode: cabin.ZipCode,
                 squareFeet: cabin.SquareFeet,
                 state: cabin.State,
                 address: cabin.Address,
                 description: cabin.Description,
                 bedrooms: cabin.BedRoom,
                 name: cabin.CabinName,
                 price: cabin.BasePricePerNight,
                 amenities: cabin.Amenity.split(';'), // Split the amenities string into an array
                 image: cabin.ImageURL
         }));
         originalProperties = [...properties];
     }).catch(error => console.log(error));
 }

function extractGoogleDriveId(url) {
    const regex = /\/file\/d\/(.*?)\//;
    const match = url.match(regex);
    return match ? match[1] : null;
}

function sortPropertiesByPrice() {
    properties.sort(function(a, b) {
        return a.price - b.price;
    });
    displayProperties();
}

// ----------- IGNORE -----------
/*
function sortPropertiesByAmenities() {
    properties.sort(function(a, b) {
        return b.amenities.length - a.amenities.length;
    });
    displayProperties();
}
*/
// ----------- IGNORE END -----------

function toggleSortByPrice() {
    var sortButton = document.getElementById('sort-button');
    if (!isSortedByPrice) {
        sortPropertiesByPrice();
        isSortedByPrice = true;
        sortButton.textContent = "Sort (Lowest to Highest)";
    }
    else {
        properties = [...originalProperties];
        displayProperties();
        isSortedByPrice = false;
        sortButton.textContent = "Sort";
    }
}

function displayProperties() {
    var propertiesList = document.getElementById('property-grid');
        propertiesList.innerHTML = '';

    // Generate the HTML for each property
    properties.forEach(function(property) {
        var propertyElement = document.createElement('div');
        
        //onclick functionality
        propertyElement.onclick = function() {
            window.location.href = '/cabins/' + property.id + '/details';
        }

        propertyElement.className = 'property';

        // replacing the google drive link with a direct link
        if (property.image.includes("drive.google.com/file/d/")) {
            let googleDriveId = extractGoogleDriveId(property.image);
            const templateURL = "https://drive.google.com/uc?id=DRIVE_FILE_ID";
            property.image = templateURL.replace("DRIVE_FILE_ID", googleDriveId);
        }

        // Create the image element
        var imgElement = document.createElement('img');
        imgElement.src = property.image;
        imgElement.alt = property.name;
        propertyElement.appendChild(imgElement);

        // Create the name element
        var nameElement = document.createElement('h3');
        nameElement.textContent = property.name;
        propertyElement.appendChild(nameElement);

        // Create the address element
        var zipCodeElement = document.createElement('h4');
        zipCodeElement.textContent = property.address + ', ' + property.zipCode;
        propertyElement.appendChild(zipCodeElement);

        // Create the price element
        var priceElement = document.createElement('p');
        priceElement.textContent = '$' + property.price.toFixed(2) + ' / night';
        propertyElement.appendChild(priceElement);

        // Add the property to the list
        propertiesList.appendChild(propertyElement);
    });
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
        welcomeMessage.textContent = `Welcome, ${renter}!`;
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
