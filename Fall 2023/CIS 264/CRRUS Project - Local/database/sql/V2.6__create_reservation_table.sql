CREATE TABLE Reservation (
	ReservationID int NOT NULL,
	CabinID int,
	RenterID int,
	CheckInDate date,
	CheckOutDate date,
	Status varchar(30),
    PRIMARY KEY (ReservationID),
	FOREIGN KEY (CabinID)
		REFERENCES Cabins (CabinID),
	FOREIGN KEY (RenterID)
		REFERENCES Renters (RenterID)
);

