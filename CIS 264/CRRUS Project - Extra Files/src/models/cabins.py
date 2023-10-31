from pydantic import BaseModel

class CabinCreate(BaseModel):
    Cabiname: str # NO VARCHAR, SO STRINGs INSTEAD???
    Address: str
    City: str
    State: str
    ZipCode: int
    Description: str
    ImageURL: str
    BasePricePerNight: float ## SHOULD LOOK INTO HOW TO GET A DOUBLE
    SquareFeet: int
    BedRoom: int
    Amenity: str




class Cabin(CabinCreate):
    CabinId: int

    class Config:
        from_attributes = True