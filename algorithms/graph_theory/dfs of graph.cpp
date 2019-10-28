//<pprockys>
//dfs of a graph;


//function of dfs;
void dfs(int s, vector<int> g[], bool vis[])
{
    cout<<s<<" ";
    vis[s]=true;
    for(auto j=g[s].begin();j!=g[s].end();j++)
    {
        if(vis[*j]==false)
        dfs(*j,g,vis);                        //recursive call for dfs on each node;
    }
}
