from sqlalchemy.orm import Session

from models.reservations import ReservationCreate as ReservationCreateModel
from schemas.cabins import Cabin as CabinSchema
from schemas.reservations_schema import Reservation as ReservationSchema
from typing import Dict
from sqlalchemy import func

# ---- for user registration
from models.renters import Renter
from schemas.renters import RenterCreate

class DatabaseController:
# Cabin related definitions ----------------------------------
    def get_cabins(self, db: Session):
        return db.query(CabinSchema).all()
    
    def get_cabin_by_id(self, cabin_id: int, db: Session):
        return db.query(CabinSchema).filter(CabinSchema.Cabinid == cabin_id).first()
    
# Reservation related definitions ----------------------------------
    def get_cabin_reservations(self, cabin_id: int, db: Session):
        cabin = db.query(CabinSchema).filter(CabinSchema.Cabinid == cabin_id).first()
        return cabin.reservationsList
    
    def get_reservation_info(self, reservation_id: int, db: Session):
        return db.query(ReservationSchema).filter(ReservationSchema.Reservationid == reservation_id).first()

# Create Reservation Function ----------------------------------
    def create_reservation(self, reservation: ReservationCreateModel, db: Session):
        db_reservation = ReservationSchema(
        CheckInDate=reservation.CheckInDate,
        CheckOutDate=reservation.CheckOutDate,
        Status=reservation.Status,
        Cabinid=reservation.Cabinid,
        Renterid=reservation.Renterid
        )

        # Check if ReservationID is NULL
        if db_reservation.ReservationID is None:
            # Get the maximum ReservationID in the Reservation table
            max_id = db.query(func.max(ReservationSchema.ReservationID)).scalar()
            # If the Reservation table is empty, set ReservationID to 1
            # Otherwise, set ReservationID to max_id + 1
            db_reservation.ReservationID = 1 if max_id is None else max_id + 1

        db.add(db_reservation)
        db.commit()
        db.refresh(db_reservation)
        return db_reservation
    
# User Registration ----------------------------------
    def create_renter(self, renter: RenterCreate, db: Session):
        
        # Finding next available RenterID
        max_id = db.query(func.max(Renter.Renterid)).scalar()
        renter_id = 1 if max_id is None else max_id + 1
        
        db_renter = Renter(
            Renterid = renter_id,
            Email = renter.email,
            Password = renter.password,
            RenterFirstName = renter.first_name,
            RenterLastName = renter.last_name,
            Phone = renter.phone_number,
        )
        
        # Checking if user already exists
        existing_user = db.query(Renter).filter(Renter.Email == renter.email).first()
        if existing_user:
            return None
        
        db.add(db_renter)
        db.commit()
        db.refresh(db_renter)
        return db_renter
