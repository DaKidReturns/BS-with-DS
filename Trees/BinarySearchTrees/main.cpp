#include"bst.h"

int main(){
    BinarySearchTree bst;
    bst.add(32);
    bst.add(45);
    bst.add(19);
    bst.add(59);
    bst.add(38);
    bst.add(18);
    bst.add(20);
    printf("%d \n",bst.predecessor(32)->getValue());
    //printf("%d \n",bst.successor(20)->getValue());
    fflush(stdout);
    //bst.swap(bst.getRoot(),bst.successor(bst.getRoot()));
    //bst.swap(bst.successor(bst.getRoot()),bst.predecessor(bst.getRoot()));
    printf("%d \n",bst.inorderSuccessor(20));
    printf("%d \n",bst.inorderPredecessor(59));
    bst.remove(32);printf("\\\\ \n");
    bst.remove(38);
    bst.remove(45);
    bst.remove(59);
    //printf("root = %d\n",bst.getRoot()->getValue());
    bst.inorder(bst.getRoot());
    return 0;
}
