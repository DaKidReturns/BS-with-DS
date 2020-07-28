#include<iostream>
#include<vector>

class BinaryTreeNode{
    private:
        //Set the private elements
        int elem;
        BinaryTreeNode *leftChild;
        BinaryTreeNode *rightChild;
        BinaryTreeNode *parent;

    public:
        //Getters
        int& getElem(){ return this->elem; }
        BinaryTreeNode* getLeftChild() const { return this->leftChild; }
        BinaryTreeNode* getRightChild() const { return this->rightChild; }
        BinaryTreeNode* getParent() const { return this->parent; }
        
        //Setters
        void setElem(int& e){ this->elem = e; }
        void setLeftChild(BinaryTreeNode* a){ this->leftChild = a; }
        void setRightChild(BinaryTreeNode* a){ this->rightChild = a; }
        void setParent(BinaryTreeNode* a){ this->parent = a; }
};


class BinaryTree{
    private:
        BinaryTreeNode  *root;
        void addRoot();
        void expandExternal(const BinaryTreeNode&); //Transfrom the external Binary tree node into an internal node by adding two nodes
        int n;
    public:
        //class BinaryTreeNode ;
        BinaryTree();
        typedef std::vector<BinaryTreeNode> NodeList; 
        int size() const;
        bool empty() const;
        BinaryTreeNode getRoot() const;
        BinaryTreeNode removeAboveExternal(const BinaryTreeNode* );
        void preorder(BinaryTreeNode & a,NodeList& nl);
        NodeList positions() const;
        void insert(const int&);
        ~BinaryTree();
        
};


BinaryTree ::BinaryTree(){
    root=NULL;
    n=0;
}

int BinaryTree ::size() const {
    return n;
}

bool BinaryTree ::empty() const{  
    //Returns true if the tree is empty
    if(root!=NULL)
        return true;
    return false;
}

BinaryTreeNode  BinaryTree ::getRoot()const {
    return *root;
}

void BinaryTree ::expandExternal(const BinaryTreeNode* p){
    //Transform p(an external node) into an internal node, 
    //By creating two external nodes for p
    BinaryTreeNode  *newLeft = new BinaryTreeNode ;
    BinaryTreeNode  *newRight = new BinaryTreeNode ;
    newLeft->setParent(p);
    newRight->setParent(p);
    p->setLeftChild(newLeft);
    p->setRightChild(newRight);
    n+=2;
}

BinaryTreeNode  BinaryTree ::removeAboveExternal(const BinaryTreeNode* w){
    //assume that a node w which is an external node with parent p(hence not a root)
    //if p is a root removing w and the parent p will cause w's sibling to becomen the
    //new root. 
    //if p is not a root then removing w and p will make the sibling of w the chiled of 
    //p's parent, i.e the grandparent of the sibling becomes it's parent

    BinaryTreeNode* p = w->getParent();
    BinaryTreeNode* sibling;
    
    //set the value of the sibling node
    if(w == p->getLeftChild()){
        sibling = p->getRightChild();
    }
    else{
        sibling = p->getLeftChild();
    }
    
    if(p== this->getRoot()){
        root = sibling;
    }
    else{
        BinaryTreeNode * gpar = p->getParent();
        //Make the sibling the child of the grandparent
        if(p == gpar->getRightChild()){
            gpar->setRightChild(sibling);
        }
        else{
            gpar->setLeftChild(sibling);
        }
        
        sibling->setParent(gpar);
    }
    
    delete p;
    delete w;
    n -=2;
    
    return sibling;
}

void BinaryTree ::preorder(BinaryTreeNode* a,NodeList& nl){
    nl.push_back(a);
    if(a->getLeftChild()!=NULL){
        preorder(a->getLeftChild(),nl);
    }
    if(a->getRightChild()!=NULL){
        preorder(a->getRightChild(),nl);
    }
}

BinaryTree ::NodeList BinaryTree ::positions() const{
    NodeList nl;
    preorder(getRoot(),nl);
    return nl;
}

void BinaryTree::insert(int)
