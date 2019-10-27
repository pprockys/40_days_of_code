//<pprockys>
//BFS of a graph;

void bfs(int start, vector<int> adj[], bool vis[], int N)
{
    stack<int>pp;   
    pp.push(s);
    cout<<start<<" ";
    vis[s]=true;
    while(pp.size()!=0)
    {
        int p=pp.top();
        for(int i=0;i<adj[p].size();i++)
        {
            if(vis[adj[p][i]]==false)
            {
                cout<<adj[p][i]<<" ";
                pp.push(adj[p][i]);
                vis[adj[p][i]]=true;
            }
        }
        pp.pop();
    }
}
   