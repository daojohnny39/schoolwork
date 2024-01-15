from django.urls import path
from .views import inventoryPageView, trumpetPageView

urlpatterns = [
    path("", inventoryPageView, name="instruments"),
    path("<str:instrument_name>/<int:price>/", trumpetPageView, name="trumpet"),
]