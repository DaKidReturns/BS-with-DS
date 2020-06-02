#include<iostream>

int sum(int* A,int i,int n){
    if (n==1)
        return A[i];
    return sum(A,i,n/2)+sum(A,i+n/2,n%2==0?n/2:n/2+1);
}

int main(){
   int A[] = {1,2,3,4,5,6};
   std::cout<<sum(A,0,6);
  return 0; 
}
