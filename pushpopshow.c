//(.2)Write a C program for push and pop Operation in Stack

#include<stdio.h>
#include<stdlib.h>

#define N 100

int top=-1,int_array[N];
void pop();
void push();
void show();

int main()
{
int choice;

while(1)
{
printf("\n operation perform by stack");
printf("\1.push the element\n2.pop the element\n3.show\n4.end");
printf("\nenter the choice");
scanf("%d",&choice);

switch(choice)
{
case 1: push();break;
case 2: pop();break;
case 3: show();break;
case 4: exit(0);
default: printf("\n invalid choice!!");
}
}
}
void push()
{
int x;
if(top==N-1)
{
printf("\n stack is overflow!!");
}
else {
printf("\nenter element to be insert in stack");
scanf("%d",&x);
top=top+1;
int_array[top]=x;
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
printf("\n popped element: %d" ,int_array[top]);
top=top-1;

}
}
void show()
{
int i;
if(top==-1)
{
printf("\n stack is underflow !!");
}
else{
printf("\n element present in the stack:\n");
for(i=top;i>=0;i--)

printf("%d\n",int_array[i]);
}
}


