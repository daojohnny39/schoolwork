# CRRUS Cabin Rental Application Setup Guide

This guide is designed to assist you in configuring your system to run the CRRUS cabin rental application. Follow the steps outlined here to set up your environment and execute the necessary commands for a seamless live deployment of the application.

### Table of Contents

- [Prerequisites](#prerequisites)
    - [Installing Python](#installing-python)
    - [Packages to be downloaded](#packages-to-be-downloaded)
    - [Installing Flyway](#installing-flyway)
    - [Setup Your Own Database File](#setup-your-own-database-file)
- [Running the CRRUS Cabin Rental Application](#running-the-crrus-cabin-rental-application)

## Prerequisites<a name="prerequisites"></a>

Prior to running the application, your system must have certain software and packages downloaded and installed.

### Installing Python<a name="installing-python"></a>

Before proceeding with the setup of the CRRUS cabin rental application, ensure that Python is installed on your system. Follow the steps below to download and install Python:

1. **Download Python:**
   - Visit the [official Python website](https://www.python.org/downloads/) to download the latest version of Python.
   - Select the appropriate installer for your operating system (Windows, macOS, or Linux) and architecture (32-bit or 64-bit).

2. **Run the Installer:**
   - Execute the downloaded installer and follow the on-screen instructions.
   - During the installation, make sure to check the option that adds Python to your system PATH. This makes it easier to run Python from the command line.

3. **Verify Installation:**
   - Open a new terminal or command prompt.
   - Type the following command to check that Python has been installed successfully:
     ```bash
     python --version
     ```
     This should display the installed Python version.

### Packages to be downloaded<a name="packages-to-be-downloaded"></a>

After getting python installed, some python packages need to be installed.
Follow these steps to use `pip`, the Python package installer:

1. **Open a Terminal or Command Prompt:**
   - On Windows, you can open the Command Prompt or PowerShell.
   - On macOS and Linux, open the terminal.

2. **Navigate to Your Project Directory:**
   - Use the `cd` command to change the directory to where you have the CRRUS cabin rental application code. For example:
     ```
     cd path\to\cabin-rentals-r-us
     ```

3. **Install Required Packages:**
   - Run the following command to install the required packages:
        ```bash
        pip install fastapi uvicorn sqlalchemy jinja2 python-multipart
        ```
    
4. **Verification:**
   - After the installation is complete, you can verify that the packages are installed by running:
     ```bash
     pip list
     ```
     This should display a list of installed packages, including those required by the CRRUS cabin rental application.

### Installing Flyway<a name="installing-flyway"></a>
If you want to use your own data with the application, you will require database migrations and you'll need to use Flyway, a database migration tool. Follow these steps to download and set up Flyway on your system:

### 1. Download Flyway

Visit the [Flyway download page](https://flywaydb.org/download) to download the latest version of Flyway.

- Select the appropriate distribution for your operating system (ZIP, TAR, or MSI for Windows).
- Download and save the file to your preferred location on your machine.

### 2. Extract the Flyway Archive (If Applicable)

If you downloaded a ZIP or TAR distribution, extract the contents to a directory of your choice.

### 3. Add Flyway to Your System PATH (Optional)

For convenience, you may want to add the Flyway executable to your system PATH. This allows you to run Flyway commands from any directory in the terminal or command prompt.

#### On Unix (Linux/macOS):

```
export PATH=$PATH:/path/to/flyway-<version>
```

### On Windows:

```
$env:PATH += ";C:\path\to\flyway-<version>"
```

Replace `/path/to/flyway-<version>` or `C:\path\to\flyway-<version>` with the actual path where you extracted Flyway.

### 4. Verify Flyway Installation
Open a new terminal or command prompt and run the following command to verify that Flyway is installed:

```bash
flyway -v
```

This should display the installed Flyway version.

### 5. Setup conf file
The CRRUS application uses sqlite so setup the proper conf file for flyway to connect to your database using sqlite or you will need to edit the database.py file further to use another sql database.

You are now ready to use Flyway for managing database migrations in conjunction with the CRRUS cabin rental application.

## Setup Your Own Database File<a name="setup-your-own-database-file"></a>

The application comes with a database filled with mock data `(flyway-team3.db)`, however you will want your own database to be used with the application.

Once you have your own database file after setting up and migrating with flyway, you will need to change some lines of code to work with your database.

### 1. Move your .db file to the root folder

Before changing any lines of code, make sure that your databse in the the root folder.  This is currently called "\cabin-rentals-r-us".

### 2. Change the databse.py file

In the "database.py" file at line 5:
```bash
SQLALCHEMY_DATABASE_URL = "sqlite:///../flyway-team3.db"
```
You will need to change the `flyway-team3.db` file name to the name of your database.

## Running the CRRUS Cabin Rental Application<a name="running-the-crrus-cabin-rental-application"></a>

Now that you have installed the required packages, you can proceed to run the CRRUS cabin rental application. Follow these steps:

1. **Navigate to the Project Directory:**
   - Open a Terminal or Command Prompt.
   - Change the directory to where you have the CRRUS cabin rental application code:
     ```
     cd path\to\cabin-rentals-r-us
     ```

2. **(Optional) Activate Virtual Environment:**
   - If you are using a virtual environment, activate it to isolate your project's dependencies:
     ```
     source venv/bin/activate  # On Linux/macOS
     # or
     .\venv\Scripts\activate  # On Windows
     ```

3. **Navigate to the src Directory:**
    - Enter the following command to change to the "src" dictory that holds the application file:
        ```bash
        cd src
        ```

4. **Run the Application:**
   - Execute the following command to start the application:
     ```bash
     python app.py
     ```

5. **Access the Application:**
   - Once the application is running, open your web browser and navigate to [http://127.0.0.1:8000](http://127.0.0.1:8000) and use the application.


6. **Shutdown the Application:**
   - When you are done, stop the application by pressing `Ctrl + C` in the terminal where it's running.

✨ Congratulations! You've successfully set up and run the CRRUS cabin rental application on your system.