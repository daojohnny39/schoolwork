from django.shortcuts import render
from django.http import HttpResponse

# Inventory Page Views
def inventoryPageView(request):
    return render(request, 'inventory/instruments.html')

def trumpetPageView(request, instrument_name = 'TRUMPET', price = 37):
    context = {
        'instrument_name': instrument_name.upper(),
        'price': price,
    }
    
    return render(request, 'inventory/trumpet.html', context)
