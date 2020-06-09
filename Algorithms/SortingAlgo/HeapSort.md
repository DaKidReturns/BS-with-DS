Heap Sort
===========


### Introduction
Heap Sort uses a very beautiful data structure called ***Heap***, refer to the [heap][link1] data structure.  
There are generally two types of heap: `min heap` and `max heap`.

Min heaps are used in the algorithm for sorting in decending order  
Max heaps are used in the algorithm for sorting in ascending order  
(That is how I did it)

### Time complexity of Heap
Heaps have an asymptotic time complexity of bigO(N logN) and theta(N). Which is much beter compared to other  
sorting methods like quicksort.

### Space complexity of Heap
The have a space complexity of O(N+k)  

### Tips on Implementation:
1. All the non-leaf nodes need not have a child.
2. If N is the number of elemets in the array. Then the index of the node that has at ***least one child*** is `N/2-1`  
   Think about it take an array of 5 elemets, they don't form a complete binary tree, `N/2 = 2`but 2 dont have any child  
   but `(2-1)th element` i.e 1 has 2 elements. 
3. The `(N/2-1)th` won't nessecarily have 2 children so make sure (during "heapification" ) that you don't go out of bounds.
4. The HeapSort (in max heap) take the top element (which will be the largest and puts it at position N-1). Then makes the  
   resulting array(0 to N-2) a max heap by passing 0 as the node whose chidrens are max heaps.

### For more information about heap sort refer:
1. [Wikipedia][link2]
2. [Geeks for Geeks][link3]

[link1]:https://github.com/DaKidReturns/BS-with-DS/tree/master/Heaps
[link2]:https://en.wikipedia.org/wiki/Heapsort
[link3]:https://www.geeksforgeeks.org/heap-sort/
