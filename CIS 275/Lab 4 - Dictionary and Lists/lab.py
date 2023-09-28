# Johnny (Nhat) Dao
# 9/28/2023
# Professor Price
# Lab 4: Dictionary and List

import random as r

def randomName():
    asCustomers = ["name1", "name2", "name3", "name4", "name5", "name6", "name7", "name8"]
    iRandomNum = r.randint(0, len(asCustomers) - 1)
    return asCustomers[iRandomNum]

def randomBurgers():
    return r.randint(1, 20)

customerQueue = []
customerDict = {}

for i in range(0, 100):
    customerQueue.append(randomName())
    
while customerQueue:
    sCustomer = customerQueue.pop(0)
    if sCustomer not in customerDict:
        customerDict[sCustomer] = 0
    customerDict[sCustomer] += randomBurgers()
    
customerSortedList = []
for customer, burgers in customerDict.items():
    customerSortedList.append((customer, burgers))
    
listLen = len(customerSortedList)
for i in range(listLen):
    for j in range(0, listLen - i - 1):
        if (customerSortedList[j][1] < customerSortedList[j+1][1]):
            customerSortedList[j], customerSortedList[j + 1] = customerSortedList[j + 1], customerSortedList[j]
            
for customer, burgers in customerSortedList:
    print(f"{customer:20s}{burgers:3d}")

