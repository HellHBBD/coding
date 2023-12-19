c a simple network with 6 nodes 9 arcs
c this file has the following format: (in the order)
c if a line starts by
c   c : whatever follows is comment, you may ignore
c   t : title of the problem_name, you have to read it
c   p : problem type(sp), n (# nodes), m (# arcs)
c   n : #nodes
c   a : from to length
c Thus your code has to 
c   1. ignore each comment line (starts by c)
c   2. read problem_name (e.g. test1_6_9)
c   3. read problem type, # nodes, and # arcs
c   4. read # nodes (in this case, 6)
c   5. read each arc one by one (from to arc_length)
c
t test1_6_9
p sp 	6	9
n	6
a	1	2	6.0
a	1	3	4.0
a	2	3	2.0
a	2	4	2.0
a	3	4	1.0
a	3	5	2.0
a	4	6	7.0
a	5	4	1.0
a	5	6	3.0