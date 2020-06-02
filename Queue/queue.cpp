#include "queue.h"

template<typename T>
class qNode{
    private:
        qNode* next;
        T elem;
    public:
        //Getters
        const qNode* getNext() const{return next;}
        const T& getElem() const{return elem;} 
        //Setters
        void setNext(qNode* N){next = N;}
        void setElem(const T& e){elem = e;}
};

template<typename T>
class queue{
    private:
        qNode
}
