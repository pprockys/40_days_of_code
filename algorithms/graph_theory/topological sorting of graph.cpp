//<pprockys>
//topological sorting of graph;

void dfs(vector<int> &pp,vector<int> adj[],bool vis[],int s)
{
   vis[s]=true;
   for(auto j=adj[s].begin();j!=adj[s].end();j++)
   if(vis[*j]==false)
   dfs(pp,adj,vis,*j);
   pp.push_back(s);
}
void topoSort(int V, vector<int> adj[])
{
    bool vis[V+69]={false};
    vector<int> pp;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        dfs(pp,adj,vis,i);
    }
    for(int i=pp.size()-1;i>=0;i--)  //since I have used vector so print elements of 
    cout<<pp[i];                     //vector in reverse order to get topological sort; 
}