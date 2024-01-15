from django.db import models

# Models
class State(models.Model):
    abbrev = models.CharField(max_length=2)
    state_name = models.CharField(max_length=20)
    
    def __str__(self):
        return self.state_name
    

class Customer(models.Model):
    first_name = models.CharField(max_length=30)
    last_name = models.CharField(max_length=30)
    address = models.CharField(max_length=50)
    city = models.CharField(max_length=30)
    state = models.ForeignKey(State, on_delete=models.CASCADE)
    zipcode = models.CharField(max_length=9)
    phone = models.CharField(max_length=10)
    
    def __str__(self):
        return f"{self.first_name} {self.last_name}"
    
    
class Order(models.Model):
    description = models.CharField(max_length=20)
    cost = models.DecimalField(max_digits=8, decimal_places=2)
    order_date = models.DateTimeField()
    
    def __str__(self):
        return self.description
    
    
class CustomerOrder(models.Model):
    customer = models.ForeignKey(Customer, on_delete=models.CASCADE)
    order = models.ForeignKey(Order, on_delete=models.CASCADE)
    
    def __str__(self):
        return f"Order {self.order.id} for {self.customer.first_name} {self.customer.last_name}"
