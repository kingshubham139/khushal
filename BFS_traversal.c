//1)Write a c program the accepts the vertices and edges of a graph and stores it as an adjacency matrix.
//implement function to traverse the graph using breadth first search (BFS).traversal.
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

void bfs(int adj [MAX][MAX],int V ,int s){

   int q[MAX],front=0,rear=0;
   
      bool visited[MAX]={false};
      
      visited[s]=true;
      q[rear++]=s;
      
      while(front<rear){
      
          int curr = q[front++];
          printf("%d",curr);
          
          
          for(int i=0;i<V;i++){
              if (adj[curr][i]==1&& !visited[i]){
                  visited[i]=true;
                  q[rear++]=i;
            }
         }
      }
   }  
   
   
void addEdge(int adj[MAX][MAX],int u,int v){
     adj[u][v]=1;
     adj[v][u]=1;    // Undirectted graph
 }
 
 int main(){
 
     int V=5;
     int adj[MAX][MAX]={0};
     
     addEdge(adj,0,1);
     addEdge(adj,0,2);
     addEdge(adj,2,3);
     addEdge(adj,1,4);
     addEdge(adj,2,4);
     
     printf("BFS starting from 0:\n");
     bfs(adj,V,0);
     
     return 0;
     }
     
     
