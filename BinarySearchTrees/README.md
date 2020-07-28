#Binary Search Trees
 
 It has been a long time before I figured out how to implement BST with only the vector class in  
 C++. I admit it is tricky without maps and implemnting the remove method is highly impractical   
 when dealing with arrays of pointers.

###Introduction
A binary search tree is (as the name implies) a tree and there is 2 child for each node  
(hence the name binary). The speciality of the tree is that the one child is greater than the parent  
and the other is less than the parent.

                        34   
                     /      \  
                   23       54  

As seen in the midiocre drawing above the left child of the root (34) is 23 which is less than 34  
and the right child is 54 which is greater than 34.  

####Insertion
If I want to insert another element say 45. First I will compare 45 with 34, since 45 is greater  
than 34 i will move to the right.  
After moving to the right I find that there is 54, who came before 45, so i will compare 45 and 54  
and clearly 54 is greater hence 45 goes to the left of 54. Then the final tree will be.  

                                 34  
                                /  \  
                              23   54  
                                  /  \    
                                 45   

In this tree the leaves are 23 and 45 (since they have no children), and the root is 34 since it has  
no parent.

###Removal (not implemnated in the vector code)
If an element is to be removed there are mainly three cases (1) where is no child nodes in the node  
to be deleted (2) there is one child or one subtree in the node to be deleted (3) there is 2 subtree  
in the node to be deleted.  
#####Case 1: When there is no child for the node  
In this case the answer is simple just delete the node.  

#####Case 2: When there is one child or one sub tree for the node
In this case just replace the node with the subtree root/ the child.

#####Case 3: When there is two child node or two sub tree
In this case you have to find the successor of the node or the smallest element in the right  
sub-tree and replace the node with the successor.

###Successor and Predecessor.
