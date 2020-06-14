#include<vector>
#include<iostream>

class Node{
    private:
        Node *parent;
        Node *leftChild;
        Node *rightChild;
        int value;
    public:
        Node(const int& a);
        Node(); 
        //Getters
        int getValue() const;
        Node& getLeftChild() const;
        Node& getRightChild() const;
        Node& getParent() const;
        //Setters
        void setValue(const int& );
        void setParent(Node* );
        void setRightChild(setRightChildNode* );
        void setLeftChild(Node* );
}

Node::Node(const int& a){
    this->value = a;
    this->leftChild=NULL;
    this->rightChild=NULL;
    this->parent=NULL;
}

Node::Node(){
    this->leftChild=NULL;
    this->rightChild=NULL;
    this->parent=NULL;
}


