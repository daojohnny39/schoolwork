from sqlalchemy import Boolean, Column, ForeignKey, Integer, String, VARCHAR, Double
from sqlalchemy.orm import relationship
from database import Base

class Cabin(Base):
    __tablename__ ="cabins"

    CabinId = Column(Integer, primary_key=True, index=True)
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

    # More fields later...

    ##Reservations = relationship("Reservation", back_populates="cabins")
    # Need to read-up more on what this does