from pydantic import BaseModel
from sqlalchemy import Column, Integer, String
from database import Base

class Renter(Base):
    __tablename__ = "Renters"
    
    RenterID = Column(Integer, primary_key=True)
    Email = Column(String(255), unique=True)
    Password = Column(String(255))
    RenterFirstName = Column(String(255))