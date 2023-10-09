n = eval(input())
line = input()
string_list = line.split()
#string_list = input().split()
number_list = []
for i in string_list:
    number = eval(i)
    number_list.append(number)
#number_list = list(map(eval,input().split()))
#number_list = [eval(i) for i in input().split()]
line = input()
string_list = line.split()
count = 0
for i in string_list:
    if eval(i) in number_list:
        count = count + 1
        #count += 1
print(count)
