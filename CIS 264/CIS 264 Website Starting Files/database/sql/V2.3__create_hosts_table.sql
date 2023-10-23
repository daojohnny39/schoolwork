CREATE TABLE Hosts (
	HostID int NOT NULL,
	HostFirstName varchar(90),
	HostLastName varchar(90),
	Password varchar(90),
	AddressCity varchar(50),
	AddressState varchar(2),
	PhoneNo varchar(50),
	Email varchar(255),
    PRIMARY KEY (HostID)
);

