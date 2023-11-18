from datetime import date
from pydantic import BaseModel, Field
from typing import Optional

class ReservationCreate(BaseModel):

    #Reservationid: Optional[int] = Field(default=None)
    CheckInDate: date
    CheckOutDate: date
    Status: str
    Cabinid: int
    #Renterid: int
    
class Reservation(ReservationCreate):

    Reservationid: int 
    class Config:
        from_attributes = True