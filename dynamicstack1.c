//Write a C program Dynamic implimentation of stack to perform peek and is empty Operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;


void peek(int);
void isEmpty();
void display();

int main()
{

        int n, ch;
        do 
        {
            printf("\n\nStack Menu\n1. peek \n2. isEmpty\n3. Display\n0. Exit");
            printf("\nEnter Choice 0-3? :");
            scanf("%d", &ch);
            switch (ch)
            {
                   case 1:
                           printf("\nEnter number ");
                           scanf("%d", &n);
                           peek(n);
                               break;
                  case 2:
                           printf("\nEnter number ");
                           scanf("%d", &n);
                            isEmpty();
                                   break;
                  case 3:
                          display();
                               break;
            }
                }while (ch !=0);
      }
      
 void peek(int item)
 {
      struct node *n = malloc(sizeof(struct node));
      n->data = item;
      n->next = top;
      top = n;
   }
   void isEmpty()
   {
   if(top == NULL)
   {
     printf("\n\nStack is empty ");
     }
     else
     {
     struct node *temp;
     temp = top;
     top = top->next;
     printf("\n\n%d deleted", temp->data);
     free(temp);
}
}
void display()
{
     struct node *temp
     temp = top;
     while (temp != NULL)
     {
        printf("\n%d peek ", temp->data);
        temp = temp->next;
        }
        }
        
             
