// Write a program which uses binary search tree library and counts the total nodes and total 
//leaf nodes and total non leafs nodes in the tree.
#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node* left,*right;
};
struct node *newnode(int info)
{
struct node *node=(struct node*)malloc(sizeof(struct node));
node->info=info;
node->left=NULL;
node->right=NULL;
return(node);
}
static int count=0;
int countnodes(struct node*node)
{
if(node!=NULL)
{
countnodes(node->left);
count++;
countnodes(node->right);
}
return count;
}
unsigned int getLeafCount(struct node *node)
{
if(node==NULL)
return 0;
if(node->left==NULL && node->right==NULL)
return 1;
else
return getLeafCount(node->left)+
getLeafCount(node->right);
}
int nonleafnodes(struct node *node)
{
if(node!=NULL)
{
nonleafnodes(node->left);
if((node->left!=NULL) || (node->right!=NULL))
{
count++;
}
nonleafnodes(node->right);
}
return count;
}
int main()
{
struct node *node=newnode(1);
node->left=newnode(2);
node->right=newnode(3);
node->left->left=newnode(4);
node->left->right=newnode(5);
{
printf("NUmber of nodes in tree are \t%d",countnodes(node));
printf("\n");
count=0;
}
{
printf("Number of leaf nodes in tree are %d",getLeafCount(node));
printf("\n");
}
{
printf("Number of non-leaf nodes in tree are %d",nonleafnodes(node));
printf("\n");
count=0;
}
return 0;
}
