from django.shortcuts import render
from django.http import HttpResponse

# Homepages Views:
def indexPageView(request):
    return render(request, 'homepages/index.html')

def aboutUsPageView(request):
    return render(request, 'homepages/aboutus.html')