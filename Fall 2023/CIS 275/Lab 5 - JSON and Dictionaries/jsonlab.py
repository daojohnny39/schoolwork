import json

# astronauts.json is in the same directory
with open ('astronauts.json') as fInput:
    astros = json.load(fInput)
    
# var declarations
sumOfAge = 0
sumOfMissionsDur = 0
count = 1

for astronaut in astros:
    #printing astronaut information
    print(f"{count} {astronaut['Profile']['Name']} {astronaut['Mission']['Year']} {astronaut['Profile']['Birth Year']}")
    
    #adding each astronaut's age and adding each astronaut's mission duration
    sumOfAge = sumOfAge + (astronaut['Mission']['Year'] - astronaut['Profile']['Birth Year'])
    sumOfMissionsDur = sumOfMissionsDur + (astronaut['Mission']['Durations']['Mission duration'])
    
    count = count + 1
    
# fixing count at the end
count = count - 1

# to make print statement easier
ageAverage = round((sumOfAge / count), 1)
missionDurAver = round((sumOfMissionsDur / count), 2)

# ending print statements
print(f"The average age of an astronaut at the time of their mission is {ageAverage}")
print(f"The average mission duration is {missionDurAver}")
