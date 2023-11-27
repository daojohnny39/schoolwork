from sqlalchemy import Column, ForeignKey, Integer, DATE, VARCHAR
from sqlalchemy.orm import relationship
from database import Base

class Reservation(Base):
    __tablename__ ="Reservation"

    ReservationID =  Column(Integer, primary_key=True, index=True, autoincrement=True)
    CheckInDate = Column(DATE)
    CheckOutDate = Column(DATE)
    Status = Column(VARCHAR(500))
    Renterid = Column(Integer, ForeignKey("Renters.Renterid"))
    Cabinid = Column(Integer, ForeignKey("Cabins.Cabinid"))

    cabin = relationship("Cabin", back_populates="reservationsList")