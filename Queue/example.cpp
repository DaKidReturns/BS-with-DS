#include "queue.cpp"
#include<iostream>

int main(){
    Queue<int> q;
    q.add(32);
    q.add(45);
    q.add(11);
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.remove();
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.remove();
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    q.remove();
    std::cout<<"Front Element "<<q.frontElem()<<'\n';
    std::cout<<"Back Element "<<q.backElem()<<'\n';
    return 0;
}
