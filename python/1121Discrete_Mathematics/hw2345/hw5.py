import pdb
# filename = input('file name: ')
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

# print(f'the network name is {title} with n={node} nodes and m={arc} arcs')

while 1:
    # s = eval(input('Please input a origin node [input \'0\' to stop]: '))
    s = eval(input('Please input a source node [input \'0\' to stop]: '))
    if s == 0:
        print('-END-')
        break
    d = [float('inf')] * node
    d[s-1] = 0
    pred = [-1] * node
    heap = {k:d[k-1] for k in range(node)}
    heap = dict(sorted(heap.items(), key=lambda item: item[1], reverse=True))
    heap = dict(sorted(heap.items(), key=lambda item: item[1], reverse=True))
    # minEdge = heap.popitem()
    # print(minEdge)

    while True:
        heap = dict(sorted(heap.items(), key=lambda item: item[1], reverse=True))
        minEdge = heap.popitem()
        if minEdge[0] not in nodes:
            pass
        else:
            for t,length in nodes[minEdge[0]].items():
                if d[t-1] > minEdge[1] + min(length):
                    d[t-1] = minEdge[1] + min(length)
                    pred[t-1] = minEdge[0]
                    heap[t] = d[t-1]
        if heap == {}:
            break

    # print(f'd[56]: {d[55]}')
    # print(f'd[57]: {d[56]}')
    # print(f'd[84]: {d[83]}')
    # print(f'd[19]: {d[18]}')
    # print(f'd[20]: {d[19]}')

    # t = eval(input('Please input a destination node: '))
    t = eval(input('Please input a sink node: '))
    print(f'{s}-{t}: [{d[t-1]}]',end=' ')
    while True:
        print(f'{t}<',end='')
        t = pred[t-1]
        if t == s:
            print(s)
            break
