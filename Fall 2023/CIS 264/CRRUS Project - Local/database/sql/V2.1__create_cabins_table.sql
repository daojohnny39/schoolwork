CREATE TABLE Cabins (
	CabinID int NOT NULL,
	CabinName varchar(90),
	Address varchar(250),
	City varchar(50),
	State varchar(2),
	ZipCode int,
	Description varchar(8000),
	ImageURL varchar(500),
	BasePricePerNight DOUBLE,
	SquareFeet int,
	BedRoom int,
	Condition int,
	HostID int,
	Amenity varchar(500),
    PRIMARY KEY (CabinID),
	FOREIGN KEY (HostID)
		REFERENCES Hosts (HostID)
);

