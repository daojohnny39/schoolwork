/* cabin details js */
const ReservedDays = [];

window.onload = function() {
    updateSignIn();
    const signOutButton = document.getElementById('signOutButton');
    if (signOutButton) {
        signOutButton.addEventListener('click', updateSignOut);
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

            getReservedDays(cabinId);
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
            priceElement.style.fontSize = "1.8rem";
            priceElement.style.textAlign = "right";
            priceElement.style.fontFamily = "Arial, Helvetica, sans-serif";
            priceElement.textContent = "$" + cabin.BasePricePerNight + " / night";
            cabinElement.appendChild(priceElement);

            //Display Calendar to book cabin.  
            var datePickerContainer =  document.createElement('div');
            datePickerContainer.className = "date-picker-container";
            cabinElement.appendChild(datePickerContainer);


            var dateInput =  document.createElement('input');
            dateInput.id = "dateInput";
            dateInput.style.maxWidth = "150px";
            dateInput.style.borderRadius = "5px";
            dateInput.style.border = "none";
            dateInput.style.boxShadow = "0 2px 5px rgba(0, 0, 0, 0.2)";
            dateInput.placeholder = "Click to choose date";
            datePickerContainer.appendChild(dateInput);

            var datePicker =  document.createElement('div');
            datePicker.className = "date-picker";
            datePicker.id = "datePicker";
            datePickerContainer.appendChild(datePicker);

            var datePickerHeader =  document.createElement('div');
            datePickerHeader.className = "date-picker-header";
            datePicker.appendChild(datePickerHeader);

            var yearSelector =  document.createElement('select');
            yearSelector.id = "yearSelector";
            datePickerHeader.appendChild(yearSelector);

            var monthSelector =  document.createElement('select');
            monthSelector.id = "monthSelector";
            datePickerHeader.appendChild(monthSelector);

            var calendarElement =  document.createElement('div');
            calendarElement.id = "calendar";
            calendarElement.className = "calendar";
            datePicker.appendChild(calendarElement);

            var chooseButton =  document.createElement('button');
            chooseButton.id = "chooseButton";
            chooseButton.className = "choose-button";
            chooseButton.textContent = "Choose";
            datePicker.appendChild(chooseButton);
            
            
            
            // Displaying "Book Now" Button
            var bookButton = document.createElement('button');
            bookButton.className = "bookButton";
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
            amenitiesElement.textContent = "Amenities: " + cabin.Amenity.replace(/;/g, ", ");
            cabinElement.appendChild(amenitiesElement);

            // Add the cabin to the page
            var propertyDetails = document.getElementById('cabinDetails');
            propertyDetails.innerHTML = ''; 
            propertyDetails.appendChild(cabinElement);

            changeTitle(cabin.CabinName);
			      cabinDateReservation();

            bookButton.addEventListener("click", function() {
 
              // You can now use checkinDate, checkoutDate, and cabinId to make a request to your backend
              // For example, using fetch API to send a POST request
              const renterID = sessionStorage.getItem('renterid');
              if (dateInput.value !== '' && renterID) {
                const dateRange = dateInput.value;
                const myDates = dateRange.split(' ');
                const formData = new FormData();
                formData.append('CheckInDate', myDates[0]);
                formData.append('CheckOutDate', myDates[2]);
                formData.append('Cabinid', parseInt(cabinId));
                formData.append('Renterid', renterID);

                console.log(formData.values);
                formData.append('Renterid', renterID);
                fetch('/create_reservation', {
                  method: 'POST',
                  body: formData
                })
                .then(response => response.json())
                .then(data => {
                  // Handle the response from the server, if needed
                  if (data.message === 'reservation complete') {
                    let ppp = document.getElementById("discount");

                    let reserveAmount = calculateTotalAmount(myDates[0], myDates[2],cabin.BasePricePerNight);
                    ppp.innerHTML = "Enjoy your " + reserveAmount[1]*100 + "% discount!"; 

                    let ppd = document.getElementById("totalAmount");
                    ppd.innerHTML = "Total: " + "$"+reserveAmount[0].toFixed(2);


                    openPopup();
                    dateInput.value = "";
                  }
                })
                .catch(error => {
                  // Handle errors
                  console.error('Error:', error);
                }); 
              } else {
                console.log("no value");
              }
            });
        })
        .catch(error => console.log(error));
      
};


function getReservedDays (cabinId){
  fetch(`/reservations/cabin/${cabinId}`)
  .then(response => response.json())
  .then(data => {
    // Handle the response from the server, if needed
    data.forEach((res) => {
      const startDate = res.CheckInDate.split('-');
      const year = parseInt(startDate[0]);
      const month = parseInt(startDate[1]) - 1;
      const day = parseInt(startDate[2]);
      for (let i = day; i <= day + 6; i ++ ) {
        dayObj = new Date(year, month, i);
        ReservedDays.push(dayObj.toLocaleDateString());
      }
    });
  });
}

function openImagePopup() {
    window.href.location = imageURL;
}

function openPopup() {
  // Show the overlay and pop-up window
  document.getElementById('overlay').style.display = 'block';
  document.getElementById('popup').style.display = 'block';
}

function closePopup() {
  // Hide the overlay and pop-up window
  document.getElementById('overlay').style.display = 'none';
  document.getElementById('popup').style.display = 'none';
}


