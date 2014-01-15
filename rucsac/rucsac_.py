#! /usr/bin/python
 
f = open('rucsac.in','r')
pairs = f.readline().split()
weight = int(pairs[1])
elements = int(pairs[0])
 
data = [-1 for i in xrange(1,5001)]
data[0] = 0
weights = []
values = []
 
for i in range(elements):
    pairs = f.readline().split()
    weights.append(int(pairs[0]))
    values.append(int(pairs[1]))
# print weights, values
max_weight = 0
 
for i in range(0,elements):
 
    for j in range(weight - weights[i], -1, -1):
        if data[j] != -1 and data[j]+values[i] > data[j+weights[i]]:
            data[j+weights[i]] = data[j] + values[i]
            if data[j+weights[i]] > max_weight:
                max_weight = data[j+weights[i]]
# print data
print max_weight