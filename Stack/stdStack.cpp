#include<cstdio>
#include<stack>

int main(){
    std::stack<int> mystack;
    int ch;
    int elem;
    bool RUN = true;
    printf("STACK IMPLEMENTATION USING THE STANDARD LIBRARY FUNCTIONSN\n");    
    while(RUN){
        printf("-------Menu-------");
        printf("\n1.Insert\n");
        printf("2.Pop\n");
        printf("3.Is Empyt\n");
        printf("4.Top");
        printf("\nEnter Choice---> ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter the element to be inserted "); 
                   scanf("%d",&elem);
                   mystack.push(elem);
                   RUN = false;
                   printf("%d",mystack.top());
                   break;
            case 2:printf("Element poped is = %d\n",mystack.top());
                   mystack.pop();
                   break;
            case 3:if(mystack.empty()){
                        printf("Stack is empty\n");
                   }
                   else{
                        printf("Stack ain't empty\n");   
                   }
                   break;
            case 4:;
        }
    }
}
