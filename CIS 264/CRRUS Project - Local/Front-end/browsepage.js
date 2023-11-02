window.onload = function() {
    
    var filtersButton = document.getElementById('filters-button');
    var filtersMenu = document.getElementById('filters-menu');

    filtersButton.addEventListener('click', function() {
        if (filtersMenu.style.display === 'none') {
            filtersMenu.style.display = 'block';
        } else {
            filtersMenu.style.display = 'none';
        }
    });

    filtersMenu.addEventListener('click', function(event) {
        if (event.target.tagName === 'A') {
            var filter = event.target.textContent;
            console.log('Filtering by ' + filter);
            switch (filter) {
                case 'Price Range':
                    sortPropertiesByPrice();
                    break;
                case 'Amenities':
                    sortPropertiesByAmenities();
                    break;
            }
        }
    });
    getCabinsFromApi();
    displayProperties();
}

const options = {
    method: "GET",
    mode: 'no-cors',
};
function getCabinsFromApi() {
    return  fetch('http://127.0.0.1:8000/cabins').then(response => response.json())
     .then(data => {
         //console.log(cabins);
         var properties = data.map(cabin => ({
             id: cabin.CabinId,
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
         return properties;
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

// testing code:
//console.log(directLink);  // Outputs: https://drive.google.com/uc?id=13XE4Ah1aK5kSGniMbeard9DJ1iuroR_K
// ------------------ GOOGLE DRIVE LINK EXTRACTION END

function sortPropertiesByPrice() {
    properties.sort(function(a, b) {
        return a.price - b.price;
    });

    console.log(properties);
    displayProperties();
}

function sortPropertiesByAmenities() {
    properties.sort(function(a, b) {
        return b.amenities.length - a.amenities.length;
    });

    console.log(properties); 
    displayProperties();
}

function displayProperties() {
    var propertiesList = document.getElementById('property-grid');
    getCabinsFromApi().then(properties => {
        console.log(properties);
        propertiesList.innerHTML = '';

    // Generate the HTML for each property
    properties.forEach(function(property) {
        var propertyElement = document.createElement('div');
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

        // Create the description element
        var linkElement = document.createElement('a');
        linkElement.href = 'viewlistingpage.html?id='+property.id;
        linkElement.textContent = 'View Details';
        propertyElement.appendChild(linkElement);

        // Create the price element
        var priceElement = document.createElement('p');
        priceElement.textContent = 'Price: $' + property.price + '/night';
        propertyElement.appendChild(priceElement);

        // Add the property to the list
        propertiesList.appendChild(propertyElement);
    });})
}