CREATE TABLE Reviews (
	ReviewID int NOT NULL,
	ReservationID int,
	Rating int,
	Comment varchar(8000),
	DatePosted date,
	RenterID int,
    PRIMARY KEY (ReviewID),
	FOREIGN KEY (ReservationID)
		REFERENCES Reservation (ReservationID)
);

