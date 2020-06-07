#include<iostream>
#include<vector>
int ITERCOUNT = 0;
void fingerThing(std::vector<int>& arr,int last,int begin,int mid);
void mergeSort(std::vector<int>& arr,int begin, int last){ 
    //std::cout<<"In merge sort"<<'\n';
    int mid; 
    mid = (begin+last)/2;
    if(begin<last){
      //mid = (begin+last)/2;
      mergeSort(arr,begin,mid);
      mergeSort(arr,mid+1,last);
      fingerThing(arr,begin,mid,last);
    } 
    ITERCOUNT++;
    std::cout<<"Iteration "<<ITERCOUNT;
    std::cout<<"\n----------------------------\n";
    std::cout<<"Value of begin = "<<begin<<'\n';
    std::cout<<"Value of last = "<<last<<'\n';
    std::cout<<"Value of mid = "<<mid<<'\n';
    for(int i = begin;i<=last;i++){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<"\n\n";
    return;
}
void fingerThing(std::vector<int>& arr ,int begin,int mid,int last){
    //std::cout<<"In pointer sort \n";
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
    for(int i = 0;i<temp.size();i++){
        arr[begin+i] = temp[i];
    }
    std::cout<<"Changed "<<begin+temp.size()-1<<" elements\n";
    
    return;
}


int main(){
    std::vector<int> spy({7,4,3,8,0,2,4,3,2});   
    for(auto it=spy.begin();it!=spy.end();++it){
        std::cout<<*it<<' '; 
    }
    std::cout<<'\n';
   mergeSort(spy,0,spy.size()-1);
    for(auto it=spy.begin();it!=spy.end();++it){
        std::cout<<*it<<' '; 
    }
    std::cout<<"\nTotal of "<<ITERCOUNT<<" iterations taken \n";
    return 0;
    }
