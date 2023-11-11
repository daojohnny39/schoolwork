from datetime import date
from pydantic import BaseModel

class ReservationCreate(BaseModel):
    Cabinid: int
    #Renterid: int
    CheckInDate: date
    CheckOutDate: date
    Status: str
    
class Reservation(ReservationCreate):
    Reservationid: int 

    class Config:
        from_attributes = True