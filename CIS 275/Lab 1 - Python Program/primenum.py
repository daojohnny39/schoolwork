import math

# defining a function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, math.floor(math.sqrt(n)) + 1): 
        if n % i == 0:
            return False
    return True

# printing every number from 1 to 100 and whether it is prime or not
for i in range (1,100):
    if is_prime(i):
        print(i, "is prime.")
    else:
        print(i, "is not prime.")