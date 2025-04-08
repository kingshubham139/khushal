//Q.2)Write a C program for peek,is Empty and is Full Operation in stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 5

int top = 5;
int stack[N];
int peek();
bool isEmpty();
bool isFull();
int main(){
    printf("STATIC ARRAY (Total Capacity: %d)\n", N);
    int choice;
    
 while(1){
       printf("\nChoose any of the folowing operations:\n");
       printf(" 0: Exit 1: Peek\n");
       printf(" 2: Check if the stack is empty ");
       printf(" 3: Check if the stack is full\n");
       scanf("%d", &choice);
       
      switch(choice){
         case 0: exit(0);
         case 1: peek();break;
         case 2: isEmpty();break;
         case 3: isFull();break;
         default:printf("Please choose a correct option!");
         }
     }
      return (0);
}
int peek(){
      int x = stack[top];
      printf("%d is the top most element of the stack\n",x);
      return x;
 }
 
 bool isEmpty(){
         if(top == -1){
         printf("Stack is empty: Underflow State\n");
         return true;
    }
    printf("Stack is not full\n");
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
  
