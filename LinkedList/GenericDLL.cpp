#include<iostream>
#include<exception>
#include <stdexcept>

template <typename E> class DLinkedList;

/*********** Node Class ***********/
template <typename E>
class DNode{
    private:
        E item;
        DNode<E>* prev;
        DNode<E>* next;
    friend class DLinkedList<E>;

    public:
        //GETTERS
        const E& getItem() const{return item;}
        DNode<E>* getPrev() const{ return prev;}
        DNode<E>* getNext() const{ return next;}

        //SETTERS
        void setItem(E& a){ item = a;}
        void setPrev(DNode<E>* A){prev = A;}
        void setNext(DNode<E>* A){next = A;}

};


/*********** Doubly Linked List class*******/
template <typename E>
class DLinkedList{
    private:
        DNode<E>* header;
        DNode<E>* trailer;
        unsigned int number_of_Nodes;
    public:
        DLinkedList();                      //Constructor Initialises header and trailer
        ~DLinkedList();                     //Destructor
        bool isEmpty() const;               //returns true is the List is empty
        const E& front() const;             //returns the element near to the header
        const E& back() const;              //returns the element neat to the trailer
        void addFront(const E&);            //adds an element to the font of the list
        void addBack(const E&);             //adds an element to the back of the list
        void removeFront();                 //Removes an element near to the header
        void removeBack();                  //Removes an element near to the trailer
        unsigned int size();                //returns the size  of the list
};

/***********Constructor****************/
template <typename E>
DLinkedList<E>::DLinkedList(){
    header = new DNode<E>;
    trailer = new DNode<E>;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
    number_of_Nodes = 0;
}

/***********Destructor***************/
template <typename E>
DLinkedList<E>::~DLinkedList(){
    while(!isEmpty()){removeFront();}
    delete header;
    delete trailer;
}

/*********** To check if the linked list is empty*************/
template <typename E>
bool DLinkedList<E>::isEmpty() const{
    if(header->next == trailer&&trailer->prev==header)
        return true;
    else
        return false;
}

/**********get the front element*****************/
template <typename E>
const E& DLinkedList<E>::front()const{
    return header->next->getItem();
    

}
/*********get the back element********************/
template <typename E>
const E& DLinkedList<E>::back()const{
        return trailer->prev->item;
}

/*********Insert an element at the head***********/
template<typename E>
void DLinkedList<E>::addFront(const E& e){
    DNode<E>* N = new DNode<E>;
    N->item = e;
    N->next = header->next;
    N->prev=header;
    header->next->prev = N;
    header->next = N;
    number_of_Nodes++;
}

/*********Insert an element at the back***********/
template<typename E>
void DLinkedList<E>::addBack(const E& e){
    DNode<E>* N = new DNode<E>;
    N->item = e;
    N->prev = trailer->prev;
    N->next = trailer;
    trailer->prev->next = N; 
    trailer->prev = N;
    number_of_Nodes++;
}

/*********Remove an element from the front********/
template<typename E>
void DLinkedList<E>::removeFront(){
    DNode<E>* temp=header->next;
    header->next->next->prev=header;
    header->next = header->next->next;
    delete temp;
}

/*********Removes an element from the back********/
template<typename E>
void DLinkedList<E>::removeBack(){
    DNode<E>* temp=trailer->prev;
    trailer->prev->prev->next = trailer;
    trailer->prev = trailer->prev->prev;
    delete temp;
}

/***********Size Of the linked list**************/
template<typename E>
unsigned int DLinkedList<E>::size(){return number_of_Nodes;}


int main(){
    DLinkedList<int> l;
    int a=34;
    l.addFront(a);
    a=55;
    l.addBack(a);
    a = l.front();
    a++;
    std::cout<<"Element at front = "<<l.front()<<'\n';
    
    std::cout<<"Element at back = "<<l.back()<<'\n';
    a=65;
    l.addBack(a);
    std::cout<<"Element at back = "<<l.back()<<'\n';
    l.removeBack();
    std::cout<<"Element at back = "<<l.back()<<'\n';
    l.removeFront();
    std::cout<<"Element at front = "<<l.front()<<'\n'; 
    std::cout<<"Size = "<<l.size()<<'\n';
}
