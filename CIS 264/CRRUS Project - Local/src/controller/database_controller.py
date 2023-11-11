from sqlalchemy.orm import Session
from fastapi import FastAPI, Path, HTTPException, status
from typing import Optional

from models.cabins import Cabin as CabinModel
from models.cabins import CabinCreate as CabinCreateModel
from schemas.cabins import Cabin as CabinSchema
from schemas.reservations import Reservation as ReservationSchema
from typing import Dict

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
    
# Showing Pages ----------------------------------