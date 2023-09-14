import re
import os

personPriceList = []
fileName = input('file name: ')
with open(fileName, 'r') as file:
    lineCount = 0
    for line in file:
        if lineCount == 0:
            lineCount += 1
            continue
        lineList = line.replace('"','').strip().split(',')
        singleList = []
        totalPrice = 0
        for i in range(len(lineList)):
            item = lineList[i]
            if i == 0:
                singleList.append(item)
                continue
            if item == '':
                singleList.append(totalPrice)
                totalPrice = 0
                continue
            priceList = re.findall(r'\d+',item)
            for price in priceList:
                totalPrice += eval(price)
        singleList.append(totalPrice)
        personPriceList.append(singleList)
        lineCount += 1

print('data contributed successfully!')

with open('totalPrice.csv', 'w') as file:
    date = 9
    file.write('姓名')
    for i in range(7):
        file.write(','+'1/'+str(date+i))
    file.write('\n')
    for line in personPriceList:
        for i in range(len(line)):
            file.write(str(line[i])+',')
        file.write('\n')

print('data written successfully!')
os.system('pause')
