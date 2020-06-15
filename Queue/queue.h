#ifndef QUEUE_H 
#define QUEUE_H

template<typename T>
class qNode{
    private:
        qNode<T>* next;
        qNode<T>* prev;
        T elem;
    public:
        //Getters
        qNode* getNext() const;
        qNode* getPrev() const;
        const T& getElem() const;
        //Setters
        void setNext(qNode<T>* N);
        void setPrev(qNode<T>* N);
        void setElem(const T& e);
};

template<typename T>
class Queue{
    private:
        qNode<T>* front;
        qNode<T>* back;
        int size;
    public:
        Queue();
        ~Queue();

        int getSize();
        bool isEmpty();
        void add(const T& t);
        void remove();
        const T& frontElem();
        const T& backElem();
};

#endif
