    //<pprockys>
    //https://codeforces.com/contest/20/problem/C
    #include <bits/stdc++.h>
    using namespace std;
    typedef long long lolo;
    lolo k=LLONG_MAX;
     
    void dj(lolo n,lolo ss,vector<lolo>&p,vector<lolo>&d,vector<vector<pair<lolo,lolo>>>&adj)
    {
        
        bool v[n+1]={false};
        d[ss]=0;
        set<pair<lolo,lolo>>s;
        s.insert({0,1});
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
        lolo n,m,i,j=-1,l=0,w;
        cin>>n>>m;
        vector<vector<pair<lolo,lolo>>>pp(n+1);
    	vector<lolo>p(n+1,j);
    	vector<lolo>d(n+1,k);
        while(m--)
        {
            cin>>i>>j>>w;
            pp[i].push_back(make_pair(j,w));
            pp[j].push_back(make_pair(i,w));
        }
        i=1;
        dj(n,i,p,d,pp);
        if(p[n]!=-1)
        {   vector<lolo>lk;
            i=n;
            while(i!=1)
            {
                lk.push_back(i);
                i=p[i];
            }
            cout<<"1 ";
            for(i=lk.size()-1;i>=0;i--)
            cout<<lk[i]<<" ";
        }
        else
        cout<<"-1";
        return 0;
    }
