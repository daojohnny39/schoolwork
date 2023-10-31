CREATE TABLE CabinAmenity (
	CabinID int,
	AmenityID int,
    PRIMARY KEY (CabinID, AmenityID),
	FOREIGN KEY (CabinID)
		REFERENCES Cabins (CabinID),
	FOREIGN KEY (AmenityID)
		REFERENCES Amenity (AmenityID)
);