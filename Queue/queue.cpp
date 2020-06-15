#ifndef QUEUE_cpp
#define QUEUE_cpp
#include "queue.h"
#include <cstddef>

//Getters
template<typename T>
qNode<T>* qNode<T>::getNext() const{return next;}

template<typename T>
qNode<T>* qNode<T>::getPrev() const{return prev;}

template<typename T>
const T& qNode<T>::getElem() const{return elem;} 


//Setters
template<typename T>
void qNode<T>::setNext(qNode<T>* N){next = N;}

template<typename T>
void qNode<T>::setPrev(qNode<T>* N){prev = N;}

template<typename T>
void qNode<T>::setElem(const T& e){elem = e;}


template<typename T>
const T& Queue<T>::frontElem(){return front->getNext()->getElem();}

template<typename T>
const T& Queue<T>::backElem(){return back->getPrev()->getElem();}

template<typename T>
Queue<T>::Queue(){
    front=new qNode<T>;
    back=new qNode<T>;
    front->setNext(back);
    back->setPrev(front);
    size =0;
}

template<typename T>
int Queue<T>::getSize(){
    return size;
}

template<typename T>
bool Queue<T>::isEmpty(){
    if(front->getNext()==back)
        return true;
    else return false;
}

template<typename T>
void Queue<T>::add(const T& t){
    qNode<T>* n = new qNode<T>;
    n->setElem(t);
    back->getPrev()->setNext(n);
    n->setPrev(back->getPrev());
    back->setPrev(n);
    n->setNext(back);
    size++;
}

template<typename T>
void Queue<T>::remove(){
    if(isEmpty()){
        return;
    }
    else{
        qNode<T>* temp = front->getNext();
        temp->getNext()->setPrev(front);
        front->setNext(temp->getNext());
        temp->setNext(NULL);temp->setPrev(NULL);
        delete temp;
        size--;
    }
}

template<typename T>
Queue<T>::~Queue(){
    while(!isEmpty()){
        remove();
    }
    delete front;
    delete back;
}

#endif
