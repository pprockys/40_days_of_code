//<pprockys>
//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lolo;
/*
1*2
345
*67

0---
1---3 
2---5 
3---1 4 
4---6 3 5 
5---2 7 4 
6---4 7 
7---5 6

*/
void bfs(lolo n,lolo s,lolo d[],vector<lolo> adj[])
{
    bool v[n+1]={false};
    v[s]=true;
    for(lolo i=0;i<n+1;i++)
    d[i]=LLONG_MAX;
    d[s]=0;
    list<lolo>l;
    l.push_back(s);
    while(l.size()!=0)
    {
        lolo u=l.front();
        l.pop_front();
        for(auto i:adj[u])
        {
            if(v[i]==false)
            {
                v[i]=true;
                d[i]=d[u]+1;
                l.push_back(i);
            }
        }
    }
}


int main() 
{
	lolo n,m,i,j,q,x,y,u,v;
	cin>>n>>m>>q;
	string p[n+69];
	for(i=0;i<n;i++)
	cin>>p[i];
	cin>>x>>y;
	lolo k=0;
	lolo pk[n][m];
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	pk[i][j]=-1;
	for(i=0;i<n;i++)                                   //assign node number to each unoccupied cell
	{
	    for(j=0;j<p[i].length();j++)
	    {
	        if(p[i][j]!='*')
	        pk[i][j]=++k;
	    }
	}
	vector<lolo>adj[k+69];                              //graph
	for(i=0;i<n;i++)
	{
	    for(j=0;j<m;j++)
	    {
	        if(pk[i][j]!=-1)
	        {
	            if(i-1>=0&&pk[i-1][j]!=-1)
	            {
	                adj[pk[i][j]].push_back(pk[i-1][j]);
	            }
	            if(i+1<n&&pk[i+1][j]!=-1)
	            {
	                adj[pk[i][j]].push_back(pk[i+1][j]);
	            }
	            if(j-1>=0&&pk[i][j-1]!=-1)
	            {
	                adj[pk[i][j]].push_back(pk[i][j-1]);
	            }
	            if(j+1<m&&pk[i][j+1]!=-1)
	            {
	                adj[pk[i][j]].push_back(pk[i][j+1]);
	            }
	        }
	    }
	}
	n=k;
	lolo d[n+69];                    //array to store shortest path from starting cell to each cell if it is reachable
	lolo s=pk[x-1][y-1];
	bfs(n,s,d,adj);                  //bfs call to find shortest path
	while(q--)
	{
	    cin>>u>>v;
	    u--;v--;
	    if(p[u][v]=='*')              //if cell is occupied
	    {
	        cout<<"-1\n";
	        continue;
	    }
	    lolo kt=pk[u][v];
	    if(d[kt]!=LLONG_MAX)
	    cout<<d[kt]<<"\n";
	    else                          //if cell is unreachable
	    cout<<"-1\n";
	}
	return 0;
}
