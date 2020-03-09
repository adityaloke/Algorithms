#include <bits/stdc++.h>
#include <limits.h> 
#include <stdio.h> 
#include <queue>

using namespace std;
#define V 4
typedef long long ll;
void bfs(int graph[][V])
{   queue <int> q;
    int i ,j,src,x,f;
    int visited[V];
    vector <int> ans; //to store final ans
    ans.clear();
    for(i=0;i<V;i++)
        visited[i]=0;
                                                                    //initializing source=0
    src=0;
    ans.push_back(src);
    q.push(src);
    cout<<src<<" ";
    while(true)
    {
        x=q.size();                                               //start of each level
        if(x==0)
            break;
        f=q.front();                
        visited[f]=1;                                            //for every node add all the connected nodes in end of queue
        for(i=0;i<V;i++)
            if(graph[f][i]!=0 and visited[i]==0)              //if edge is present and node not present then push in queue
               { ans.push_back(i);
                 cout<<i<<" ";
                 q.push(i);
               }
                
        q.pop();                                                  //end of each level
        
    }
    
    
    
    
}
int main() {
	// your code goes here
 int graph[V][V] =     { { 0 ,1 ,1 ,0  }, 
                        { 1 ,0 ,0 ,1  }, 
                        { 1, 0, 0, 0  }, 
                        { 0 ,1 ,0, 0  } }; 
  
    bfs(graph); 
  
    return 0; 
}
//output:0 1 2 3
