#include<iostream>
#include <bits/stdc++.h>
#include <list> 
#include <iterator>
#include<cmath>
#include <stack> 
#include <vector>
using namespace std;
typedef long long ll;

#define loop(i,b) for(ll i=0;i<b;i++)

#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
int dfs(int n,vector<vector <int> > graph , int s,int d ){
//	std::fill(*mat, *mat + M*N, value);
	int ct=0;
		stack<int> st;
		int visited[n],i,j,k,flag;
		  rep(i,0,n){
		     	visited[i]=0;
		           }
		
	
		st.push(s);
		//start node 
		cout<<s<<endl;
		ct=ct+1;
		visited[s]=1;
	
		while(!st.empty()){
		int x=st.top();
		  
			flag=0;
			rep(i,0,n){
		
				
				if(graph[x][i]==1 and visited[i]==0) {
					
					if (i==d){
						//end node 
						cout<<d<<endl;
						return ct;
					
						
					}
					st.push(i);
					//visited nodes 
					cout<<i<<endl;
					ct=ct+1;
					
					visited[i]=1;
					flag=1;
					break;
													}
				
			
				}
			if(flag==0){
				st.pop();
			
			}
		
		}
	return 0;
}


int main()
{
	int n,i,j,x,s,d;
	cin>>n; 
    vector<vector<int> > vec( n , vector<int> (n, 0));
     
	loop(i,n){
		loop(j,n){
			cin>>x;
			vec[i][j]=x;
	   		}
    	}
		//0 is source  5 is destination
		x=	dfs(n,vec,0,5);
	
		cout<<"no of nodes between the sorce and desination are "<<x<<endl;	
		return 0;
}
