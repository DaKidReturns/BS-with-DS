#include<iostream>
#include<vector>

template<typename E> class BinaryTree;
template<typename E> class BinaryTreeNode;


template<typename E>
class BinaryTreeNode{
    private:
        //Set the private elements
        E elem;
        BinaryTreeNode *leftChild;
        BinaryTreeNode *rightChild;
        BinaryTreeNode *parent;

    public:
        //Getters
        E& getElem(){ return this->elem; }
        BinaryTreeNode<E>* getLeftChild() const { return this->leftChild; }
        BinaryTreeNode<E>* getRightChild() const { return this->rightchild; }
        BinaryTreeNode<E>* getParent() const { return this->parent; }
        
        //Setters
        void setElem(E& e){ this->elem = e; }
        void setLeftChild(BinaryTreeNode<E>* a){ this->leftChild = a; }
        void setRightChild(BinaryTreeNode<E>* a){ this->rightChild = a; }
        void setParent(BinaryTreeNode<E>* a){ this->parent = a; }
};


template<typename E>
class BinaryTree{
    private:
        BinaryTreeNode<E> *root;
        void addRoot();
        void expandExternal(const BinaryTreeNode<E>&); //Transfrom the external Binary tree node into an internal node by adding two nodes
        int n;
    public:
        //class BinaryTreeNode<E>;
        BinaryTree();
        typedef std::vector<BinaryTreeNode<E>> NodeList; 
        int size() const;
        bool empty() const;
        BinaryTreeNode<E> getRoot() const;
        BinaryTreeNode<E> removeAboveExternal(const BinaryTreeNode<E>&);
        void preorder(BinaryTreeNode<E>& a,NodeList& nl);
        NodeList positions() const;
        ~BinaryTree();
        
};


template<typename E>
BinaryTree<E>::BinaryTree(){
    root=NULL;
    n=0;
}

template<typename E>
int BinaryTree<E>::size() const {
    return n;
}

template<typename E>
bool BinaryTree<E>::empty() const{  
    //Returns true if the tree is empty
    if(root!=NULL)
        return true;
    return false;
}

template<typename E>
BinaryTreeNode<E> BinaryTree<E>::getRoot()const {
    return *root;
}

template<typename E>
void BinaryTree<E>::expandExternal(const BinaryTreeNode<E>& p){
    //Transform p(an external node) into an internal node, 
    //By creating two external nodes for p
    BinaryTreeNode<E> *newLeft = new BinaryTreeNode<E>;
    BinaryTreeNode<E> *newRight = new BinaryTreeNode<E>;
    newLeft->setParent(p);
    newRight->setParent(p);
    p->setLeftChild(newLeft);
    p->setRightChild(newRight);
    n+=2;
}

template<typename E>
BinaryTreeNode<E> BinaryTree<E>::removeAboveExternal(const BinaryTreeNode<E>& w){
    //assume that a node w which is an external node with parent p(hence not a root)
    //if p is a root removing w and the parent p will cause w's sibling to becomen the
    //new root. 
    //if p is not a root then removing w and p will make the sibling of w the chiled of 
    //p's parent, i.e the grandparent of the sibling becomes it's parent

    BinaryTreeNode<E>* p = w->getParent();
    BinaryTreeNode<E>* sibling;
    
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
        BinaryTreeNode<E>* gpar = p->getParent();
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

template<typename E>
void BinaryTree<E>::preorder(BinaryTreeNode<E>& a,NodeList& nl){
    nl.push_back(a);
    if(a->getLeftChild()!=NULL){
        preorder(a->getLeftChild(),nl);
    }
    if(a->getRightChild()!=NULL){
        preorder(a->getRightChild(),nl);
    }
}

template<typename E>
typename BinaryTree<E>::NodeList BinaryTree<E>::positions() const{
    NodeList nl;
    preorder(getRoot(),nl);
    return nl;
}


