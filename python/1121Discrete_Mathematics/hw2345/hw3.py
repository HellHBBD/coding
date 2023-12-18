filename = input('Please input the filename of a test network: ')
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
while True:
    command = eval(input('Please choose which data structure to use (1 for adjacency matrix; 2 for adjacency list): '))
    if command == 1:
        print('the Adjacency Matrix is used')
    elif command == 2:
        print('the Adjacency List is used')

    source = eval(input('Please input a source node node s (0 to STOP): '))
    if source == 0:
        break
    queue = [source]
    used = [source]

    if command == 1:
        print('BFS touches',end='')
        while queue != []:
            front = queue.pop(0)
            for i in range(node):
                if matrix[front-1][i] == 0:
                    continue
                elif i+1 not in used:
                    queue.append(i+1)
                    used.append(i+1)
            print(f' {front}',end='')
        print()

    elif command == 2:
        print('BFS touches',end='')
        while queue != []:
            front = queue.pop(0)
            for next in nodes[front].keys():
                if next not in used:
                    queue.append(next)
                    used.append(next)
            print(f' {front}',end='')
        print()

    elif command == 0:
        break
