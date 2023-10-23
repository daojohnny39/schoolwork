from sqlalchemy.orm import Session
from fastapi import FastAPI, Path, HTTPException, status
from typing import Optional

from models.cabins import Cabin as CabinModel
from models.cabins import CabinCreate as CabinCreateModel
from schemas.cabins import Cabin as CabinSchema
from typing import Dict



class DatabaseController:

    def get_cabins(self, db: Session):
        return db.query(CabinSchema).all()
    
    def get_cabin_by_id(self, cabin_id: int, db: Session):
        return db.query(CabinSchema).filter(CabinSchema.CabinId == cabin_id).first()