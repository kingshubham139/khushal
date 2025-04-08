    #include <stdio.h>        
    struct node{  
        int data;  
        struct node *previous;  
        struct node *next;  
    };      
       
      struct node *head, *tail = NULL;  
       
      void addNode(int data) {  
      struct node *newNode = (struct node*)malloc(sizeof(struct node));  
        newNode->data = data;  
          
        
        if(head == NULL) {  
     
            head = tail = newNode;  
            head->previous = NULL;  
            tail->next = NULL;  
        }  
        else {  
             
            tail->next = newNode;  
            newNode->previous = tail;  
            tail = newNode;    
            tail->next = NULL;  
        }  
    }  
       
   
    void reverse() {  
        struct node *current = head, *temp = NULL;  
          
        //Swap the previous and next pointers of each node to reverse the direction of the list  
        while(current != NULL) {  
            temp = current->next;  
            current->next = current->previous;  
            current->previous = temp;  
            current = current->previous;  
        }  
        //Swap the head and tail pointers.  
        temp = head;  
        head = tail;  
        tail = temp;  
    }  
       
    void display() {   
        struct node *current = head;  
        if(head == NULL) {  
            printf("List is empty\n");  
            return;  
        }  
        while(current != NULL) {  
            //Prints each node by incrementing pointer.  
            printf("%d ", current->data);  
            current = current->next;  
        }  
    }  
       
    int main()  
    {  
        //Add nodes to the list  
        addNode(1);  
        addNode(2);  
        addNode(3);  
        addNode(4);  
        addNode(5);  
          
        printf("Original List: \n");  
        display();  
          
        //Reverse the given list  
        reverse();  
          
        //Displays the reversed list  
        printf("\nReversed List: \n");  
        display();  
       
        return 0;  
    }  
