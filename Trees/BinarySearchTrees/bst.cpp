#ifndef BST_CPP
#define BST_CPP

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

bool Node::isLeaf()const{
    if(this->getRightChild()==NULL&&this->getLeftChild()==NULL){
        return true;
    }
    return false;
}

bool Node::isRoot() const{
    if(this->getParent()==NULL){
        return true; 
    }
    return false;
}

void Node::operator=(Node &a){
    this->value=a.getValue();
    /*this->parent = a.getParent();
    this->leftChild=a.getLeftChild();
    this->rightChild=a.getRightChild();*/
}



//
//
//
// Definitions for the binary tree class
//
//
//

BinarySearchTree::BinarySearchTree(){
        root=NULL;
        size=0;
    }

bool BinarySearchTree::isEmpty()const{
        return root==NULL;
}

void BinarySearchTree::swap(Node* a, Node* b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}


/********Search for an element**********/
Node* BinarySearchTree::search(const int& a,Node* N) const{
    if(N==NULL){return NULL;}
    
    if(a>N->getValue()){
        return search(a,N->getRightChild());
    }
    else {
        if(a<N->getValue()){
            return search(a,N->getLeftChild());
        }
        else{
            return N;
        }
    }
}

/***************Recusive funtion to find the position of insertion of an element************/
Node* BinarySearchTree::insertPos(const int& n,Node* a){
    if(isEmpty()){
       return this->root; 
    }
    else{
        if(n>a->getValue()){
            if(a->getRightChild() ==NULL){
                a->setRightChild(new Node(n));
                a->getRightChild()->setParent(a);
                return a->getRightChild();
            }
            else{
                return insertPos(n,a->getRightChild());
            }
        }
        else{
            if(a->getLeftChild()==NULL){
                a->setLeftChild(new Node(n));
                a->getLeftChild()->setParent(a);
                return a->getLeftChild();

            }
            else{
                return insertPos(n,a->getLeftChild());
            }
        }
    }
}


/*************Funtion to add an element**********/
void BinarySearchTree::add(const int& a){
    Node* pos;

    pos = insertPos(a,this->root);
    if(pos==root){
        root=new Node(a);
        printf("added %d as the root of the tree\n",root->getValue());
    }    
    else{
        
        printf("added %d as the child of %d\n",pos->getValue(), pos->getParent()->getValue());
    }
    size++;
}


/*********Funtion to find the largest element in the tree********/
Node* BinarySearchTree::largest(Node* n)const{
    if(n->getRightChild()!=NULL){
        return smallest(n->getRightChild());
    }
    else{
        return n;
    }
}


/*******Funtion to find the smallest node in the tree***********/
Node* BinarySearchTree::smallest(Node* n)const{
    if(n->getLeftChild()!=NULL){
        return largest(n->getLeftChild());
    }
    else
        return n;
}


/*******Definition for the predecessor*************/
Node* BinarySearchTree::predecessor(const int& a)const{
    /*The predecessor is the largest element in the smallest subtree*/
    Node* pos;
    pos = search(a,root);
    return largest(pos->getLeftChild());

}

Node* BinarySearchTree::predecessor(Node* n)const{
    return largest(n->getLeftChild());
}

/********Definition for the successor***************/
Node* BinarySearchTree::successor(const int& n)const{
    /*The Successor is the smallest element in the largest subtree****/
    Node* pos;
    pos = search(n,root);
    return smallest(pos->getRightChild());
}


Node* BinarySearchTree::successor(Node* n)const{
    return smallest(n->getRightChild());
}


