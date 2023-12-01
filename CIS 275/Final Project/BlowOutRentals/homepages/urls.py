from django.urls import path
from .views import indexPageView, aboutUsPageView

urlpatterns = [
    path("", indexPageView, name="index"),
    path("aboutus/", aboutUsPageView, name="aboutus"),
]