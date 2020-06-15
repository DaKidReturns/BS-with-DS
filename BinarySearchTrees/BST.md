# Binary Search Trees (BST)

Tree Data Strucuteres can be used to implement ordered maps and orered dictionaries  
Assume that maps and dictionaries provide an additional pointer object called  
an *iterator* that permis us to reference and enumerate the entries of the  
data structre.

A binary search tree (BST) is a tree such that each internal node v stores entry  
such that  
1. Keys at nodes in the left sub trr are less than or equal to k
2. Keys at nodes in the right subtree are greater than k  

#### Basic Operations on the BST

1. Searching:- To perform operation in a binary tree. ask to each node whether the
search key is greater than, less than or equal to the key sotred in the node to be   
found.  
if it is greater go to the left subtree else go to the right subtree.  

