from django.urls import path
from .views import indexPageView
from .views import aboutPageView
from .views import showCustomersPageView
from .views import showSingleCustomerPageView
from .views import updateCustomersPageView
from .views import deleteCustomerPageView
from .views import addCustomerPageView
from .views import addCustomerDestinationPageView
from .views import addCustDestPageView

urlpatterns = [
    path("", indexPageView, name="index"),
    path("about/", aboutPageView, name="about"),
    path("customers/", showCustomersPageView, name="customers"),
    path("showCustomers/<int:cust_id>/", showSingleCustomerPageView, name="showSingleCustomer"),
    path("updateCustomers/", updateCustomersPageView, name="updateCust"),
    path("deleteCustomers/<int:cust_id>/", deleteCustomerPageView, name="deleteCustomer"),
    path("addCustomer/", addCustomerPageView, name="addCustomer"),
    path("addCustomerDestination/<int:cust_id>/", addCustomerDestinationPageView, name="addCustomerDestination"),
    path("addCustDest/", addCustDestPageView, name="addCustDest"),
]