#ifndef BST_H
#define BST_H

#include<cstdio>
#include<cstdlib>

class Node{
    private:
        Node *parent;
        Node *leftChild;
        Node *rightChild;
        int value;
    public:
        Node(const int& a);
        Node(); 
        bool isLeaf() const;
        bool isRoot() const;
        void operator= (Node &a);

        //Getters
        int getValue() const{ return value;}
        Node* getLeftChild() const{return this->leftChild;}
        Node* getRightChild() const{return this->rightChild;}
        Node* getParent() const{return this->parent;}

        //Setters
        void setValue(const int& a){ this->value = a;}
        void setParent(Node* N){ this->parent = N;}
        void setRightChild(Node* N){ this->rightChild = N;}
        void setLeftChild(Node* N){ this->leftChild = N;}
};

class BinarySearchTree{
    private:
        Node* root;
        int size;
        Node* insertPos(const int& n,Node* a);
        Node* search(const int& a, Node* n)const;   //Returns a pointer to the element to be searched
        bool remove_pvt(const int& a, Node* key);
        void swap(Node* , Node*); //funtion for swapping two nodes
        
        Node* predecessor(Node* n)const;//Successor of the node in it's subtree
       
        Node* successor(Node* n)const; //Sucessor of the node in it's subtree
      
        Node* smallest(Node* n) const;
        Node* largest(Node* n) const;
    public:
        BinarySearchTree();
        bool isEmpty()const;
        Node* getRoot() const {return root;}

        void add(const int& a);
        void remove(const int& a);

        int inorderSuccessor(const int& a)const;
        int inorderPredecessor(const int& a)const;

        Node* predecessor(const int& a)const;//Successor of the node in it's subtree
        Node* successor(const int& a)const; //Sucessor of the node in it's subtree

        void inorder(Node* n)const;
        void preorder(Node* n) const;
        void postorder(Node* n)const;
        
        void deleteAll(Node* n);
        ~BinarySearchTree();
        
};

#include"bst.cpp"

#endif
