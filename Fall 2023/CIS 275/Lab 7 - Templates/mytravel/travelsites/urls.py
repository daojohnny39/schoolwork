from django.urls import path
from .views import showtripsPageView
from .views import showAirbnbPageView
from .views import showToursPageView
from .views import showCityPageView
from .views import showHollywoodPageView
from .views import showDisneylandPageView
from .views import showUniversalPageView

urlpatterns = [
    path("", showtripsPageView, name="showtrips"),
    path("airbnb/", showAirbnbPageView, name="airbnb"),
    path("tours/", showToursPageView, name="tours"),
    path("city/", showCityPageView, name="city"),
    path("hollywood/", showHollywoodPageView, name="hollywood"),
    path("disneyland/", showDisneylandPageView, name="disneyland"),
    path("universal", showUniversalPageView, name="universal"),
]