#include<iostream>
#include<vector>
#include<cstring>

typedef std::vector<int>::iterator Iterator;
typedef std::vector<int>::const_iterator ConstIterator;

void reciveArray(std::vector<int> &a){
    int i,n;
    std::cout<<"Enter the number of elements in the array : ";
    std::cin>>n;
    a.resize(n);
    std::cout<<"Enter the elements of the array : ";
    for(i = 0;i<n;i++){
        std::cin>>a[i];
    }
    std::cout<<std::endl;
}

void printVector(const std::vector<int> &a){
    for(ConstIterator p = a.begin();p!=a.end();++p){
        std::cout<<*p<<' ';
    }
    std::cout<<std::endl;
}

void countingSort(std::vector<int> &a,int p,bool printSteps){
    //Here p is the place value of the MSD in the
    
    int len = a.size();
    int i;
    
    std::vector<int> c;
    std::vector<int> d;
    
    c.resize(10);
    d.resize(len);
    
    //assume that the value of k is 10
    for(i = 0;i<len;++i){
        c[(a[i]%p)/(p/10)]++;
    }
    
    if(printSteps){
    std::cout<<"The counting array c is : ";
    printVector(c);
    }

    
    //cumulative postions
    for(i=1;i<10;++i){
        c[i]+=c[i-1];
    }
    
    if(printSteps){
        std::cout<<"The cumulative position array c is : ";
        printVector(c);
    }
    
    
    //Sorting the vector b
    for(i=len-1;i>=0;--i){
        d[c[(a[i]%p)/(p/10)]-1] = a[i];
        c[(a[i]%p)/(p/10)]--;
        if(printSteps){
            std::cout<<"Array b after the " <<len-i<<" iteration = ";
            printVector(d);
        }
    }
    a=d;
    
}

void radixSort(std::vector<int> &a,bool printSteps){
    int largest = a[0];
    int i;
    int p =10; //Our base
    int len;

    len = a.size();
    for(i = 1; i<len ;++i){
        if(a[i]>largest){
            largest = a[i];
        }
    }

    while(largest>0){
        countingSort(a,p,printSteps);
        
        //std::cout<<"Array b is: ";
        //printVector(b);

        p*=10;
        largest/=10;
        if(printSteps)
            std::cout<<std::endl<<std::endl;
    }
}

int main(int args,char* argv[]){
    char c;
    bool print = false;
    std::vector<int> a;
    
    
    reciveArray(a);
    std::cout<<"Array created ";
    printVector(a);

    
    if(args<2){
        std::cout<<"Do you want to print the steps in the sorting process? (y/n) : ";
        std::cin>>c;
        if( c == 'y'||c=='Y'){
            print = true;
        }
        else{
            if(c == 'n'||c=='N'){
                print = false;
            }
            else{
                std::cout<<"Entered command is unknown the defaul option will be used instead "<<std::endl;
            }
        }
    }
    else{
        if(!strcmp(argv[1],"print")){
            print = true;
        }
        else{
            print  = false;
        }
    }

    
    radixSort(a,print);

    std::cout<<"Sorted Array is : ";
    printVector(a);
    return 0;
}
