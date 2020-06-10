Heaps
=====
Heaps are a beautiful liitle data structures.  
Formally heaps are defined as: A ***nearly complete*** binary tree.  
It is similar to a priority queue

### Max heap and Min heap
*Max Heap* : The children of a node is ***smaller*** than the parent node(if there are children)  
*Min Heap* : The children of a node is ***larger*** than the parent node (if there are children)

### Basic Operations on Heaps
1. `find_max` or `find_min` : Find the maximum(in case of a max heap) or 
    minimum (in case of a min heap) of a min heap ie the root node.
2. `insert` : Insert a new key into the heap.  
3.  `extract_max` : remove the largest element from the heap.  
4.  `build heap`: creates a heap out of an array  
5.  `heapify` : creates a min/max heap out of a given node, assuming that the chidren are min/max 
     heaps  
6.  `isEmpty` : Checks if a heap is empty or not.
7.  `size` : returns the size of a heap.

### Varients of heaps
There are many varients of heap such as a Fibonacci heap, binomial heap, Radix heap, etc.  

### References
For more info on heap refer:  
[Wikipedia][link1]


[link1]:https://en.wikipedia.org/wiki/Heap_%28data_structure%29
