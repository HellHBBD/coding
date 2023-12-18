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

while 1:
    d = [-1] * node
    pred = [-1] * node
    queue = []
    used = []
    s = eval(input('Please input a origin node [input \'0\' to stop]: '))
    if s == 0:
        print('-END-')
        break
    t = eval(input('Please input a destination node: '))
    queue.append(s)
    d[s-1] = 0
    while queue != []:
        tail = queue.pop(0)
        if tail not in nodes or tail in used:
        # if tail not in nodes:
            continue
        for head,length in nodes[tail].items():
            if head == s:
                continue
            queue.append(head)
            distance = d[tail-1] + min(length)
            if d[head-1] == -1 or distance < d[head-1]:
                d[head-1] = distance
                pred[head-1] = tail
        used.append(tail)
    if d[t-1] == -1:
        print(f'{s}-{t}: no posible path')
        continue
    print(f'{s}-{t}: [{d[t-1]}]',end=' ')
    while True:
        print(f'{t}<',end='')
        t = pred[t-1]
        if t == s:
            print(s)
            break
