//<pprockys>
//https://www.codechef.com/problems/CHEFGAME

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=747474747;
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
    ll w=1,i=0;
    sort(adj.begin(),adj.end());
    for(auto j=adj.begin();j!=adj.end();j++)
    {
        ll u=find(pp,j->second.first);
        ll v=find(pp,j->second.second);
        if(u!=v)
        {
            j->first=(-1)*j->first;
            w=((w%mod)*(j->first%mod))%mod;
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
    while(t--)
    {
       cin>>n>>d;
       vector<ll>v[n+1];
       ll pp[n+1],size[n+1];
       for(i=1;i<=n;i++)
       {
           pp[i]=i;
           size[i]=1;
           for(j=0;j<d;j++)
           {
               ll k;
               cin>>k;
               v[i].push_back(k);
           }
       }
       vector<pair<ll,pair<ll,ll>>>adj;
       for(i=1;i<=n;i++)
       {
           for(j=i+1;j<=n;j++)
           {
               ll d=0;
               for(ll k=0;k<v[i].size();k++)
               {
                   d+=(v[i][k]-v[j][k])*(v[i][k]-v[j][k]);
               }
               if(d)
               adj.push_back({-d,{i,j}});
           }
       }
       cout<<kruskal(n,pp,size,adj)<<"\n";
    }
	return 0;
}
