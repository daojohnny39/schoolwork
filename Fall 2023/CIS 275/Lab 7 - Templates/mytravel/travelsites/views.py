from django.shortcuts import render
from django.http import HttpResponse
from .models import TripCategory, Destination

# Create your views here.
def showtripsPageView(request) :
    return render(request, 'travelsites/showTrips.html')

def showAirbnbPageView(request) :
    id = TripCategory.objects.get(description = "Airbnb")
    data = Destination.objects.get(trip_category_id = id)
    context = {
        "area" : id.description,
        "image" : data.main_photo
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showToursPageView(request) :
    id = TripCategory.objects.get(description = "Tours")
    data = Destination.objects.get(trip_category_id = id)
    context = {
        "area" : id.description,
        "image" : data.main_photo
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showCityPageView(request) :
    id = TripCategory.objects.get(description = "City")
    data = Destination.objects.get(trip_category_id = id)
    context = {
        "area" : id.description,
        "image" : data.main_photo
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showHollywoodPageView(request) :
    id = TripCategory.objects.get(description = "Hollywood")
    data = Destination.objects.get(trip_category_id = id)
    context = {
        "area" : id.description,
        "image" : data.main_photo
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showDisneylandPageView(request) :
    id = TripCategory.objects.get(description = "Disneyland")
    data = Destination.objects.get(trip_category_id = id)
    context = {
        "area" : id.description,
        "image" : data.main_photo
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showUniversalPageView(request) :
    id = TripCategory.objects.get(description = "Universal")
    data = Destination.objects.get(trip_category_id = id)
    context = {
        "area" : id.description,
        "image" : data.main_photo
    }
    return render(request, 'travelsites/displayTrips.html', context)