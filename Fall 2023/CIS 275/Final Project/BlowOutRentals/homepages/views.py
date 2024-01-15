from django.shortcuts import render
from django.http import HttpResponse

# Homepages Views:
def indexPageView(request):
    return render(request, 'homepages/index.html')

def aboutPageView(request):
    return render(request, 'homepages/aboutus.html')