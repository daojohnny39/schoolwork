#Function

def name_it(sName, iAge) :

    if (iAge == 0) :

        iAge = 10

    

    return (sName + " is " + str(iAge) + " years old")

 

#Main Program

sPerson = "Mickey"

print( name_it(sPerson, 75) )