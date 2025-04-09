//write a c program that accepts the verices edeges of a graps and store it as an adj.matrix impliment function to print indegree ,outdegree total degree of all vertices of graph.//

#include<stdio.h>
void main()
{
int m[10][10],r,c,sumin,sumout,n,v,i;
//clscr();
printf("How many vertices:");
scanf("%d",&n);
for(r=0;r<n;r++)
for(c=0;c<n;c++)
{
m[r][c]=0;
if(r!=c)
{
printf("is there an edge between vertices %d and %d (1/0):",r+1,c+1);
scanf("%d",&m[r][c]);
}}
printf("\n\nVertex\t Indegree\tOutdegree\t Total degree\n");
for(v=0;v<n;v++)
{
sumin=sumout=0;
for(i=0;i<n;i++)
{
sumin=sumout+m[i][v];
sumout=sumout+m[v][i];
}
printf("%d\t\t%d\t\t%d\t\t%d\n",v+1,sumin,sumout,sumin+sumout);
}
}
