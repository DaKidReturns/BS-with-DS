#include<iostream>
#include<excption>

/*1) Create a static array with an initial capacity
 *2) Add elements to the underlying static array, keeping the track of the
 *   number of elemets
 *3) If adding anoter element will exceed the capacity, then create a  new 
 *   static array with twice the capacity and cpy the original elements
 * */

class DynamicArray<T>{
	private:
		int size=0; //
		T arr[size];
		int max_capacity = 0;
	public:
		DynamicArray(int N){
			this.max_capacity = N;
			this.size = 0;
		}


};
