window.onload = function() {
  //getCabinsFromApi();
  const queryString = window.location.search;
  console.log(queryString);
  const urlParams = new URLSearchParams(queryString);
  const id = urlParams.get('id')
  console.log(id);
  displayProperties(id);
}

const options = {
  method: "GET",
  mode: 'no-cors',
};
function getCabinsFromApi(id) {
  console.log(id);
  return  fetch('http://127.0.0.1:8000/cabins/'+id).then(response => response.json())
   .then(data => {
       //console.log(cabin);
       //console.log(data)
       var property = [data].map( cabin => ({
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
       console.log(property);
       return property[0];
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

function displayProperties(id) {
  var propertiesList = document.getElementById('property-grid');
  getCabinsFromApi(id).then(property => {
      console.log(property);
      propertiesList.innerHTML = '';

  // Generate the HTML for each property

      var propertyElement = document.createElement('div');
      propertyElement.className = 'more-deets'; //CHANGED
      
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
      priceElement.textContent = 'Price: $' + property.price + '/night';
      propertyElement.appendChild(priceElement);

      var bedroomsElement = document.createElement('p');
      bedroomsElement.textContent = 'Bedroom: '+ property.bedrooms;
      propertyElement.appendChild(bedroomsElement);

      var descElement = document.createElement('p');
      descElement.textContent = 'Description: '+ property.description;
      propertyElement.appendChild(descElement);

      var amentiesElement = document.createElement('p');
      amentiesElement.textContent = 'Amenities: '+ property.amenities;
      propertyElement.appendChild(amentiesElement);


      // Add the property to the list
      propertiesList.appendChild(propertyElement);
})
}

// CabinProperty.js
//import React from 'react';
//
//const CabinProperty = ({
//  CabinName,
//  Address,
//  Description,
//  ImageURL,
//  BasePricePerNight,
//  SquareFeet,
//  BedRoom,
//  Condition,
//  Amenity,
//}) => {
//  return (
//    <div className="cabin-property">
//      <h2>{CabinName}</h2>
//      <p>{Address}</p>
//      <p>{Description}</p>
//      <img src={ImageURL} alt={CabinName} />
//      <p>Base Price per Night: ${BasePricePerNight}</p>
//      <p>Square Feet: {SquareFeet} sq. ft.</p>
//      <p>Bedrooms: {BedRoom}</p>
//      <p>Condition: {Condition}</p>
//      <p>Amenities: {Amenity}</p>
//    </div>
//  );
//};
//
//export default CabinProperty;
//
//
//
//// In your React component
//import React, { useEffect, useState } from 'react';
//import CabinProperty from './CabinProperty'; // Your CabinProperty component
//
//const CabinPropertiesList = () => {
//  const [cabinProperties, setCabinProperties] = useState([]);
//
//  useEffect(() => {
//    // Fetch data from the API
//    fetch('http://127.0.0.1:8000/cabins')
//      .then((response) => response.json())
//      .then((data) => {
//        setCabinProperties(data);
//      })
//      .catch((error) => {
//        console.error('Error fetching data: ', error);
//      });
//  }, []);
//
//  return (
//    <div>
//      {cabinProperties.map((cabin) => (
//        <CabinProperty
//          key={cabin.CabinID}
//          cabinName={cabin.CabinName}
//          address={cabin.Address}
//          description={cabin.Description}
//          imageURL={cabin.ImageURL}
//          basePricePerNight={cabin.BasePricePerNight}
//          squareFeet={cabin.SquareFeet}
//          bedRoom={cabin.BedRoom}
//          condition={cabin.Condition}
//          amenity={cabin.Amenity}
//        />
//      ))}
//    </div>
//  );
//};
//
//export default CabinPropertiesList;
//
//
//