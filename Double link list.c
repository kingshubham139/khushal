//Empliment a double link list to performed insert at beginning & delete at beginning operation 
#include<stdio.h>
#include<stdlib.h>
struct  node
{
int data;
struct node *next;
};
struct node *start;
void insert_begin();
void delete_begin();
void search();
void print();
void main()
{
int ch=0;
while(ch!=4)
{
printf("\n Enter the operation to be performed\n");
printf("\n 1.Insert the beginning\n 2.Delete from beginning\n 3.Search\n 4.Show\n 5.Exit\n");
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
                search();
                break;
                
                case 4:
                print();
                break;
                
                case 5:
                exit(0);
                break;
                
default:
printf("Invalid option !!");
}
}
}
void insert_begin()
{
struct node *p;
int value;
p=(struct node *)malloc(sizeof(struct node *));
if(p==NULL)
{
printf("\nList is empty");
}
else
{
printf("\n Enter value :\n");
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
printf("\n List is empty");
}
else
{
p=start;
start=p->next;
free(p);
}
}
void search()
{
struct node *p;
int item,i=0,flag;
p=start;
if(p==NULL)
{
printf("\n Empty list\n");
}
else
{
printf("\n Enter element which you want to be searched:");
scanf("%d",&item);
while(p!=NULL)
{
if(p->data==item)
{
printf("item found at location %d",i+1);
flag=0;
}
else
{
flag=1;
}
i++;
p=p->next;
}
if (flag==1)
{
printf("item not found\n");
}
}
}
void print()
{
struct node *p;
p=start;
if (p==NULL)
{
printf("Nothing to print");
}
else
{
printf("\n printing values\n");
while(p!=NULL)
{
printf("\n%d",p->data);
p=p->next;
}
}
}
