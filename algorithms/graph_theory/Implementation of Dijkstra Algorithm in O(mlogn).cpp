     //<pprockys>
    //Implementation of Dijkstra Algorithm---O(mlogn)
    int k=INT_MAX;
    int n=100;
    vector<vector<pair<int,int>>>adj(n+1);   
    vector<int>p(n+1,j);                   //vector to restore path
    vector<int>d(n+1,k);                  //distance vector
     
    void dj(int start)
    {
        
        bool v[n+1]={false};        //boolean visited vector
        d[start]=0;
        set<pair<int,int>>s;    //set to access node with minimum distance
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
