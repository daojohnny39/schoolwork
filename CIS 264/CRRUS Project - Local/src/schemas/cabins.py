from sqlalchemy import Column, Integer, VARCHAR, Double
from sqlalchemy.orm import relationship
from database import Base

class Cabin(Base):
    __tablename__ ="Cabins"

    Cabinid = Column(Integer, primary_key=True, index=True)
    CabinName = Column(VARCHAR(90))
    Address = Column(VARCHAR(250)) 
    City = Column(VARCHAR(50))
    State = Column(VARCHAR(2))
    ZipCode = Column(Integer)
    Description = Column(VARCHAR(8000)) 
    ImageURL = Column(VARCHAR(500)) 
    BasePricePerNight = Column(Double) 
    SquareFeet = Column(Integer)
    BedRoom = Column(Integer)
    Amenity = Column(VARCHAR(500)) 
    Hostid = Column(Integer)

    reservationsList = relationship("Reservation", back_populates="cabin")