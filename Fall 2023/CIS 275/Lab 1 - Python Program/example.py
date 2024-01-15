user_input = input("pick a number")

is_prime = True
for i in range(2, int(user_input)): 
    if int(user_input) % i == 0 :
        is_prime = False
        break #break out of the for loop since the number isn't prime

if is_prime:
   print("Your number is prime")
else:
   print("your number is not prime")