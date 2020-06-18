#include<iostream>
#include<string>
#include<unistd.h>

class CNode{
	private:
		std::string elem;
		CNode* next;
	friend class CLinkedList;
};

class CLinkedList{
	private:
		CNode*  cursor;
	public:
		CLinkedList();
		~CLinkedList();
		bool empty() const;
		const std::string& front() const;
		const std::string& back() const;
		void advance();
		void add(const std::string& );
		void remove();
        void reverse();
        void printList();
};

CLinkedList::CLinkedList(){
	cursor = NULL;
}

CLinkedList::~CLinkedList(){
	while(!empty())
		remove();
}

bool CLinkedList::empty() const{
	return (cursor==NULL);
}

const std::string& CLinkedList::front() const{
	return cursor->next->elem;
}

const std::string& CLinkedList::back() const{
	return cursor->elem;
}

void CLinkedList::advance(){
	cursor=cursor->next;
}

void CLinkedList::add(const std::string& e){
	CNode* n = new CNode;
	n->elem = e;
	if(cursor== NULL){
		n->next = n;
	}
	else{
		n->next=cursor->next;
		cursor->next = n;
	}
	cursor = n;
}

void CLinkedList::remove(){
	if(!(this->empty())){
        CNode* old = cursor->next;
	    if(old == cursor) cursor = NULL;
	    else cursor->next = old->next;
	    delete old;
    }
}

void CLinkedList::reverse(){ //Uses high space
    if(this->empty()||cursor->next==cursor){
        return;
    }
    CNode* current=cursor->next;
    CNode* prev;
    CNode* nextNode=current->next;
    while(current!=cursor){
        prev = current;
        current = nextNode;
        nextNode = current->next;
        current->next = prev;
    }
    prev=current;
    current = nextNode;
    nextNode = current->next;
    current->next = prev;
    cursor = current;
    
}

void CLinkedList::printList(){
    CNode* start=cursor;
    this->advance();
    while(cursor!=start){
        std::cout<<cursor->elem<<" ";
        this->advance();
   }
    std::cout<<cursor->elem<<" ";
    std::cout<<std::endl;
}
