#include<iostream>
#include<string>

class Node{
	private:
		std::string elem;
		Node* next;
	friend class LinkedList;
};

class LinkedList{
	private:
		Node* head;
        int count;
	public:
		LinkedList();
		~LinkedList();
		bool empty() const;
        int size() const;
		const std::string& front() const;
		void addFront(const std::string& e);
		void removeFront();
        const std::string& penultimate() const; //Modified to return the second last item
};

LinkedList::LinkedList(){
	head = NULL;
    count = 0;
}

LinkedList::~LinkedList(){
	while(!(this->empty())) removeFront();
	std::cout<<"\nDone\n";
}

bool LinkedList::empty() const {
	if(head == NULL)
		return true;
	return false;
}

const std::string& LinkedList::front()const{
	if(!empty()){
		return head->elem;
   
    }
}

void LinkedList::addFront(const std::string& e){
	Node* ptr = new Node;
	ptr->elem= e;
	ptr->next = head;
	head = ptr;
    ++count;
}

void LinkedList::removeFront(){
	Node* ptr = head;
	head = head->next;
	delete ptr;
    --count;
}

int LinkedList::size() const{
    return count;
}

const std::string& LinkedList::penultimate() const{
    Node* N;
    while(!empty()&&head->next!=NULL){
        N = head;
        while(true){
            if (N->next->next==NULL){
                return N->elem;
            }
            else{
                N= N->next;
            }
        }
   }
}

int main(){
	LinkedList l;
    int ch,EXIT = 1;
	std::string str;
	std::cout<<"Linked List Implementation";
        while(EXIT)
	{
		std::cout<<"Enter a choice \n1.Insert an element\n2.Delete an element\n3.Is it empty?\n4.Print It\n5.Exit\n";
		std::cin>>ch;
		switch(ch){
			case 1:std::cout<<"Enter a string ";
			       std::cin>>str;
			       l.addFront(str);
			       break;
			case 2:l.removeFront();
			       break;
			case 3:if(l.empty()) std::cout<<"Yes";
				else std::cout<<"No";
				break;
			case 4: str = l.front();
				std::cout<<str;
				break;
			case 5: EXIT = 0;
                    break;
            case 6:std::cout<<l.penultimate();
                   break;
		}
	}
	std::cout<<"Exiting..........";
	return 0;
}
