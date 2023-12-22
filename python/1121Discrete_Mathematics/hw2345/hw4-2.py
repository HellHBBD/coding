import pdb
filename = input('Please input network filename: ')
title = ''
node = 0
arc = 0
matrix = []
nodes = {}
with open(filename,'r',encoding='utf8') as file:
    for line in file:
        command = line.split()
        if command[0] == 'p': #graph config
            node = eval(command[2])
            arc = eval(command[3])
            matrix = [[0 for i in range(node)] for j in range(node)]
        elif command[0] == 't':
            title = command[1]
        elif command[0] == 'a': #add nodes
            start = eval(command[1])
            end = eval(command[2])
            weight = eval(command[3])
            if matrix[start-1][end-1] == 0 or matrix[start-1][end-1] > weight:
                matrix[start-1][end-1] = weight
            if start not in nodes:
                nodes[start] = {}
                nodes[start][end] = [weight]
            else:
                if end not in nodes[start]:
                    nodes[start][end] = [weight]
                else:
                    nodes[start][end].append(weight)

def printList(l):
    for i in l:
        for j in i:
            print(f'{j:2d}',end=' ')
        print()

sp = [[float('inf') if i != j and matrix[i][j] == 0 else matrix[i][j] for j in range(node)] for i in range(node)]
# pred = [[0 for i in range(node)] for j in range(node)]
pred = [[-1] * node for j in range(node)]
# pred = [[0] * node] * node

for i in range(node):
    for j in range(node):
        for k in range(node):
            # if k == 97 and j == 19:
            #     breakpoint()
            a = sp[i][j]
            b = sp[k][i]
            if a + b < sp[k][j]:
                sp[k][j] = a + b
                pred[k][j] = i+1
# print(sp[97])
# print()
# print()

while True:
    source = eval(input('Please input a source node [input \'0\' to stop]: '))
    if source == 0:
        print('-END-')
        break
    sink = eval(input('Please input a sink node: '))
    print(f'{source}-{sink}: [{sp[source-1][sink-1]}]',end=' ')
    while True:
        print(f'{sink}<',end='')
        sink = pred[source-1][sink-1]
        if sink == -1:
            print(source)
            break
print(pred[97])
