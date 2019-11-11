//<pprockys>
//http://codeforces.com/contest/17/problem/B

#include <bits/stdc++.h>
using namespace std;
int find(int pp[],int a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=find(pp,pp[a]);
}

void Union(int pp[],int size[],int a,int b)
{
    a=find(pp,a);
    b=find(pp,b);
    if(a!=b)
    {
        if(size[a]<size[b])
        swap(a,b);
        pp[b]=a;
        size[a]+=size[b];
    }
}

int kruskal(int n,int q[],int pp[],int size[],vector<pair<int,pair<int,int>>>adj)
{
    int w=0,i=0;
    sort(adj.begin(),adj.end());
    bool vis[n+1]={false};
    for(auto j=adj.begin();j!=adj.end();j++)
    {
        int u=find(pp,j->second.first);
        int v=find(pp,j->second.second);
        if(u!=v&&q[find(pp,u)]>q[find(pp,v)]&&!vis[pp,j->second.second])
        {
            w+=j->first;
            Union(pp,size,u,v);
            i++;
            vis[pp,j->second.second]=true;
        }
        if(i==n-1)
        return w;
    }
  
    return -1;
}


int main() {
	int n,m;
	cin>>n;
	int q[n+1];
	for(int i=1;i<=n;i++)
	cin>>q[i];
	int pp[n+1],size[n+1];
	for(int i=0;i<=n;i++)
	{
	    size[i]=0;;
	    pp[i]=i;
	}
	vector<pair<int,pair<int,int>>>adj;
	cin>>m;
	if(m==0)
	{
	    if(n==1)
	    cout<<"0";
	    else
	    cout<<"-1";
	    return 0;
	}
	while(m--)
	{
	    int u,v,w;
	    cin>>u>>v>>w;
	    adj.push_back({w,{u,v}});
	}
	cout<<kruskal(n,q,pp,size,adj);
	return 0;
}
