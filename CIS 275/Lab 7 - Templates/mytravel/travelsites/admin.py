from django.contrib import admin
from .models import Customer, TripCategory, Destination
# Register your models here.

admin.site.register(Customer)
admin.site.register(TripCategory)
admin.site.register(Destination)