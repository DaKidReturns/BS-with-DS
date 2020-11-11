/*This is a vector implementaion of a binary search tree
 *This is currently done only for integer type in c++
 * Done By: DaKid*
 */
 
#include<iostream>
#include<vector>

typedef std::vector<int*>::iterator IntIterator;
typedef std::vector<int*>::const_iterator ConstIntIterator;

class BinarySearchTree{
    public:
        std::vector<int*> nodes;
        int _size;
        bool isRoot(int pos)const{if(pos==0) return true; return false;}
        int parent(int pos) const;
        int right(int pos) const;
        int left(int pos) const;
        int getIns(int elem,int pos=0);
        
        int predecessor(int elem);
        int successor(int elem);
        void addNode(int elem);
        BinarySearchTree();
        ~BinarySearchTree();
};
BinarySearchTree::BinarySearchTree(){
    _size = 0;
}

int BinarySearchTree::parent(int pos) const{
    if(!isRoot(pos)){
        if(pos%2==0){
            return pos/2-1;
        }
        else{
            return pos/2;
        }
    }
    else
        return -1;
}

int BinarySearchTree::right(int pos)const{
    if(nodes[(pos+1)*2]==NULL){
        return -1;
    }
    else{
        return (pos+1)*2;
    }
}

int BinarySearchTree::left(int pos)const{
    if(nodes[pos*2+1]==NULL){
        return -1;
    }
    else{
        return 1+pos*2;
    }
}

int BinarySearchTree::getIns(int elem, int pos){
    {  if(pos>=nodes.size()){
            //std::cout<<"Increased the size of pos"<<std::endl;
            nodes.resize(pos*2+1);
        }
    }

    
    if(nodes[pos]==NULL)
        return pos;
    else{
        if(elem>*nodes[pos]){
            //go right
            return  getIns(elem,(pos+1)*2);
        }
        else{
            //go left
            return getIns(elem,(pos*2+1));
        }
    }
}

void BinarySearchTree::addNode(int elem){
    int pos =getIns(elem);
    nodes[pos] = new int;
    *nodes[pos] = elem;
}

int BinarySearchTree::successor(int elem){
    int pos =0;
    int* next=NULL;
    
    while(*nodes[pos] != elem){
        {if (nodes[pos]==NULL) return NULL;}

        //std::cout<<"In the first loop "<<std::endl;
        
        if(*nodes[pos]<=elem){
            //std::cout<<*nodes[pos]<<std::endl;
            //std::cout<<"In the firs if "<<std::endl;
            pos=(pos+1)*2;
            continue;
        }
        else{
            //std::cout<<*nodes[pos]<<std::endl;
            //std::cout<<"In the firs if "<<std::endl;
            next = nodes[pos];
            pos=pos*2+1;
            continue;
        }
    }
   // std::cout<<" The value found is -> "<<*next<<std::endl;
    while(nodes[(pos+1)*2]!=NULL&&(1+pos)*2<nodes.size()){
        //if the value of the pos is out of range of the vector then there is 
        //no next element it is the last one in the subtree
        next = nodes[(1+pos)*2];
        pos = (1+pos)*2;
    }
    return *next;
}


int BinarySearchTree::predecessor(int elem){
    int pos =0;
    int* next=NULL;
    
    while(*nodes[pos] != elem){
        {if (nodes[pos]==NULL) break;}

        
        if(*nodes[pos]<=elem){
            next = nodes[pos];
            pos=(pos+1)*2;
            continue;
        }
        else{
            pos=pos*2+1;
            continue;
        }
    }
    while(nodes[1+pos*2]!=NULL && 1+pos*2<nodes.size()){
        next = nodes[pos*2+1];
        pos = pos*2+1;
    }
    return *next;
}

/*void BinarySearchTree::remove(int elem){
    int pos = 0;
    int flag = 0;
    
    //to delete the element first you  have to find it;
    while(elem!=nodes[pos]){
        {if(pos>=nodes.size()||nodes[pos]==NULL) flag=1;}
        
        if(elem>node[pos]){
            pos=2*(1+pos);
        }
        else{
            pos=2*pos+1;
        }
    }
    if(flag == 0){
        if()
    }
}*/

BinarySearchTree::~BinarySearchTree(){
    for(IntIterator i = nodes.begin();i!=nodes.end();++i){
        if(*i!=0)
            delete *i;
    }
    std::cout<<"All nodes cleared\n";
}

int main(){
    BinarySearchTree bst;
    //bst.nodes.resize(1);
    //bst.nodes[0] = new int;
    //*bst.nodes[0] = 31;
    bst.addNode(31);
    std::cout<<bst.getIns(59)<<" "<<std::endl;
    bst.addNode(59);
    std::cout<<bst.getIns(21)<<" "<<std::endl;
    bst.addNode(21);
    std::cout<<bst.getIns(43)<<" "<<std::endl;
    bst.addNode(43);
    std::cout<<bst.getIns(36)<<" "<<std::endl;
    bst.addNode(36);
    std::cout<<bst.getIns(61)<<" "<<std::endl;
    bst.addNode(61);
    std::cout<<"BST the succesor of 43 is "<<bst.successor(43)<<std::endl;
    std::cout<<"The predecessor of 31 is "<<bst.predecessor(31)<<std::endl;
    std::cout<<"size of nodes = "<<bst.nodes.size()<<std::endl;
    return 0;

}
