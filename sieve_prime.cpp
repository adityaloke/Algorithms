#include <iostream>
#include <bits/stdc++.h>
#include <list> 
#include <iterator>
#include<cmath>
#include <vector>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i=a;i<b;i++)
int prime[1000000];//change number
void sieve_prime(int *prime,int n)
    {       //mark all odd no as primes initially skip all multiple of 2
            prime[2]=1;
            
            for(int i=3;i<=n;i+=2)
                prime[i]=1;
            for(ll i=3;i*i<=n;i+=2)
                {   //i<=sqrt(n)
                    if(prime[i]==1)
                        {
                            for(ll j=i*i;j<=n;j=j+i)
                                {
                                    //starting from i square to n
                                    prime[j]=0;
                                }
                        }
                }
return;
    }
int main(){

        int n=20;
        cin>>n;
       
        sieve_prime(prime,n);
        
        for(ll i=0;i<=n;i++)
                if(prime[i]==1)
                    cout<<i<<" ";
        
        return 0;
}