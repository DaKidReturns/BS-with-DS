#include<iostream>


/********** Function that implements insetion sort *******************/
/*O(n^2)*/

void insertionSort(int* arr,int n){ //Accept integer array and length of the array
	int i,j,cur;
	for(i = 1;i<n;i++){         //Iterate through every element
		cur = arr[i];       //select arr[i] as the current element
		for(j = i-1;(j>=0)&&(arr[j]>cur);--j){
			arr[j+1] = arr[j];
		}
		arr[j+1] = cur;
	}
}


int main(){
	int arr[] = {3,4,5,2,5,1,1,3,2,3,7,8,4,3};
	std::cout<<"Sorted array is\n";
	insertionSort(arr,14);
	for(int i =0;i<14;i++)
		std::cout<<arr[i]<<" ";
	std::cout<<'\n';
	return 0;
}
