//<pprockys>
//https://www.spoj.com/problems/MST/
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

int kruskal(int n,int pp[],int size[],vector<pair<int,pair<int,int>>>adj)
{
    int w=0,i=0;
    sort(adj.begin(),adj.end());
    for(auto j=adj.begin();j!=adj.end();j++)
    {
        int u=find(pp,j->second.first);
        int v=find(pp,j->second.second);
        if(u!=v)
        {
            w+=j->first;
            Union(pp,size,u,v);
        }
    }
    return w;
}


int main() {
	int n,m;
	cin>>n>>m;
	int pp[n+1],size[n+1];
	for(int i=0;i<=n;i++)
	{
	    size[i]=0;;
	    pp[i]=i;
	}
	vector<pair<int,pair<int,int>>> adj;
	while(m--)
	{
	    int u,v,w;
	    cin>>u>>v>>w;
	    adj.push_back({w,{u,v}});
	}
	cout<<kruskal(n,pp,size,adj);
	return 0;
}
