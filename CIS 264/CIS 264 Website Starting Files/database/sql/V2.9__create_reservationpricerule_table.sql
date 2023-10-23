CREATE TABLE ReservationPriceRule (
	ReservationID int,
	PricingRuleID int,
    PRIMARY KEY (ReservationID, PricingRuleID),
	FOREIGN KEY (ReservationID)
		REFERENCES Reservation (ReservationID),
	FOREIGN KEY (PricingRuleID)
		REFERENCES PricingRule (PricingRuleID)
);