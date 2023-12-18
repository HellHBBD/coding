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

print(f'the network name is {title} with n={node} nodes and m={arc} arcs')
d = [-1] * node
pred = [-1] * node
queue = []

while 1:
    s = eval(input('input the origin, if the origin is \'0\', then the code STOP:'))
    if s == 0:
        break
    queue.append(s)
    d[s-1] = 0
    while queue != []:
        tail = queue.pop(0)
        for head,length in nodes[tail].items():
            queue.append(head)
            distance = d[tail-1] + min(length)
            if d[head-1] == -1 or distance < d[head-1]:
                d[head-1] = distance
                pred[head-1] = tail
    print(f'd:{d}')
    print(f'p:{pred}')
'''
{1: {2: [7], 3: [5], 4: [1]}, 2: {5: [4]}, 3: {2: [7], 5: [9], 6: [9]}, 4: {2: [5], 7: [16]}, 5: {4: [4], 8: [1]}, 6: {7: [1]}, 7: {1: [2], 8: [4]}, 8: {6: [2], 7: [4]}}
'''
