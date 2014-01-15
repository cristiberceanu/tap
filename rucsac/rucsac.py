#! /usr/bin/python
from heapq import *
 
f = open('rucsac.in','r')
pairs = f.readline().split()
weight = int(pairs[1])
elements = int(pairs[0])
data = []
for i in range(elements):
    pairs = f.readline().split()
    data.append( (float(float(pairs[0])/float(pairs[1])), float(pairs[0]), float(pairs[1]),));
 
heap = []
 
for item in data:
    heappush(heap, item)
 
total = 0
value = 0
peak = []
#peak = [(weight/value), weight, value] - because python has only minheap
while heap and total<weight:
    peak = heappop(heap)
    # print peak
    total+=peak[1]
    value+=peak[2]
 
# value - peak[2], total - peak[2](remove last value inserted)
 
total -= peak[1]
value -= peak[2]
remaining_weight = weight - total
percentage_to_add = float(remaining_weight * 100 / 3)
value += float(percentage_to_add * peak[2] / 100)
 
print "weight: "+str(weight), "\nvalue: "+str(value)