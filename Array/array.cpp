#include<iostream>

int main(){
	int N;
	std::cin>>N;
	int A[N];
	for(int i =0;i<N;i++) A[i] = i;
	for(int i =0;i<N;i++) std::cout<<A[i]<<"\n";
	std::cin>>N;
	
	return 0;
}
