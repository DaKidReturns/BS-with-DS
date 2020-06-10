#include <iostream>
#include <vector>

class MaxHeap{
    private:
        std::vector<int> arr;
        int size;
        int max;
        void swap(int i, int j);
        void maxHeapify(int i);
        void buildMaxHeap();
    public:
        MaxHeap();
        int findMax() const;
        int extractMax();
        void insert(int& a); 
        const bool isEmpty() const;
        void printHeap() const;
};
void MaxHeap::swap(int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void MaxHeap::maxHeapify(int i){
    //assumes that the children are max heaps
    //check if the parent is less than the child
    //if not swap the  parent with the  child
    int leftChild,rightChild,largest;
    leftChild=2*i+1;
    rightChild=2*i+2;
    largest= i;
    //there will be one or two childeren we will check for the chidern in the
    //below if statements
    if(size>leftChild && arr[leftChild]>arr[largest])largest = leftChild;
    if(size>rightChild && arr[rightChild]>arr[largest])largest = rightChild;
    //If i is not the largest then swap them
    if(largest != i){
        //if the largest is not the parent than one of the child is larger
        //than the parent then you have to swap them
        swap(i,largest);
        //After swapping them check if the child node is still a min heap
        maxHeapify(largest);
    }
    
    return;
}

void MaxHeap::buildMaxHeap(){
    size = arr.size();
   //root of a heap is the first element i=0
   //left child is 2*i+1 and the right child is 2*i+2
   //for i from n/2 till 0 run  heapify (arr, i )
   //While calling heapify i is the root of the nearly complete binary tree to min heaped
    for(int i=size/2-1;i>=0;i--) 
           maxHeapify(i);
}

MaxHeap::MaxHeap(){
    size = 0;
}


void MaxHeap::printHeap() const{
    if(isEmpty()){std::cout<<"\nHeap is empty\n";return;}
    std::cout<<"\nHeap is\n";
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<'\n';
}

void MaxHeap::insert(int& a){
    arr.push_back(a);
    size++;
    buildMaxHeap();
}

const bool MaxHeap::isEmpty() const{
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

int MaxHeap::findMax() const{
    return arr[0];
}

int MaxHeap::extractMax(){
    int a = arr[0];
    swap(0,--size);
    arr.pop_back();
    maxHeapify(0);
    return a;
}

int main(){
    MaxHeap heap;
    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    int max = heap.extractMax();
    heap.printHeap();
    std::cout<<'\n';
    return 0;
}
