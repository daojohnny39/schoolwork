from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def indexPageView(request) :
    return render(request, 'homepages/index.html')

def aboutPageView(request) :
    return render(request, 'homepages/about.html')

#TEMP
def productPageView(request, product, sku, price):
    productInfo = {
        "product" : product,
        "sku" : sku,
        "price" : price }
    return render(request, 'homepages/product.html', productInfo)