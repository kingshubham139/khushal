Q.sort a random array of n integers in ascending order by using selection algorithm
#include<stdio.h>
int main()
{
     int arr[10]={6,12,0,18,11,99,55,45,34,2};
     int n=10;
     int i, j, min, swap;
     for (i=0;i<(n-1);i++)
       {
    min = i;
      for (j=i+1;j<n;j++)
         {
            if(arr[min] > arr[j])
              min = j;
        }
        if (min !=i)
     {
     swap = arr[i];
     arr[i] = arr[min];
     arr[min] = swap;
       }
       }
       for(i=0;i<n;i++)
       printf("%d\t", arr[i]);
       return 0;
       }
