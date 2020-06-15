#include "queue.cpp"
#include<iostream>

int main(){
    Queue<int> q;
    q.add(32);
    q.add(45);
    q.add(11);
    std::cout<<"Size of the queue is \n"<<q.getSize()<<'\n';
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.remove();
    std::cout<<"After removing one element :"<<'\n';
    std::cout<<"Size of the queue is \n"<<q.getSize()<<'\n';
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.remove();
    std::cout<<"After removing one element :"<<'\n';
    std::cout<<"Size of the queue is \n"<<q.getSize()<<'\n';
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.add(99);
    std::cout<<"After adding one element :"<<'\n';
    std::cout<<"Size of the queue is \n"<<q.getSize()<<'\n';
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.remove();
    std::cout<<"After removing one element :"<<'\n';
    std::cout<<"Size of the queue is \n"<<q.getSize()<<'\n';
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    return 0;
}
