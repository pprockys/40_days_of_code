//<pprockys>
//https://www.spoj.com/problems/DAVIDG/


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll find(ll pp[], ll a)
{
    if(pp[a] == a)
    return a;
    return pp[a] = find(pp,pp[a]);
}
 
void Union (ll pp[], ll size[], ll a, ll b)
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
            w%mod;
            Union(pp,size,u,v);
            i++;
        } 
    }
    return w%mod;
}


int main() {
    ll t;
    cin>>t;
    ll i,j,n,d;
    ll o=1;
    while(o<=t)
    {
       cin>>n>>d;
       vector<ll>v[n+1];
       ll pp[n+1],size[n+1];
       for(i=1;i<=n;i++)
       {
           pp[i]=i;
           size[i]=1;
           ll k,l;
           cin>>k>>l;
           v[i].push_back(k);
           v[i].push_back(l);
       }
       vector<pair<ll,pair<ll,ll>>>adj;
       for(i=1;i<=n;i++)
       {
           for(j=i+1;j<=n;j++)
           {
               ll di;
               di=ceil(d*sqrt((v[i][0]-v[j][0])*(v[i][0]-v[j][0])+(v[i][1]-v[j][1])*(v[i][1]-v[j][1])));
               adj.push_back({di,{i,j}});
           }
       }
       cout<<"Scenario #"<<o<<": ";
       cout<<kruskal(n,pp,size,adj)<<"\n";
       o++;
    }
	return 0;
}
/*2

4 1

35 46

29 13

44 0

27 17

3 18

18 0

11 17

2 31*/
