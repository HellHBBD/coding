import random
import os

#class definition
class Poly:
    def __init__(self,n,a):
        self.maxDegree = n
        self.coefficientList = a

    def function(self,b):
        result = 0
        for i in range(self.maxDegree+1):
            result += (self.coefficientList[i] * (b**i))
        return result

    def print(self):
        print(f'f(x)= {self.coefficientList[0]}',end='')
        for i in range(1,self.maxDegree+1):
            if self.coefficientList[i] < 0:
                print(f' - {-self.coefficientList[i]}',end='')
                if i == 0:
                    pass
                else:
                    print(f' x^{i}',end='')
                continue
            elif self.coefficientList[i] == 0:
                continue
            else:
                print(' + ',end='')
            print(self.coefficientList[i],end='')
            if i == 0:
                pass
            else:
                print(f' x^{i}',end='')
        print()

#open config file
n = 0
a = []
with open('hw1_input.txt','r',encoding='utf8') as file:
    line = file.readline()
    n = eval(line)
    line = file.readline()
    a = [eval(i) for i in line.split()]

#main
#n = eval(input())
#a = [eval(i) for i in input().split()]
pf = Poly(n,a)
pf.print()
while 1:
    #b = eval(input())
    b = random.choices(('0 and stop','random float number'),weights=(1,5))[0]
    if b == '0 and stop':
        b = 0
        pass
    else:
        b = random.uniform(-5,5) #generate random float number
    print(f'f({b}) =',end=' ')
    if b == 0:
        print(pf.function(b))
        break
    else:
        print(pf.function(b))
os.system('pause')
