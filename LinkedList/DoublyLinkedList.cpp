#include<iostream>
#include<string>

class Dnode{
	private:
		std::string elem;
       		Dnode* next;
		Dnode* prev;
	 friend class DLinkedList;	
};


class DLinkedList{
	private:
		Dnode* header;
		Dnode* trailer;
	public:
		DLinkedList();
		~DLinkedList();
		bool empty() const;
		const std::string front() const;
		const std::string back() const;
		void addFront(const std::string&);
		void addBack(const std::string&);
		void removeFront();
		void removeBack();
        class Iterator;
        Iterator begin();
        Iterator end();
	protected:
		void add(Dnode*, const std::string);
		void remove(Dnode*);
};

class DLinkedList::Iterator{
    private:
        Dnode* v;
        Iterator(Dnode* u);
    public:
        std::string& operator*();
        bool operator==(const Iterator& p ) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();
        friend class DLinkedList;
};

DLinkedList::Iterator::Iterator(Dnode* u){v =u;}

std::string& DLinkedList::Iterator::operator*(){
    return v->elem;
}

bool DLinkedList::Iterator::operator==(const Iterator& p) const{
    return v==p.v;
}

bool DLinkedList::Iterator::operator!=(const Iterator& p) const{
    return v!=p.v;
}


DLinkedList::Iterator& DLinkedList::Iterator::operator++(){
    v=v->next;
    return *this;
}

DLinkedList::Iterator& DLinkedList::Iterator::operator--(){
    v = v->next;
    return *this;
}

DLinkedList::Iterator DLinkedList::begin(){
    return Iterator(header->next);
}

DLinkedList::Iterator DLinkedList::end(){
    return Iterator(trailer);
}

DLinkedList::DLinkedList(){
	header = new Dnode;
	trailer = new Dnode;
	header->next = trailer;
	trailer->prev = header;
}

DLinkedList::~DLinkedList(){
	while(!empty()) removeFront();
	delete header;
	delete trailer;
}

bool DLinkedList::empty() const{
	return (header->next == trailer);
}

const std::string DLinkedList::front() const{
	return header->next->elem;
}

const std::string DLinkedList::back() const{
	return trailer->prev->elem;
}


void DLinkedList::add(Dnode* D,const std::string e){
	Dnode* n = new Dnode;
	n->elem = e;
	D->next->prev = n;
	n->next = D->next;
	D->next = n;
	n->prev = D;
}

void DLinkedList::addFront(const std::string& e){
	add(header, e);
}

void DLinkedList::addBack(const std::string& e){
	add(trailer->prev, e);
}

void DLinkedList::remove(Dnode* D){
	Dnode* temp = D;
	D->next->prev = D->prev;
	D->prev->next = D->next;
	delete temp;
}

void DLinkedList::removeFront(){
	if(header->next !=trailer)
		remove(header->next);
}
void DLinkedList::removeBack(){
	if(trailer->prev != header)
		remove(trailer->prev);
}

void listReversal(DLinkedList& L){
	DLinkedList T;
	std::string s;
	while(!L.empty()){
		s= L.front();
		L.removeFront();
		T.addFront(s);
	}
	while(!T.empty()){
		s = T.front();
		T.removeFront();
		L.addBack(s);
	}

}
int main(){
	std::cout<<"Doubly Linked List impleentation\n";
    DLinkedList d;
    d.addFront("Rohit");
    d.addFront("Karunakaran");
    DLinkedList::Iterator it = d.begin();
    for(;it!=d.end();++it){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
	return 0;
}
