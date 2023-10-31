from sqlalchemy import Boolean, Column, ForeignKey, Integer, DATE
from sqlalchemy.orm import relationship
from database import Base

class Reservation(Base):
    __tablename__ ="reservations"

    reservationID =  Column(Integer, primary=True, index=True)
    CabinID = Column(Integer, ForeignKey("cabin.CabinID"))
    RenterID = Column(Integer, ForeignKey("renters.RenterID"))
    CheckInDate = Column(DATE)
    CheckOutDate = Column(DATE)


    Cabins = relationship("Cabin", back_populates="Reservations")
