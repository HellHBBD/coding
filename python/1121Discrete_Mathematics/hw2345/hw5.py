import pdb
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
    s = eval(input('Please input a origin node [input \'0\' to stop]: '))
    if s == 0:
        print('-END-')
        break
    d = [-1] * node
    pred = [-1] * node
    d[s-1] = 0
    # for t,length in nodes[s].items():
    #     d[t-1] = min(length)
    #     pred[t-1] = s
    queue = []
    used = []
    source = s
    while True:
        # if source == 57:
        #     breakpoint()
        if source in nodes:
            for t,length in nodes[source].items():
                temp = [source,t,min(length)]
                if temp not in used:
                    queue.append(temp)
                    used.append(temp)
            queue.sort(key = lambda x : x[2])
        minEdge = queue.pop(0)
        if d[minEdge[1]-1] == -1 or d[minEdge[1]-1] > d[minEdge[0]-1] + minEdge[2]:
            d[minEdge[1]-1] = d[minEdge[0]-1] + minEdge[2]
            pred[minEdge[1]-1] = minEdge[0]
            complete = False
        source = minEdge[1]
        if queue == []:
            break

    # print(f'd[56]: {d[55]}')
    # print(f'd[57]: {d[56]}')
    # print(f'd[84]: {d[83]}')
    # print(f'd[19]: {d[18]}')
    # print(f'd[20]: {d[19]}')

    t = eval(input('Please input a destination node: '))
    print(f'{s}-{t}: [{d[t-1]}]',end=' ')
    while True:
        print(f'{t}<',end='')
        t = pred[t-1]
        if t == s:
            print(s)
            break
