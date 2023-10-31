from pydantic import BaseModel

class ReservationCreate(BaseModel):
    RenterFirstName: str # NO VARCHAR, SO STRINGs INSTEAD???