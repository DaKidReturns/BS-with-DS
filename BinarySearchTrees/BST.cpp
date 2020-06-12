#include<vector>
#include<iostream>

class Node{
    private:
        Node *parent;
        Node *leftChild;
        Node *rightChild;
        int value;
    public:
        //Getters
        int getValue() const;
        Node& getLeftChild() const;
        Node& getRightChild() const;
        Node& getParent() const;
        //Setters
}