bool BinarySearchTree::remove_pvt(const int& a,Node* n){
    Node* parent;
    Node* child;
    Node* temp;
    while(n->getValue()!=a){
        if(n->getValue()<a){
            n = n->getRightChild();
        } 
        else if(n->getValue()>a){
            //printf("found %d moving left to find %d \n",n->getValue(),a);
            //fflush(stdout);
            n = n->getLeftChild();
        }

        if(n==NULL){
            //TODO: Apply experssion catching to handle element not found
            //printf("There is no element %d\n",a);
            return false;
        }
    }
    //If the program control reaches here then the required element is found

    if(n->getRightChild()==NULL || n->getLeftChild()==NULL){
        //If one of the child is null or both is null
        //printf("Entered the main deletion loop");fflush(stdout);
        if(n->getRightChild()!=NULL){
            //printf("Reciving the right child\n");fflush(stdout);
            child = n->getRightChild();
        }

        else if (n->getLeftChild()!=NULL){
            //printf("Reciving the left child\n");fflush(stdout);
            child = n->getLeftChild();
        }
        else{
            //printf("OK I am a leaf\n");fflush(stdout);
            child = NULL;
        }
        
        if(!n->isRoot()){
            parent = n->getParent();
            //printf("OK I am a not root and my parent is %d\n",parent->getValue());fflush(stdout);
            if(n==parent->getRightChild()){
                parent->setRightChild(child);
            }
            else{
                //printf("The left child of %d is NULL\n", parent->getValue());fflush(stdout);
                parent->setLeftChild(child);
            }
        }
        else{
            //If the control comes here then the element to be deleted is the root
            parent=NULL;
            this->root = child;

        }

        //printf("Before setting the parent to null\n");fflush(stdout);
        if(child!=NULL){
            child->setParent(parent);
        }
        //printf("The parent is set\n");fflush(stdout);
        delete n;
    }
    
    //If there are two childrens
    else{
        temp = successor(n); 
        *n = *temp;
        remove_pvt(temp->getValue(),temp);
    }
    
    return true;
}

void BinarySearchTree::remove(const int& a){
   if(remove_pvt(a,getRoot())){
        return; 
   }
   else{
        printf("Error No element \"%d\" found\n",a);
        return;
   }
}

/***********Returns the element greater than the enteres one from the whole tree*********/
int BinarySearchTree::inorderSuccessor(const int& a)const{
    if(search(a,root)== NULL){
        printf("Element %d is not found\n",a);      //Exception
        return 0;
    }
    
    else{
        Node* pos=root;
        Node *s=NULL;
        
        while(pos->getValue()!=a){
            if(pos->getValue()>a){
                s=pos;
                pos = pos->getLeftChild();
            }
            else
                pos=pos->getRightChild();
        }
        
        if(pos->getRightChild()!=NULL)
            s = smallest(pos->getRightChild());
        if(s==NULL){
            printf("There is no element greater than %d\n",a);  //Exception
            return 0;
        }
        return s->getValue();
    }
}


int BinarySearchTree::inorderPredecessor(const int& a)const{
    if(search(a,root)==NULL){
        
        printf("Element %d is not found\n",a);
        return 0;
    
    }
    
    else{
        
        Node* pos=root;
        Node* p;
        
        while(pos->getValue()!=a){
            if(pos->getValue()>a){
                pos = pos->getLeftChild();
            }
            else{
                p=pos; 
                pos = pos->getRightChild();
            }
        }
        
        if(pos->getLeftChild()!=NULL)  {p=largest(pos->getLeftChild()); }
        
        if(p==NULL)  {printf("Element %d has no predecessor\n",a);}
        
        return p->getValue();
    }

}

/*
void BinarySearchTree::setChildNull(Node* n){
            if(n->getParent()->getRightChild()==n)
                n->getParent()->setRightChild(NULL);
            else
                n->getParent()->setLeftChild(NULL);
}*/


/***********Definition for the Post order Traversal**********/
void BinarySearchTree::postorder(Node* n)const{
    if(n->getLeftChild()!=NULL)
        postorder(n->getLeftChild());
    if(n->getRightChild()!=NULL)
        postorder(n->getRightChild());
    printf("%d ",n->getValue());
    return;
}

/**********Definition for the inorder traversal*************/
void BinarySearchTree::inorder(Node* n)const{
    if(n->getLeftChild()!=NULL)
        inorder(n->getLeftChild());
    printf("%d ",n->getValue());
    if(n->getRightChild()!=NULL)
        inorder(n->getRightChild());
    return;
}

/*********Definition for the post order traversal**********/
void BinarySearchTree::preorder(Node* n)const{
    printf("%d ",n->getValue());
    if(n->getLeftChild()!=NULL)
        preorder(n->getLeftChild());
    if(n->getRightChild()!=NULL)
        preorder(n->getRightChild());
    return;
}


void BinarySearchTree::deleteAll(Node* root){   //use this funtion to clear entire subtree
    if (root->getLeftChild()!=NULL)
        deleteAll(root->getLeftChild());
    if(root->getRightChild()!=NULL)
        deleteAll(root->getRightChild());
    delete root;
}


BinarySearchTree::~BinarySearchTree(){
    deleteAll(root);
    printf("All cleared\n");
}


#endif
