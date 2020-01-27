//<pprockys>
//https://www.spoj.com/problems/HIGHWAYS/

#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;
lolo k=LLONG_MAX;
 void dj(lolo n,lolo ss,vector<lolo>&p,vector<lolo>&d,vector<vector<pair<lolo,lolo>>>&adj)
    {
        
        bool v[n+1]={false};
        d[ss]=0;
        set<pair<lolo,lolo>>s;
        s.insert({0,ss});
        while(s.size()!=0)
        {
            int op=s.begin()->second;
            s.erase(s.begin());
            for(int g=0;g<adj[op].size();++g)
            {
               int u=adj[op][g].first;
               int w=adj[op][g].second;
               if(d[u]>d[op]+w)
               {
                   p[u]=op;
                   if(s.find({d[u],u})!=s.end())
                   s.erase({d[u],u});
                   d[u]=d[op]+w;
                   s.insert({d[u],u});
                }
            }
        }
    }
int main() {
    lolo t,n;
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin>>t;
    lolo i,j=0;
    while(t--)
    {
        lolo m,s,e;
        cin>>n>>m>>s>>e;
        vector<vector<pair<lolo,lolo>>>pp(n+1);
        while(m--)
        {
           lolo w;
           cin>>i>>j>>w;
           pp[i].push_back(make_pair(j,w));
           pp[j].push_back(make_pair(i,w));
        }
        j=0;
        vector<lolo>p(n+1,j);
    	vector<lolo>d(n+1,k);
        dj(n,s,p,d,pp);
        if(d[e]==k)
        cout<<"NONE\n";
        else
        cout<<d[e]<<"\n";
    }
	return 0;
}
