#include<iostream>
#include<string>

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
	cursor =cursor->next;
}

void CLinkedList::add(const std::string& e){
	CNode* n = new CNode;
	n->elem = e;
	if(cursor!= NULL){
		n->next = n;
		cursor = n;
	}
	else{
		n->next = cursor->next;
		cursor->next = n;
	}
}

void CLinkedList::remove(){
	CNode* old = cursor->next;
	if(old == cursor) cursor = NULL;
	else cursor->next = old->next;
	delete old;
}
