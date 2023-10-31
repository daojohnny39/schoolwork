# Version 1.0 of API
from fastapi import FastAPI, Path, HTTPException, status, Depends
import uvicorn
from typing import Optional

from models.cabins import Cabin as CabinModel
from models.cabins import CabinCreate as CabinCreateModel
from schemas.cabins import Cabin as CabinSchema

from database import engine, SessionLocal, Base
from sqlalchemy.orm import Session
from controller.database_controller import DatabaseController
from typing import Dict
from fastapi.middleware.cors import CORSMiddleware #changed

app = FastAPI()
controller = DatabaseController()

Base.metadata.create_all(bind=engine)
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)   #changed


def get_db():
    try:
        db = SessionLocal()
        yield db
    finally:
        db.close()


@app.get("/cabins")
def get_cabins(db: Session = Depends(get_db)):
    return controller.get_cabins(db)


@app.get("/cabins/{cabin_id}")
def get_cabin_by_id(cabin_id: int = Path(description="The ID of the cabin you'd like to retrieve", gt=999)
                     , db: Session = Depends(get_db)):
    cabin = controller.get_cabin_by_id(cabin_id, db)
    if cabin is None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Cabin does not exists")

    return cabin

if __name__ == "__main__":
    uvicorn.run("app:app", host="127.0.0.1", reload=True)