# -------------------------
# This code can run without a problem.

# How to run: 
# 1. input the file that contains 2 lines, where line 1 is an integer n; and line 2 contains n+1 real numbers a[0], a[1],..., a[n]
# 2. it will print out a text like f(x)= a[0] + a[1] x^1 + a[2] x^2 + ... + a[n] x^n 
# 3. it will ask the user to input a value of x, say, b. Then it calculates and outputs f(b)
# 4. it repeats step 3, unless b=0, which prints out f(0) and STOP

# This code is written by 余柏穎, email h34111122@gs.ncku.edu.tw, on 2023/09/17
# -------------------------

import os
from decimal import Decimal

def printTerm(coefficient,degree,first):
    if coefficient == 0:
        return first
    elif coefficient == 1 and degree == 0:
        if first:
            print(' 1',end='')
            pass
        else:
            print(' + 1',end='')
        return False
    elif coefficient == -1 and degree == 0:
        print(' - 1',end='')
        return False
    elif coefficient == 1:
        if first:
            pass
        else:
            print(' +',end='')
    elif coefficient == -1:
        print(' -',end='')
    elif coefficient < 0:
        print(f' - {-coefficient}',end='')
    elif first:
        print(f' {coefficient}',end='')
    else:
        print(f' + {coefficient}',end='')

    if degree == 0:
        return False
    elif degree == 1:
        print(' x',end='')
        return False
    else:
        print(f' x^{degree}',end='')
        return False

def multiply(a,b):
    return Decimal(str(a))*Decimal(str(b))

def power(a,n):
    result = 1
    for i in range(n):
        result = Decimal(str(result)) * Decimal(str(a))
    return result

#class definition
class Poly:
    def __init__(self,n,a):
        self.maxDegree = n
        self.coefficientList = a

    def plug(self,b):
        result = 0
        for i in range(self.maxDegree+1):
            result += multiply(self.coefficientList[i],power(b,i))
        return float(result)

    def print(self):
        first = True
        print('f(x)=',end='')
        for i in range(self.maxDegree+1):
            first = printTerm(self.coefficientList[i],i,first)
        print()

n = 0
a = []
#open config file
with open('hw1_input.txt','r',encoding='utf8') as file:
    line = file.readline()
    n = eval(line)
    line = file.readline()
    a = [eval(i) for i in line.split()]

#main
#n = eval(input())
#a = [eval(i) for i in input().split()]
function = Poly(n,a)
function.print()
while 1:
    b = eval(input('input a number x to plug into the function: '))
    print(f'f({b}) =',end=' ')
    if b == 0:
        print(function.plug(b))
        break
    else:
        print(function.plug(b))

os.system('pause')
