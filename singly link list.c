//implement singly link list to perform insert at beginning , delete at beginning , search display operation, right a menu dynamic program
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
 };
struct node *start;
void insert_begin();
void delete_begin();
void print();

void main ()
{
    int ch=0;
    while(ch!=4)
    {
      printf("\nEnter the operation to be performed\n");
      printf("n1.Insert in the begining\n2.Delete from Beginning\n3.Show\n4.Exit\n");
         scanf("\n%d",&ch);
         switch(ch)
         {
               case 1:
               insert_begin();
               break;
               
                case 2:
                delete_begin();
                break;
                
                case 3:
                print();
                break;
                case 4:
                exit(0);
                break;
                default:
                  printf("Enter valid option");
           }
   }
}
void insert_begin()
{
        struct node *p;
        int value;
        p=(struct node *) malloc(sizeof(struct node *));
        if(p==NULL)
        {
              printf("\nList is Empty");
          }
          else
          {
             printf("\nEnter value\n");
             scanf("%d",&value);
             p->data=value;
             p->next=start;
             start=p;
        }
   }
   
   
void delete_begin()
{
   struct node *p;
   if(start==NULL)
   {
       printf("\nList is Empty\n");
       }
       else
       {
          p=start;
           start=p->next;
          free(p);
      }
  }
  
  void print()
  {
    struct node *p;
    p=start;
    if(p==NULL)
    {
         printf("Nothing to print");
    }
       else
       {
              printf("\nprinting values\n");
              while (p!=NULL)
              {
                    printf("\n%d",p->data);
                    p-p->next;
        }
   }
 }
 
