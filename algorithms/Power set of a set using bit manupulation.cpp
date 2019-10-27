//<pprockys>
//To print power set of a given set using bit manupulation;

#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;

int main() 
{
    lolo n;
    cin>>n;               //Number of elements of set;
    lolo a[n];
    for(lolo i=0;i<n;i++) //Elements of set;
    cin>>a[i];
    lolo j=1<<n;          //Total number of set in power set;
    
    //We will iterate from 0 to j-1 and for each j we will iterate from i=0 to n and see if
    //ith bit of j is set then we will print a[i];
    for(lolo k=0;k<j;k++)
    {   cout<<"{ ";
        for(lolo i=0;i<n;i++)
        if(k&(1<<i))
        cout<<a[i]<<" ";
        cout<<"}\n";
    }
	return 0;
}