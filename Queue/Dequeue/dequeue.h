#ifndef DEQUEUE_H 
#define DEQUEUE_H

template<typename T>
class dqNode{
    private:
        dqNode<T>* next;
        dqNode<T>* prev;
        T elem;
    public:
        //Getters
        dqNode* getNext() const;
        dqNode* getPrev() const;
        const T& getElem() const;
        //Setters
        void setNext(dqNode<T>* N);
        void setPrev(dqNode<T>* N);
        void setElem(const T& e);
};

template<typename T>
class Dequeue{
    private:
        dqNode<T>* front;
        dqNode<T>* back;
        int size;
    public:
        Dequeue();
        ~Dequeue();

        int getSize();
        bool isEmpty();
        void addFront(const T& t);
        void addBack(const T& t);
        void removeFront();
        void removeBack();
        const T& frontElem();
        const T& backElem();
};

#endif
