//Single source shortest path using greedy method  Dijkstra
#include <bits/stdc++.h>
#include <limits.h> 
#include <stdio.h> 
using namespace std;
#define V 9
typedef long long ll;
int find_mindistance(int distance[],bool visited[]){
    int index;
    int min=INT_MAX;
    
    for(int i=0;i<V;i++)
    {  
        if(distance[i]<=min and visited[i]==false)
            {
                min=distance[i];
                index=i;
            }
    }
    return index;
}
int printSolution(int distance[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, distance[i]); 
} 
void dijkstra(int graph[V][V],int src)
{   int i,u,v;
    bool visited[V];
    int distance[V];
    
    for(i=0;i<V;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
   
    distance[src]=0;
    
    for(i=0;i<V;i++)
    {
        u=find_mindistance(distance,visited);
       
        visited[u]=true;
        for(v=0;v<V;v++)
             if(graph[u][v] and visited[v]==false and  distance[u]+graph[u][v]<=distance[v])
                        distance[v]=distance[u]+graph[u][v];
                       
                  
        
    }
   printSolution(distance);
    
    
    
    
}
int main() {
	// your code goes here
 int graph[V][V] =     { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}
