window.onload = function() {
    console.log("HELLO");
}

document.getElementById('registrationForm').addEventListener('submit', function(event) {
    event.preventDefault();

    const email = document.querySelector('input[name="email"]').value;
    const password = document.querySelector('input[name="password"]').value;
    const confPassword = document.querySelector('input[name="confPassword"]').value;
    const first_name = document.querySelector('input[name="first_name"]').value;
    const last_name = document.querySelector('input[name="last_name"]').value;
    const phone_number = document.querySelector('input[name="phone_number"]').value;

    const formData = new FormData();
    formData.append('email', email);
    formData.append('password', password);
    formData.append('confPassword', confPassword);
    formData.append('first_name', first_name);
    formData.append('last_name', last_name);
    formData.append('phone_number', phone_number);

    fetch('/registration', {
        method: 'POST',
        body: formData
    })
    .then(response => {
        if (response.redirected) {
            window.location.href = response.url;
        }
        else {
            return response.json();
        }
    })
    .then(data => {
        if (data && data.message === 'User successfully created') {
            alert('Registration successful!');
        }
        else {
            alert('Registration failed');
        }
    })
});