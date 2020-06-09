#include <iostream>
#include <vector>

void swap(std::vector<int>& arr, int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void heapify(std::vector<int>& arr,int i,int n){
    //assumes that the children are max heaps
    //check if the parent is less than the child
    //if not swap the  parent with the  child
    int leftChild,rightChild,largestChild;
    if(i<=n/2){
        //The above condition checks that the node checked has atleast
        //one child 
        leftChild=2*i+1;
        rightChild=2*i+2;
        //there will be one or two childeren
        if(n<=rightChild){
            //there is no right child
            //in that case the largest child is the left child
            largestChild=leftChild;
        }
        else{
            largestChild = arr[leftChild]<arr[rightChild]?rightChild:leftChild;
        }
        if(arr[largestChild]>arr[i]){
            //if the largest child is greater than the parent then swap them
            swap(arr,i,largestChild);
            heapify(arr,largestChild,n);
        }
    }
    return;
}

void buildHeap(std::vector<int>& arr,int n){
   //root of a heap is the first element i=0
   //left child is 2*i+1 and the right child is 2*i+2
   //for i from n/2 till 0 run  heapify (arr, i )
   //While calling heapify i is the root of the nearly complete binary tree to max heaped
   int i=n/2;
   while(i>=0){
    heapify(arr,i,n);
    i--;
   }
}

int main(){
    std::vector<int> numbers({1,7,6,3,5,3,6});
    buildHeap(numbers,numbers.size()-1);
    for(int i=0;i<numbers.size();i++){
        std::cout<<numbers[i]<<' ';
    }
    std::cout<<'\n';
    return 0;
}
