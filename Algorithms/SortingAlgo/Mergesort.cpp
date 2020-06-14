#include<iostream>
#include<vector>
int ITERCOUNT = 0;
void fingerThing(std::vector<int>& arr,int last,int begin,int mid);
void mergeSort(std::vector<int>& arr,int begin, int last,bool printArray = false){ 
    //std::cout<<"In merge sort"<<'\n';
    int mid; 
    mid = (begin+last)/2;
    if(begin<last){
      mergeSort(arr,begin,mid,printArray);
      mergeSort(arr,mid+1,last,printArray);
      fingerThing(arr,begin,mid,last);
    } 
    ITERCOUNT++;
    if(printArray){
        std::cout<<"Iteration "<<ITERCOUNT;
        std::cout<<"\n----------------------------\n";
        std::cout<<"Value of begin = "<<begin<<'\n';
        std::cout<<"Value of last = "<<last<<'\n';
        std::cout<<"Value of mid = "<<mid<<'\n';
        for(int i = begin;i<=last;i++){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<"\n\n";
    }
    return;
}
void fingerThing(std::vector<int>& arr ,int begin,int mid,int last){
    if(last==begin){
        return; 
    }
    int b=begin,c=mid+1;
    std::vector<int> temp;
    while(b<=mid&&c<=last){
        if(arr[b]<arr[c]){
            temp.push_back(arr[b]);
            b++;
        }
        else{
            temp.push_back(arr[c]);
            c++;
        }
    }
    while(b<=mid){temp.push_back(arr[b++]);}
    while(c<=last){temp.push_back(arr[c++]);}
    return;
}


int main(){
    std::vector<int> spy;   
    int n;
    int a;
    bool printArray;
    char input;
    std::cout<<"Welcome to Megre sort implementation\n";
    std::cout<<"Enter the number of elements in the array\n";
    std::cin>>n;
    std::cout<<"Enter the elements in the array\n";    
    a = readE
    std::cout<<'\n';
    std::cout<<"Do you want to print each iteration of the Merge Sort? (y/n) ";
    std::cin>>input;
    for(auto it=spy.begin();it!=spy.end();++it){
        std::cout<<*it<<' ';
    }
    if(input == 'y'|| input == 'Y')printArray = true;
    else printArray = false;
   mergeSort(spy,0,spy.size()-1,printArray);
    for(auto it=spy.begin();it!=spy.end();++it){
        std::cout<<*it<<' ';
    }
    return 0;
    }
