def buildABetterPassword(password):
    
    # character of choice
    charChoice = ">"
    
    if len(password) % 2 == 0:
        midIndex = len(password) // 2
    else:
       midIndex = ((len(password) + 1) // 2) # +1 is to account for the index starting at 0
        
    # splits the password into two parts    
    passP1 = password[0:midIndex]
    passP2 = password[midIndex:]
    
    # makes changes to the first part of the password
    newPassP1 = (passP1.replace("e", "3").replace("E", "3").replace("a", "@")
               .replace("A", "@").replace("o", "0").replace("O", "0").replace("s", "$")
               .replace("S", "$").replace("i", "!").replace("I", "!"))
    
    # makes changes to the second part of the password
    newPassP2 = (passP2.replace("e", "3").replace("E", "3").replace("a", "@")
               .replace("A", "@").replace("o", "0").replace("O", "0").replace("s", "$")
               .replace("S", "$").replace("i", "!").replace("I", "!"))
    
    # converts the first part of the password into a list
    # replaces the middle character with the character of choice
    # converts the list back into a string
    passConvList = list(newPassP1)
    passConvList[midIndex - 1] = charChoice
    convNewPassP1 = "".join(passConvList)
    
    return convNewPassP1 + newPassP2
    
def main():
    password = input("Enter a password: ")
    
    # input validator
    while len(password) < 8:
        print("Your password must be at least 8 characters long.")
        password = input("Enter a password: ")
    
    betterPassword = buildABetterPassword(password)
    betterPassLen = len(betterPassword)
        
    print(f"A better password would be {betterPassword}, it is {betterPassLen} characters long.")
    
    # Below is just a series of tests to make sure the function works properly
    
    """
    # TEST 1:
    password0 = "MyDogIsBuddy"
    
    betterPassword0 = buildABetterPassword(password0)
    betterPassLen0 = len(betterPassword0)
        
    print(f"A better password would be {betterPassword}, it is {betterPassLen} characters long.")
    
    
    # TEST 2:
    password1 = "MyDogIsBuddy1"
        
    betterPassword1 = buildABetterPassword(password1)
    betterPassLen1 = len(betterPassword1)
    
    print(f"A better password would be {betterPassword1}, it is {betterPassLen1} characters long.")
    
    # TEST 3:
    password2 = "ThereAre9"
    
    betterPassword2 = buildABetterPassword(password2)
    betterPassLen2 = len(betterPassword2)
    
    print(f"A better password would be {betterPassword2}, it is {betterPassLen2} characters long.")
    
    # TEST 4:
    password3 = "ThereAre10"
    
    betterPassword3 = buildABetterPassword(password3)
    betterPassLen3 = len(betterPassword3)
    
    print(f"A better password would be {betterPassword3}, it is {betterPassLen3} characters long.") 
    """
    
if __name__ == "__main__":
    main()