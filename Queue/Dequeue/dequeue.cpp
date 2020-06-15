#ifndef DEQUEUE_cpp
#define DEQUEUE_cpp
#include "dequeue.h"
#include <cstddef>

//Getters
template<typename T>
dqNode<T>* dqNode<T>::getNext() const{return next;}

template<typename T>
dqNode<T>* dqNode<T>::getPrev() const{return prev;}

template<typename T>
const T& dqNode<T>::getElem() const{return elem;} 


//Setters
template<typename T>
void dqNode<T>::setNext(dqNode<T>* N){next = N;}

template<typename T>
void dqNode<T>::setPrev(dqNode<T>* N){prev = N;}

template<typename T>
void dqNode<T>::setElem(const T& e){elem = e;}


template<typename T>
const T& Dequeue<T>::frontElem(){return front->getNext()->getElem();}

template<typename T>
const T& Dequeue<T>::backElem(){return back->getPrev()->getElem();}

template<typename T>
Dequeue<T>::Dequeue(){
    front=new dqNode<T>;
    back=new dqNode<T>;
    front->setNext(back);
    back->setPrev(front);
    size =0;
}

template<typename T>
int Dequeue<T>::getSize(){
    return size;
}

template<typename T>
bool Dequeue<T>::isEmpty(){
    if(front->getNext()==back)
        return true;
    else return false;
}

template<typename T>
void Dequeue<T>::addFront(const T& t){
    dqNode<T>* n = new dqNode<T>;
    n->setElem(t);
    front->getNext->setPrev(n);
    n->setPrev(front);
    n->setNext(front->getNext());
    front->setNext(n);
    size++;
}

template<typename T>
void Dequeue<T>::addBack(const T& t){
    dqNode<T>* n = new dqNode<T>;
    n->setElem(t);
    back->getPrev()->setNext(n);
    n->setPrev(back->getPrev());
    back->setPrev(n);
    n->setNext(back);
    size++;
}

template<typename T>
void Dequeue<T>::removeFront(){
    if(isEmpty()){
        return;
    }
    else{
        dqNode<T>* temp = front->getNext();
        front->setNext(temp->getNext());
        temp->getNext()->setPrev(front);
        size--;
        delete temp;
    }
}

template<typename T>
void Dequeue<T>::removeBack(){
    if(isEmpty()){
        return;
    }
    else{
        dqNode<T>* temp = front->getNext();
        temp->getNext()->setPrev(front);
        front->setNext(temp->getNext());
        temp->setNext(NULL);temp->setPrev(NULL);
        delete temp;
        size--;
    }
}

template<typename T>
Dequeue<T>::~Dequeue(){
    while(!isEmpty()){
        removeFront();
    }
    delete front;
    delete back;
}

#endif
