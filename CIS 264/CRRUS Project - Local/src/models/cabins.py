from pydantic import BaseModel

class CabinCreate(BaseModel):
    Cabiname: str
    Address: str
    City: str
    State: str
    ZipCode: int
    Description: str
    ImageURL: str
    BasePricePerNight: float
    SquareFeet: int
    BedRoom: int
    Amenity: str
    Hostid: int

class Cabin(CabinCreate):
    Cabinid: int
    
    class Config:
        from_attributes = True