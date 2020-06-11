#include <iostream>
#include <vector>

class MinHeap{
    private:
        std::vector<int> arr;
        int size;
        int max;
        void swap(int i, int j);
        void minHeapify(int i);
        void buildMinHeap();
    public:
        MinHeap();
        int findMin() const;
        int extractMin();
        void insert(const int& a); 
        const bool isEmpty() const;
        void printHeap() const;
};
void MinHeap::swap(int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void MinHeap::minHeapify(int i){
    //assumes that the children are Min heaps
    //check if the parent is less than the child
    //if not swap the  parent with the  child
    int leftChild,rightChild,smallest;
    leftChild=2*i+1;
    rightChild=2*i+2;
    smallest= i;
    //there will be one or two childeren we will check for the chidern in the
    //below if statements
    if(size>leftChild && arr[leftChild]<arr[smallest])smallest = leftChild;
    if(size>rightChild && arr[rightChild]<arr[smallest])smallest = rightChild;
    //If i is not the smallest then swap them
    if(smallest != i){
        //if the smallest is not the parent than one of the child is smaller
        //than the parent then you have to swap them
        swap(i,smallest);
        //After swapping them check if the child node is still a Min heap
        minHeapify(smallest);
    }
    
    return;
}

void MinHeap::buildMinHeap(){
    size = arr.size();
   //root of a heap is the first element i=0
   //left child is 2*i+1 and the right child is 2*i+2
   //for i from n/2 till 0 run  heapify (arr, i )
   //While calling heapify i is the root of the nearly complete binary tree to Min heaped
    for(int i=size/2-1;i>=0;i--) 
           minHeapify(i);
}

MinHeap::MinHeap(){
    size = 0;
}


void MinHeap::printHeap() const{
    if(isEmpty()){std::cout<<"\nHeap is empty\n";return;}
    std::cout<<"\nHeap is\n";
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<'\n';
}

void MinHeap::insert(const int& a){
    arr.push_back(a);
    size++;
    buildMinHeap();
}
/*
void MinHeap::insert(int a){
    arr.push_back(a);
    size++;
    buildMinHeap();
}
*/
const bool MinHeap::isEmpty() const{
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}

int MinHeap::findMin() const{
    return arr[0];
}

int MinHeap::extractMin(){
    int a = arr[0];
    swap(0,--size);
    arr.pop_back();
    minHeapify(0);
    return a;
}

int main(){
    MinHeap heap;
    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    int max = heap.extractMin();
    heap.printHeap();
    std::cout<<'\n';
    return 0;
}
