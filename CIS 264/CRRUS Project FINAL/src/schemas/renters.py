from sqlalchemy import Boolean, Column, Integer, String
from database import Base
from pydantic import BaseModel

#new comment
class Users(Base):
    __tablename__ = "users"

    Renterid = Column(Integer, primary_key=True, index=True)
    email = Column(String, unique=True, index=True)
    first_name = Column(String)
    last_name = Column(String)
    password = Column(String)
    is_active = Column(Boolean, default=True)
    
class RenterCreate(BaseModel):
    email: str
    password: str
    first_name: str
    last_name: str
    phone_number: str