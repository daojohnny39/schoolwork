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
    displayProperties();
    getCabinsFromAPI();
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
             name: cabin.CabinName,
             price: cabin.BasePricePerNight,
             amenities: cabin.Amenity.split(';'), // Split the amenities string into an array
             image: cabin.ImageURL
 
         }));
      //   console.log(properties);
         return properties;
     }).catch(error => console.log(error));
}

/*
var properties = [
    { name: 'Property 1', price: 200, amenities: ['Pool', 'Gym'], image: "../../cabin placeholder images/property1.png"},
    { name: 'Property 2', price: 150, amenities: ['Gym'], image: "../../cabin placeholder images/property2.png" },
    { name: 'Property 3', price: 300, amenities: ['Pool', 'Gym', 'Spa'], image: "../../cabin placeholder images/property3.png" },
    // ...more properties...
];
*/

var properties = [getCabinsFromAPI()];
function sortPropertiesByPrice() {
    properties.sort(function(a, b) {
        return a.price - b.price;
    });

    console.log(properties); // Log the sorted properties to the console
    displayProperties();
}


function sortPropertiesByAmenities() {
    properties.sort(function(a, b) {
        return b.amenities.length - a.amenities.length;
    });

    console.log(properties); // Log the sorted properties to the console
    displayProperties();
}
function displayProperties() {

    var propertiesList = document.getElementById('property-grid');
    getCabinsFromApi().then(properties => {
        // Now you can use the properties array
        console.log(properties);
    // Clear the current properties
    propertiesList.innerHTML = '';

    // Generate the HTML for each property
    properties.forEach(function(property) {
        var propertyElement = document.createElement('div');
        propertyElement.className = 'property';

        var imgElement = document.createElement('img');
        console.log(property.image);
        imgElement.src = property.image; // Assuming the image URL is stored in the property object
        imgElement.alt = property.name;
        propertyElement.appendChild(imgElement);

        var nameElement = document.createElement('h3');
        nameElement.textContent = property.name;
        propertyElement.appendChild(nameElement);

        var linkElement = document.createElement('a');
        linkElement.href = 'View Listing/viewlistingpage.html'; // Modify this if needed
        linkElement.textContent = 'View Details';
        propertyElement.appendChild(linkElement);

        var priceElement = document.createElement('p');
        priceElement.textContent = 'Price: $' + property.price + '/night';
        propertyElement.appendChild(priceElement);

        // Add the property to the list
        propertiesList.appendChild(propertyElement);
    });})
}