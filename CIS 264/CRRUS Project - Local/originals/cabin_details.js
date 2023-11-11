/* cabin details js */

// ------------------ EXTRACTING GOOGLE DRIVE LINKS
function extractGoogleDriveId(url) {
    const regex = /\/file\/d\/(.*?)\//;
    const match = url.match(regex);
    return match ? match[1] : null;
}

// Replace DRIVE_FILE_ID with googleDriveId
const templateURL = "https://drive.google.com/uc?id=DRIVE_FILE_ID";
// ------------------ GOOGLE DRIVE LINK EXTRACTION END

function changeTitle(cabinName) {
    var title = document.querySelector('title');
    title.textContent = '';
    title.textContent = "CRRUS - " + cabinName;
}

function displayPropertyDetails(cabinId) {
    // Getting cabin details from API
    fetch(`http://127.0.0.1:8000/cabins/${cabinId}`)
        .then(response => response.json())
        .then(cabin => {
            // Generating the HTML for the cabin
            var cabinElement = document.createElement('div');
            cabinElement.className = 'cabin'; // Assign a string class name

            // Checking and replacing Google Drive image URL
            let imageURL = cabin.ImageURL; // Use a separate variable to store the transformed URL
            if (imageURL.includes("drive.google.com/file/d/")) {
                let googleDriveId = extractGoogleDriveId(imageURL);
                imageURL = templateURL.replace("DRIVE_FILE_ID", googleDriveId);
            }

            // Displaying Image of property
            var imgElement = document.createElement('img');
            imgElement.src = imageURL; // Use the transformed URL
            imgElement.alt = cabin.CabinName;

            //for pop up image
            imgElement.id = 'pop-up'; // Assign an id to the imgElement
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


            // Putting property details in its own div  TESTING
            //var wholeDescElement = document.createElement('div');
            //cabinElement.className = 'wholeDesc';

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

            // Add the wholeDescElement to the cabinElement TESTING
            //cabinElement.appendChild(wholeDescElement);

            // Add the cabin to the page
            var propertyDetails = document.getElementById('cabinDetails');
            propertyDetails.innerHTML = ''; // Clear existing content
            propertyDetails.appendChild(cabinElement); // Append the new cabin element

            changeTitle(cabin.CabinName); // Call the changeTitle function with the cabin name
        })
        .catch(error => console.log(error));
};

function openImagePopup() {
    //console.log("this function was ran");
    window.href.location = imageURL;
}
