from django.http import HttpResponse

# Create your views here.

def indexPageView(request):
    return HttpResponse('Welcome to Python R Us Programming!')

def aboutPageView(request) :
    return HttpResponse('Our company is great')

def contactPageView(request, contact_first_name, contact_last_name, contact_email) :
    return HttpResponse('Welcome ' + contact_first_name + ' ' + contact_last_name + '! We will send an email to ' + contact_email)