// Login functionality (using session storage)
function updateSignIn() {
    const renter = sessionStorage.getItem('renter');
    console.log(renter);

    if (renter) {
        const signIn = document.querySelector('.sign-in');
        signIn.innerHTML = '';

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
    sessionStorage.removeItem('renterid');
    location.reload();
}


//Calendar date picker to reserve stay date range. 
function cabinDateReservation() {
    const dateInput = document.getElementById("dateInput");
    const datePicker = document.getElementById("datePicker");
    const calendar = document.getElementById("calendar");
    const chooseButton = document.getElementById("chooseButton");
    const yearSelector = document.getElementById("yearSelector");
    const monthSelector = document.getElementById("monthSelector");
    let selectedStartDate = null;
    let selectedEndDate = null;


    function showDatePicker() {
      datePicker.style.display = "block";
    }

    function hideDatePicker() {
      datePicker.style.display = "none";
    }

    function populateYearDropdown() {
      const currentYear = new Date().getFullYear();
      for (let year = currentYear; year <= currentYear + 5; year++) {
        const option = document.createElement("option");
        option.value = year;
        option.textContent = year;
        yearSelector.appendChild(option);
      }
    }

    function populateMonthDropdown() {
      const months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
      months.forEach((month, index) => {
        const option = document.createElement("option");
        option.value = index + 1;
        option.textContent = month;
        monthSelector.appendChild(option);
      });
    }

    function createCalendar(year, month) {
      calendar.innerHTML = "";
      const daysInMonth = new Date(year, month + 1, 0).getDate();
      const firstDayOfMonth = new Date(year, month, 1);
      const lastDayOfMonth = new Date(year, month, daysInMonth);

      for (let i = 1; i <= daysInMonth; i++) {
        const dayElement = document.createElement("div");
        dayElement.className = "day";
        dayElement.textContent = i;

        today = new Date(year, month, i);
        if (ReservedDays.includes(today.toLocaleDateString())) {
          dayElement.classList.add("greyoout");
        }
        else {
          let j = 0;
          for (j = 1; j < 6; j++) {
            next_day = new Date(year, month, i+j);
            if (ReservedDays.includes(next_day.toLocaleDateString())) {
              break;
            }
          }
          if (j == 6) {
            dayElement.addEventListener("click", () => {
              selectedStartDate = new Date(year, month, i);
              selectedEndDate = new Date(year, month, i + 6);
              highlightSelectedDates();
            });
          }
        }

        calendar.appendChild(dayElement);
      }
    }

    function highlightSelectedDates() {
      const days = calendar.querySelectorAll(".day");
      days.forEach((dayElement, index) => {
        if (index >= selectedStartDate.getDate() - 1 && index < selectedStartDate.getDate() + 6) {
          dayElement.classList.add("selected");
        } else {
          dayElement.classList.remove("selected");
        }
      });
      chooseButton.classList.add("selected");
    }

    function clearSelection() {
      chooseButton.classList.remove("selected");
      const days = calendar.querySelectorAll(".day");
      days.forEach((dayElement) => {
        dayElement.classList.remove("selected");
      });

      if (selectedStartDate) {
        const formattedStartDate = selectedStartDate.toLocaleDateString('en-US', { year: 'numeric', month: 'numeric', day: 'numeric' });
        const formattedEndDate = selectedEndDate.toLocaleDateString('en-US', { year: 'numeric', month: 'numeric', day: 'numeric' });
        dateInput.value = `${formattedStartDate} to ${formattedEndDate}`;
      } else {
        dateInput.value = "";
      }

      selectedStartDate = null;
      hideDatePicker();
    }

    populateYearDropdown();
    populateMonthDropdown();

    dateInput.addEventListener("click", () => {
      const currentDate = new Date();
      yearSelector.value = currentDate.getFullYear();
      monthSelector.value = currentDate.getMonth() + 1;
      createCalendar(currentDate.getFullYear(), currentDate.getMonth());
      showDatePicker();
    });

    chooseButton.addEventListener("click", () => {
      if (chooseButton.classList.contains("selected")) {
        chooseButton.classList.remove("selected");
        clearSelection();
      }
    });

    document.addEventListener("click", (event) => {
      if (!datePicker.contains(event.target) && event.target !== dateInput) {
        hideDatePicker();
      }
    });

    yearSelector.addEventListener("change", () => {
      const selectedYear = parseInt(yearSelector.value);
      const selectedMonth = parseInt(monthSelector.value) - 1;
      createCalendar(selectedYear, selectedMonth);
    });

    monthSelector.addEventListener("change", () => {
      const selectedYear = parseInt(yearSelector.value);
      const selectedMonth = parseInt(monthSelector.value) - 1;
      createCalendar(selectedYear, selectedMonth);
    });
  
}

function calculateTotalAmount(startDate, endDate, dailyRentRate) {
  // Convert start and end dates to JavaScript Date objects
  const startDateObj = new Date(startDate);
  const endDateObj = new Date(endDate);

  // Calculate the total number of days for the reservation
  const totalDays = (endDateObj - startDateObj) / (1000 * 60 * 60 * 24);

  // Get the month of the start date (0-indexed)
  const bookingMonth = startDateObj.getMonth();

  // Define discount rates based on the booking month
  let discountRate = 0;
  if (bookingMonth >= 0 && bookingMonth <= 2) {
    discountRate = 0.4; // 40% discount for December to March
  } else if (bookingMonth >= 3 && bookingMonth <= 4) {
    discountRate = 0.2; // 20% discount for April to May
  } else if (bookingMonth >= 5 && bookingMonth <= 8) {
    discountRate = 0;   // No discount for June to September (full price)
  } else if (bookingMonth >= 9 && bookingMonth <= 12) {
    discountRate = 0.2; // 20% discount for October to November
  }

  // Calculate the total amount with the applied discount
  const totalAmount = totalDays * dailyRentRate * (1 - discountRate);

  return [totalAmount, discountRate];
}
