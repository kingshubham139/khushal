//Q.2)Write a C program for isEmpty and isFull Operation in Stack 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5


int stack[N];
int top=-1,inp_array[N];
 void pop();
void push();
int peek();        
bool isEmpty();    
bool isFull();     
void show();
int main(){
    printf("STATIC ARRAY (Total Capacity: %d)\n", N);
    int choice;

    while(1){
        printf("\nChoose any of the following options:\n");
        printf(" 0: Exit  1: Peek\n");
        printf("2:push the element ");
        printf("3:pop the element");
        printf("4 : Check if the stack is empty ");  
        printf(" 5: Check if the stack is full\n");
         printf("6:show");
        scanf("%d", &choice);

        switch(choice){
            case 0: exit(0);
            case 1: peek(); break;
             case 2: push();break;
              case 3: pop();break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
              case 6:show();break;
            default: printf("Please choose a correct option!");
        }
    }
    return (0);
}
int peek(){
    int x = stack[top];
    printf("%d is the top most element of the stack\n", x);
    return x;
}
void push()
{
int x;
 if(top==N-1)
{
printf("\n stack is overflow!!");
}
else {
printf("\n enter element to be inserted in stack");
scanf("%d",&x);
top=top+1;
inp_array[top]=x;
}
}

void pop()
{
if(top==-1)
{
printf("\n stack is underflow !!");
}
else
{
printf("\n popped element: %d",inp_array[top]);
top=top-1;

}
  }

bool isEmpty(){
    if(top == -1){
        printf("Stack is empty: Underflow State\n");
;        return true;
    }
    printf("Stack is not empty\n");
    return false;
}

bool isFull(){
    if(top == N-1)
	{
        printf("Stack is full: Overflow State\n");
        return true;
   	}
    printf("Stack is not full\n");
    return false;
}
void show()
{
int i;
if(top==-1)
{
printf("\n stack is underflow !!");
}
else{
printf("\n elements present in the stack:\n");
for( i=top;i>=0;i--)

printf("%d\n",inp_array[i]);
}
}


