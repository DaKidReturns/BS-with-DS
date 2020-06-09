#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int i,int j){
    if(i==j){return;}
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void heapify(std::vector<int>& arr,int i,int n){
    //assumes that the children are max heaps
    //check if the parent is less than the child
    //if not swap the  parent with the  child
    int leftChild,rightChild,largest;
    leftChild=2*i+1;
    rightChild=2*i+2;
    //We assume that the parent to be the largest element
    largest = i;
    if(leftChild<n && arr[leftChild]>arr[largest]){
        //if there is a left child then is it bigger than largest
        largest = leftChild;
    }
    if(rightChild<n && arr[largest]<arr[rightChild]){
        //if there is a right child then is it bigger than largest
        largest = rightChild;
    }
    if(largest!=i){
        //there is only a need to swap the parent and the child if any one of 
        //the child is greater than the parent
        swap(arr,i,largest);
        //we have to hepify the sub tree also
        heapify(arr,largest,n);
    }
    return;
}

void buildHeap(std::vector<int>& arr,int n){
   //root of a heap is the first element i=0
   //left child is 2*i+1 and the right child is 2*i+2
   //for i from n/2 till 0 run  heapify (arr, i )
   //While calling heapify i is the root of the nearly complete binary tree to max heaped
   for(int i=n/2-1;i>=0;--i)
       heapify(arr,i,n);

}

void heapSort(std::vector<int>& arr, int n,bool printArray=false){
    buildHeap(arr,n);
    if(printArray){
        std::cout<<"The max Heap is\n";
        for(int i=0;i<arr.size();i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<"\n";
    }
    for(int i=n-1;i>0;i--){
        swap(arr,0,i);
        if(printArray){
            std::cout<<"\nBefore Heapify \n";
            for(int i=0;i<arr.size();i++){
                std::cout<<arr[i]<<' ';
            }
        }
        heapify(arr,0,i);
        
        if(printArray){
            std::cout<<"\nAfter Heapify \n";
            for(int i=0;i<arr.size();i++){
                std::cout<<arr[i]<<' ';
            }
        } 
    }
}

int main(){
    std::vector<int> numbers({3,4,2,7,3,6,4,81,100,2,4,5,4,7,2});
    heapSort(numbers,numbers.size());
    for(int i=0;i<numbers.size();i++){
        std::cout<<numbers[i]<<' ';
    }
    std::cout<<'\n';
    return 0;
}
