filename = input('file name: ')
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

print(f'the network name is {title} with n={node} nodes and m={arc} arcs')
sp = [[-1 if i != j and matrix[i][j] == 0 else matrix[i][j] for j in range(node)] for i in range(node)]
pred = [[0 for i in range(node)] for j in range(node)]
for i in range(node):
    for j in range(node):
        if i == j:
            continue
        for k in range(node):
            if i == k or sp[i][j] == -1 or sp[k][i] == -1:
                continue
            a = sp[i][j]
            b = sp[k][i]
            if sp[k][j] == -1 or a + b < sp[k][j]:
                sp[k][j] = a + b
                pred[k][j] = i+1
printList(sp)
# print()
# printList(pred)
