//<pprockys>
//https://www.spoj.com/problems/BLINNET/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll find(ll pp[],ll a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=find(pp,pp[a]);
}

void Union(ll pp[],ll size[],ll a,ll b)
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
ll kruskal(ll n,ll pp[],ll size[],vector<pair<ll,pair<ll,ll>>>adj)
{
    ll w=0,i=0;
    sort(adj.begin(),adj.end());
    for(auto j=adj.begin();j!=adj.end();j++)
    {
        ll u=find(pp,j->second.first);
        ll v=find(pp,j->second.second);
        if(u!=v)
        {
            w+=j->first;
            Union(pp,size,u,v);
        }
    }
    return w;
}
int main() {
    ll t,n;
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin>>t;
    ll i,j;
    while(t--)
    {
        cin>>n;
        ll pp[n+1],size[n+1];
        vector<pair<ll,pair<ll,ll>>>adj;
        for(i=1;i<=n;i++)
        {
            pp[i]=i;
            size[i]=1;
            string s;
            ll q;
            cin>>s;
            cin>>q;
            while(q--)
            {
                ll w;
                cin>>j>>w;
                adj.push_back({w,{i,j}});
            }
        }
        cout<<kruskal(n,pp,size,adj)<<"\n";
    }
	return 0;
}
