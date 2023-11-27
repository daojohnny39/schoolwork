from pydantic import BaseModel
from sqlalchemy import Column, Integer, String
from database import Base

class Renter(Base):
    __tablename__ = "Renters"
    
    Renterid = Column(Integer, primary_key=True, index=True, autoincrement=True)
    Email = Column(String(255), unique=True)
    Password = Column(String(255))
    RenterFirstName = Column(String(255))
    RenterLastName = Column(String(255))    #added for registration
    Phone = Column(String(255))       #added for registration
    
class UserRegistration(BaseModel):
    email: str
    password: str
    first_name: str
    last_name: str
    phone_number: str