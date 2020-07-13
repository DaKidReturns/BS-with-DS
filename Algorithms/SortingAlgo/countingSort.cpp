#include<vector>
#include<iostream>

typedef std::vector<int>::iterator Iterator;
typedef std::vector<int>::const_iterator ConstIterator;
void printVector(const std::vector<int>& a){
    //std::cout<<std::endl;
    for(ConstIterator c = a.begin();c!=a.end();++c){
        std::cout<<*c<<' ';
    }
    std::cout<<std::endl;
}

//counting sort funtion
void countingSort(std::vector<int>& a){
        Iterator p;
        std::vector<int> c;
        std::vector<int> b = a;
        std::cout<<"Vector b = ";
        printVector(b);
        int k = a[0]+1;
        int len=a.size();
        std::cout<<"Initialized all the variables"<<std::endl; 
        //finding the value of k
        for(Iterator p=a.begin()+1;p!=a.end();++p){
            if(*p>k){
               k = *p+1;
            }
        }
        std::cout<<"Found the value of k as "<<k<<std::endl;
        c.resize(k);
        for(int i = 0;i<len;++i){
            //std::cout<<"Iteration "<<i<<std::endl;
            c[a[i]] += 1;
        }
        
        std::cout<<"Created the position vector "<<std::endl;
        printVector(c);
        for(int i=1;i<k;++i){
            c[i]+=c[i-1];
        }

        std::cout<<"Created the positions of all the values "<<std::endl;
        printVector(c);
        for(int i=len-1;i>=0;--i){
            a[c[b[i]]-1] = b[i];
            c[b[i]]-=1;
            printVector(a);
        }
        std::cout<<"Sorted array created "<<std::endl;

}

int main(){
    std::vector<int> a ={1,2,4,2,8,4,2,5};
    countingSort(a);
    for (Iterator p = a.begin();p !=a.end();++p) {
        std::cout<<*p<<' ';
    } 
    std::cout<<std::endl;
    return 0;
}
