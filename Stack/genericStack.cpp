
template<typename E> class stack;

template<typename E> class stackNode{
    private:
        stackNode* prev;
        E elem;
    public:
        //GETTERS
        stackNode* getPrev(){return this->prev;}
        const E& getElem()const{return this->elem;}
        //SETTERS
        void setPrev(stackNode* N){this->prev = N;}
        void setElem(const E& elem){this->elem = elem;}
};


template<typename E> class stack{
    private:
        stackNode<E>* head;
    public:
        void push(const E&);
        bool empty()const;

};
