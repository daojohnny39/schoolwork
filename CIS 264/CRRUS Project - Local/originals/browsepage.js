var isSortedByPrice = false;
var originalProperties = [];

window.onload = function() {
    //sorting functionality
    var sortButton = document.getElementById('sort-button');
    sortButton.addEventListener('click', toggleSortByPrice);

    getCabinsFromApi().then(() => {
        displayProperties();
    })
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

// ------------------ EXTRACTING GOOGLE DRIVE LINKS
function extractGoogleDriveId(url) {
    const regex = /\/file\/d\/(.*?)\//;
    const match = url.match(regex);
    return match ? match[1] : null;
}

// Replace DRIVE_FILE_ID with googleDriveId
const templateURL = "https://drive.google.com/uc?id=DRIVE_FILE_ID";
// ------------------ GOOGLE DRIVE LINK EXTRACTION END

// ------- IGNORE ----------
function sortPropertiesByPrice() {
    properties.sort(function(a, b) {
        return a.price - b.price;
    });

    //console.log(properties);
    displayProperties();
}

function sortPropertiesByAmenities() {
    properties.sort(function(a, b) {
        return b.amenities.length - a.amenities.length;
    });

    //console.log(properties); 
    displayProperties();
}

function toggleSortByPrice() {
    if (!isSortedByPrice) {
        sortPropertiesByPrice();
        isSortedByPrice = true;
    }
    else {
        properties = [...originalProperties];
        displayProperties();
        isSortedByPrice = false;
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
