from django.shortcuts import render
from django.http import HttpResponse
from travelsites.models import Customer
from travelsites.models import Destination

# Create your views here.
def indexPageView(request) :
    return render(request, 'homepages/index.html')

def aboutPageView(request) :
    return render(request, 'homepages/about.html')

def showCustomersPageView(request) :
    data = Customer.objects.all()
    
    context = {
        "cust" : data
    }
    return render(request, 'homepages/showCustomers.html', context)

def showSingleCustomerPageView(request, cust_id) :
    data = Customer.objects.get(id = cust_id)
    destinations = data.destinations.all()
    
    context = {
        "record" : data,
        "dest" : destinations
    }
    return render(request, 'homepages/editCustomer.html', context)

def updateCustomersPageView(request) :
    if request.method == 'POST':
        cust_id = request.POST['cust_id']
        
        customer = Customer.objects.get(id=cust_id)
        
        customer.first_name = request.POST['first_name']
        customer.last_name = request.POST['last_name']
        customer.user_name = request.POST['user_name']
        customer.password = request.POST['password']
        customer.email = request.POST['email']
        customer.phone = request.POST['phone']
        
        customer.save()
        
    return showCustomersPageView(request)

def deleteCustomerPageView(request, cust_id) :
    data = Customer.objects.get(id = cust_id)
    
    data.delete()
    
    return showCustomersPageView(request)

#TEMP------------------------------------------------------------------------
def productPageView(request, product, sku, price):
    productInfo = {
        "product" : product,
        "sku" : sku,
        "price" : price }
    return render(request, 'homepages/product.html', productInfo)

