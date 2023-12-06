# Version 1.0 of API

#pip installs:
#pip install fastapi
#pip install uvicorn
#pip install sqlalchemy
#pip install jinja2
#pip install python-multipart


from fastapi import FastAPI, Path, HTTPException, status, Depends, Request, Form
import uvicorn
from datetime import date
from fastapi.middleware.cors import CORSMiddleware

from models.reservations import ReservationCreate as ReservationCreateModel

from database import engine, SessionLocal, Base
from sqlalchemy.orm import Session
from controller.database_controller import DatabaseController

from fastapi.responses import RedirectResponse
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles 
from fastapi.templating import Jinja2Templates

# ---- for LOGIN
from sqlalchemy.ext.declarative import declarative_base
from models.renters import Renter

# ---- for REGISTRATION
from schemas.renters import RenterCreate

app = FastAPI()
controller = DatabaseController()

origins = [
    "http://localhost:8080"
]

Base.metadata.create_all(bind=engine)
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)   

templates = Jinja2Templates(directory="templates")
app.mount("/static", StaticFiles(directory="static"), name="static")

def get_db():
    try:
        db = SessionLocal()
        yield db
    finally:
        db.close()

# Cabin related commands -----------------------------------------------------------------
@app.get("/cabins")
def get_cabins(db: Session = Depends(get_db)):
    return controller.get_cabins(db)

# Shows a cabin's details and reservations
@app.get("/cabins/{cabin_id}")
def get_cabin_by_id(cabin_id: int = Path(description="The ID of the cabin you'd like to retrieve", gt=999), db: Session = Depends(get_db)):
    cabin = controller.get_cabin_by_id(cabin_id, db)
    if cabin is None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Cabin does not exists")
    reservations = [reservation for reservation in cabin.reservationsList]
    full_response = {
        "cabin": cabin, 
        "reservations": reservations }
    return full_response

# Reservation related commands -----------------------------------------------------------------
@app.get("/reservations/{reservation_id}")
def get_reservation_info(reservation_id: int = Path(description="The ID of the reservation you'd like to retrieve", gt=999), db: Session = Depends(get_db)):
    reservation = controller.get_reservation_info(reservation_id, db)
    if reservation is None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Reservation does not exists")
    return reservation
# Reservation related commands END -----------------------------------------------------------------



# Cabin Reservation related commands -----------------------------------------------------------------
@app.get("/reservations/cabin/{cabin_id}")
def get_cabin_reservations(cabin_id: int = Path(description="The ID of the cabin you'd like to retrieve", gt=999), db: Session = Depends(get_db)):
    reservation = controller.get_cabin_reservations(cabin_id, db)
    if reservation is None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Reservation does not exists")
    return reservation
# Reservation related commands END -----------------------------------------------------------------




# Page view functions -----------------------------------------------------------------
# Homepage
@app.get("/")
async def homepage(request: Request, db: Session = Depends(get_db)):
    return templates.TemplateResponse("browsepage.html", {"request": request})

# View cabin details page
@app.get("/cabins/{cabin_id}/details")
async def cabin_details(request: Request, cabin_id: int, db: Session = Depends(get_db)):
    cabin = controller.get_cabin_by_id(cabin_id, db)
    if cabin is None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Cabin does not exist")
    
    cabin_dict = {c.name: getattr(cabin, c.name) for c in cabin.__table__.columns}
    
    return templates.TemplateResponse("cabin_details.html", {"request": request, "cabin": cabin_dict})

# Login page
@app.get("/login")
def loginpage(request: Request):
    return templates.TemplateResponse("login/loginpage.html", {"request": request})

# Registration page
@app.get("/registration")
def registrationpage(request: Request):
    return templates.TemplateResponse("login/registration.html", {"request": request})
# Page view functions END -----------------------------------------------------------------

# Login Function -----------------------------------------------------------------
@app.post("/login")
async def login(request: Request, email: str = Form(...), password: str = Form(...), db: Session = Depends(get_db)):
    renter = db.query(Renter).filter(Renter.Email == email).first()
    
    # If email doesn't exist
    if not renter:
        return {"message": "Login failed"}
    
    # If password does not match
    if renter.Password != password:
        return {"message": "Login failed"}
    
    return {"message": "Login successful", "renter": {"email": renter.Email, "first_name": renter.RenterFirstName,  "renter_id": renter.Renterid}}
# Login Function END -----------------------------------------------------------------

# Registration Function -----------------------------------------------------------------
@app.post("/registration")
async def registration(request: Request, email: str = Form(...), password: str = Form(...), confPassword: str = Form(...), first_name: str = Form(...), last_name: str = Form(...), phone_number: str = Form(...), db: Session = Depends(get_db)):
    if password != confPassword:
        return {"message": "Passwords do not match!"}
    
    renter = RenterCreate(email=email, password=password, first_name=first_name, last_name=last_name, phone_number=phone_number)
    created_renter = controller.create_renter(renter, db)
    
    if created_renter is None:
        return {"message": "User with this email already exists"}
    
    return RedirectResponse(url='/login', status_code=status.HTTP_303_SEE_OTHER)

# Registration Function END

# Create Reservation Function -----------------------------------------------------------------
@app.post("/create_reservation")
async def create_reservation(request: Request, CheckInDate: str = Form(...), CheckOutDate: str = Form(...), Cabinid: int = Form(...), Renterid: int = Form(...), db: Session = Depends(get_db)):
    cid = CheckInDate.split('/')
    cod = CheckOutDate.split('/')
    reservation = ReservationCreateModel(CheckInDate=date(int(cid[2]), int(cid[0]), int(cid[1])), CheckOutDate=date(int(cod[2]),int(cod[0]),int(cod[1])), Status="Pending", Cabinid=Cabinid, Renterid=Renterid)

    controller.create_reservation(reservation, db)
    
    return {"message": "reservation complete"}
# Create Reservation Function END -----------------------------------------------------------------

# Last 2 webpages, about and contact -----------------------------------------------------------------
@app.get("/aboutus")
def aboutus(request: Request):
    return templates.TemplateResponse("aboutus.html", {"request": request})

@app.get("/contactus")
def contactus(request: Request):
    return templates.TemplateResponse("contactus.html", {"request": request})


if __name__ == "__main__":
    uvicorn.run("app:app", host="127.0.0.1", reload=True)