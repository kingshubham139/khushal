 // Write a program which uses binary search tree library and count the total node in the tree//
    #include <stdio.h>
    #include <stdlib.h>

    struct node
    {
      int info;
      struct node *left, *right;

    };

    struct node *createnode(int key)
      {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->info = key;
        newnode->left = NULL;
        newnode->right = NULL;

        return(newnode);
       }

    static int count = 0;
    int countnodes(struct node *root)

    {
      if(root != NULL)
      {
        countnodes(root->left);
        count++;
        countnodes(root->right);
      }
       return count;
     }

    int main()

    {

        struct node *newnode = createnode(25);

        newnode->left = createnode(27);

        newnode->right = createnode(19);

        newnode->left->left = createnode(17);

        newnode->left->right = createnode(91);

        newnode->right->left = createnode(13);

        newnode->right->right = createnode(55);


        printf("Number of nodes in tree 1 = %d ",countnodes(newnode));

        printf("\n");

        count = 0;
    }


