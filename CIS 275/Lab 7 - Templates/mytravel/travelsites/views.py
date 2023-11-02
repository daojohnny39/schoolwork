from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def showtripsPageView(request) :
    return render(request, 'travelsites/showTrips.html')

def showAirbnbPageView(request) :
    context = {
        "area" : "Airbnb"
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showToursPageView(request) :
    context = {
        "area" : "Tours"
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showCityPageView(request) :
    context = {
        "area" : "City"
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showHollywoodPageView(request) :
    context = {
        "area" : "Hollywood"
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showDisneylandPageView(request) :
    context = {
        "area" : "Disneyland"
    }
    return render(request, 'travelsites/displayTrips.html', context)

def showUniversalPageView(request) :
    context = {
        "area" : "Universal"
    }
    return render(request, 'travelsites/displayTrips.html', context)