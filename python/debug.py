inputList = list(map(eval,input().split()))
increaseDict = dict({})
for i in range(len(inputList)):
    number = inputList[0]
    findList = list(filter(lambda x : x>number,inputList))
    inputList.pop(0)
    increaseDict[number] = findList
print(increaseDict)
increaseList = []
for num in increaseDict:
    if increaseDict[num] == []:
        continue
    notFound = True
    for increase in increaseList:
        if increase[-1] == num:
            notFound = False
            for i in range(1,len(increaseDict[num])):
                copyIncrease = increase
                increaseList.append(copyIncrease.append(increaseDict[num][i]))
            increase.append(increaseDict[num][0])
    if notFound:
        for i in range(len(increaseDict[num])):
            copyIncrease = [num]
            increaseList.append(copyIncrease.append(increaseDict[num][i]))
print(increaseList)
#print(max(increaseList,key=len))
