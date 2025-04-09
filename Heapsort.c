//write a program to sort n randomly generated elements using heapsort method.
#include<stdio.h>

void swap(int*a,int*b)
{
    int team=*a;
    *a=*b;
    *b=team;
 }
 
 void heapify(int arr[],int n,int i)
 {
     int left,right,largest;
     largest=i;
     left=2*i+1;
     right=2*i+2;
     
     // check if left child exists and is larger than its parent 
     if(left <n && arr[left]>arr[largest])
        largest = left;
        
      if(right<n && arr[right]>arr[largest])
          largest=right;
          
          
          if(largest !=i){
             swap(&arr[i],&arr[largest]);
             heapify(arr,n,largest);
    }
 }
 
 void heap_sort(int arr[],int n)
 {
      int i;
      for(i=(n/2)-1;i>=0;i--)
          heapify(arr,n,i);
          
       for(i=n-1;i>=0;i--){
          swap(&arr[0],&arr[i]);
          heapify(arr,i,0);
      }
}

int main()
{
    int arr[]={20,13,34,56,12,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    
    printf("Array:\n");
    for(i=0;i<n;i++)
        printf("%d",arr[i]);
        
        heap_sort(arr,n);
        
        printf("\nAfter performing Heap sort:\n");
        for(i=0;i<n;i++)
            printf("%d",arr[i]);
            
      return 0;
 }
 
