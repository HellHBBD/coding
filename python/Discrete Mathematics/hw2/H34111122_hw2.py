filename = input('file name: ')
matrix = []
nodes = {}
node = 0
arc = 0

with open(filename,'r',encoding='utf8') as file:
    for line in file:
        command = line.split()

        if command[0] == 'p': #graph config
            node = eval(command[2])
            arc = eval(command[3])

            matrix = [[0 for i in range(node)] for j in range(node)]

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

# print(nodes)
while True:
    index = eval(input('Please input the source vertex index (0 to exit): '))
    if index == 0:
        break
    command = eval(input('Please choose (1) Adjacency Matrix (2) Adjacency List: '))

    if command == 1:
        for i in range(node):
            if matrix[index-1][i] != 0:
                print(f'{index:4d} -> {i+1:4d} ({matrix[index-1][i]})')
        for i in range(node):
            if matrix[i][index-1] != 0:
                print(f'{i+1:4d} -> {index:4d} ({matrix[i][index-1]})')

    elif command == 2:
        for outNode in nodes[index]:
            for weight in nodes[index][outNode]:
                print(f'{index:4d} -> {outNode:4d} ({weight})')

        for arcs in range(1,node+1):
            if index not in nodes[arcs]:
                continue
            for weight in nodes[arcs][index]:
                print(f'{arcs:4d} -> {index:4d} ({weight})')

    elif command == 0:
        break
