//<pprockys>
//https://www.codechef.com/problems/MSTQS

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll weight[2002][2002],changed[2002][2002];
struct Hash {
    size_t operator()(const pair<ll,ll> &x) const {
        return (size_t) x.first * 37U + (size_t) x.second;
    }
	size_t operator()(const vector<int> &v)const{
		size_t s = 0;
		for(auto &e : v)
			s ^= hash<int>()(e)+0x9e3779b9+(s<<6)+(s>>2);
		return s;
	}
}; 


bool comp(pair<ll,ll>&a,pair<ll,ll>&b)
{
    return weight[a.first][a.second]<weight[b.first][b.second];
    
}

ll find (ll pp[], ll a)
{
    if(pp[a] == a)
    return a;
    return pp[a] = find(pp,pp[a]);
}
 
bool Union (ll pp[], ll size[], ll a, ll b)
{
    a=find(pp,a);
    b=find(pp,b);
    if(a!=b)
    {
        if(size[a]<size[b])
        swap(a,b);
        pp[b]=a;
        size[a]+=size[b];
        return true;
    }
    return false;
}
 


int main()  
{
       ll t,n;
       ios_base::sync_with_stdio(false); 
       cin.tie(NULL); 
       cout.tie(NULL); 
       ll i,j;
       ll m,q;
       cin>>n>>m>>q;
       ll pp[n+1],size[n+1];
       vector<pair<ll,ll>>adj;
       unordered_set<pair<ll,ll>,Hash>mp;
       mp.reserve(32768);
       mp.max_load_factor(0.25);
       while(m--)
       {
           ll w;
           cin>>i>>j>>w;
           adj.push_back({i,j});
           weight[i][j]=changed[i][j]=w;
           swap(i,j);
           weight[i][j]=changed[i][j]=w;
       }
       for(ll i=0;i<=n;i++)
       {
         pp[i]=i;
         size[i]=1;
       }
       sort(adj.begin(),adj.end(),comp);
       vector<pair<ll,ll>>mst;
       ll ans=0;
       for(auto u=adj.begin();u!=adj.end();++u)
       {
          ll x=u->first;
          ll y=u->second;
          if(Union(pp,size,x,y))
          {
              ans+=weight[x][y];
              mst.push_back({x,y});
          }
       }
       while(q--)
       {
           ll x;
           cin>>x;
           if(x<3)
           {
               ll u,v;
               cin>>u>>v;
               if(x==2)
               {
                   changed[u][v]=weight[u][v];
                   pair<ll,ll>p(u,v);
                   if(mp.find(p)!=mp.end())
                   mp.erase(mp.find(p));
               }
               else
               {
                   changed[u][v]=0;
                   mp.insert({u,v});
               }
           }
           else
           {
               for(ll i=0;i<=n;i++)
               {
                  pp[i]=i;
                  size[i]=1;
               }
               ll result=0;
               for(auto u=mp.begin();u!=mp.end();++u)
               {
                   if(Union(pp,size,u->first,u->second))
                   continue;
               }
               for(auto u=mst.begin();u!=mst.end();++u)
               {
                  ll x=u->first;
                  ll y=u->second;
                  if(Union(pp,size,x,y))
                  {
                    result+=changed[x][y];
                  }
                }
                cout<<result<<"\n";
           }
       }
	return 0;
}
