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
	protected:
		void add(Dnode*, const std::string);
		void remove(Dnode*);
};

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
	return 0;
}
