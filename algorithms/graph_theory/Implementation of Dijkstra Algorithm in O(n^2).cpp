    //<pprockys>
    //Implementation of Dijkstra Algorithm---O(n^2)
    int k=INT_MAX;
    int n=100;
    vector<vector<pair<int,int>>>adj(n+1);   
    vector<int>p(n+1,j);                   //vector to restore path
    vector<int>d(n+1,k);                  //distance vector
     
    void dj(int start)
    {
    
       bool v[n+1]={false};
       d[s]=0;
       for(int i=1;i<=n;i++)
       {
          int op=-1,x=k;
          for(lolo j=1;j<=n;j++)
          {
             if(d[j]<x&&v[j]==false)
             {
               x=d[j];
               op=j;
             }
          } 
          if(d[op]==k)
          break;
          v[op]=true;
          for(int g=0;g<adj[op].size();++g)
          {
             if(d[adj[op][g].first]>d[op]+adj[op][g].second)
             {
               p[adj[op][g].first]=op;
               d[adj[op][g].first]=d[op]+adj[op][g].second;
             }
           }
        }
    }
