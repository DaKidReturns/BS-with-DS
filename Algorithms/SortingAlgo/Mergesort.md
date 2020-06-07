# Merge Sort

The theory for merge sort is available almost anywhere on the internet. If you are wondering how to 
implement it. Let me help.

So it is a Recusive sorting algorithm (If you don't know what recursion is you should stop here 
before reading further). What Merge Sort does is that it takes two **sorted** arrays and creates 
a new **sorted** array.

For example:

Array1: [1,4,5,7]

Array2: [2,3,6,7]

Array3: [1,2,3,4,5,6,7,7]

So if we can split an array to arrays till there are N arrays (N being the number of items in the 
array) we can merge sort two at a time till we get a single sorted array.

That is exactly what merge sort does!!! 

So to sort an array like [2,4,1,5,3,8] we can divide the array into smaller parts and sort 
those parts one by one

Division 1: [2,4,1,5,3,8] --> [2,4,1] and [5,3,8]

Division 2: [2,4,1] --> [2,4] and [1]

Division 3: [2,4] --> [2] and [4] Now there is nothing else to divide (begining index = last index)

This is where we use the power of **recursion**

Merge Sort 1: Now we run merge sort on the latest division so we have 2 arrays with one element 
each and sorting them would give us [2,4]

Merge Sort 2: Sort [2,4] and [1] --> [1,2,4]

Note that here similar process happens in the part [5,3,8] changing it to -->[3,5,8]

Then running the last merge sort [1,2,4] and [3,5,8] -->[1,2,3,4,5,8]

There it is, the array is sorted Yeah!!!!

## Tips On The Implemetaion of Merge Sort

Now During the implementation you have to note that if the algorithm can sort an array with 2 
elements it can do it for any number of elements.

Since the array is divided in half and the same process happens on both the halves.

so all you have to do is make two funtions, one for the spliting of the array and other 
one will sort 'em up.

Note that you have to call the splitting function twice since it has to split an array and 
take the 'half array' and slpit it aging until there is only one element in it, and then start 
sorting.

The source code is provided, but I strongly recommend not to check it until you have implemented your own version of merge sort...
