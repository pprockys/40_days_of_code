//<pprockys>
//BFS of a graph;

void bfs(int start, vector<int> adj[], bool vis[], int N)
{
    list<int>pp;   
    pp.push(start);
    cout<<start<<" ";
    vis[start]=true;
    while(pp.size()!=0)
    {
        int p=pp.front();
        for(int i=0;i<adj[p].size();i++)
        {
            if(vis[adj[p][i]]==false)
            {
                cout<<adj[p][i]<<" ";
                pp.push_back(adj[p][i]);
                vis[adj[p][i]]=true;
            }
        }
        pp.pop_front();
    }
}
   
