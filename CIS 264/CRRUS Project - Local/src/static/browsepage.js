
// Variables set for sorting and cabins display  
var sortByPrice = "default"; // Do lowest for low-to-high, highest for high-to-low, string instead of boolean for default
var originalProperties = [];
var amenitySearchInput; // global declaration for displayProperties()

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
        signOutButton.addEventListener('click', updateSignOut);
    }

    // Amenity Search (Onload)
    amenitySearchInput = document.getElementById('amenity-search');

    if (amenitySearchInput) {
        amenitySearchInput.addEventListener('input', filterPropertiesByAmenity)
    }
}

// Not really sure what this is
const options = {
    method: "GET",
    mode: 'no-cors',
};

// Properties declaration
var properties = [];

// Mapping the properties from the API to the properties array
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

 // Converting default Google Drive link to a direct link (for images)
function extractGoogleDriveId(url) {
    const regex = /\/file\/d\/(.*?)\//;
    const match = url.match(regex);
    return match ? match[1] : null;
}

// Sorting the properties by price (Lowest to Highest)
function sortPropertiesByPrice(ascending = true) {
    properties.sort(function(a, b) {
        if (ascending) {
            return a.price - b.price;
        } else {
            return b.price - a.price;
        }
    });
    displayProperties();
}


// Updating the user's name when they sign out
function updateSignOut() {
    sessionStorage.removeItem('renter');
    location.reload();
}

// Toggle price sorting functionality
function toggleSortByPrice() {
    var sortButton = document.getElementById('sort-button');
    if (sortByPrice === "default") {
        sortPropertiesByPrice(true); // Pass true for ascending order
        sortByPrice = "lowest-to-highest";
        sortButton.textContent = "Sort (Lowest to Highest)";
    }
    else if (sortByPrice === "lowest-to-highest") {
        sortPropertiesByPrice(false); // Pass false for descending order
        sortByPrice = "highest-to-lowest";
        sortButton.textContent = "Sort (Highest to Lowest)";
    }
    else {
        properties = [...originalProperties];
        displayProperties();
        sortByPrice = "default";
        sortButton.textContent = "Sort";
    }
}


// Amenities search functionality
function filterPropertiesByAmenity() {
    properties = [...originalProperties];
    displayProperties();
}

// Displays all properties
function displayProperties() {
    var propertiesList = document.getElementById('property-grid');
    propertiesList.innerHTML = '';

    // Amenity Search Functionality Catch
    const amenitySearchValue = amenitySearchInput.value.toLowerCase();
    if (amenitySearchValue) {
        properties = properties.filter(property => 
            property.amenities.some(amenity => 
                amenity.toLowerCase().includes(amenitySearchValue)
            )
        );
    }

    // Generate the HTML for each property
    properties.forEach(function(property) {
    var propertyElement = document.createElement('div');
        
    // onclick functionality
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

    // image element
    var imgElement = document.createElement('img');
    imgElement.src = property.image;
    imgElement.alt = property.name;
    propertyElement.appendChild(imgElement);

    // name element
    var nameElement = document.createElement('h3');
    nameElement.textContent = property.name;
    propertyElement.appendChild(nameElement);

    // address element
    var zipCodeElement = document.createElement('h4');
    zipCodeElement.textContent = property.address + ', ' + property.zipCode;
    propertyElement.appendChild(zipCodeElement);

    // price element
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
