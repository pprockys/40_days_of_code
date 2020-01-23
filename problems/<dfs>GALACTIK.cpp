//<pprockys>

//we will find minimum vale of vertex in each connected component and then ot of these minimum , we will take minimum of all the minimum
// and then add all minimm vertex to this vertex

#include<bits/stdc++.h>
using namespace std;
typedef long long lolo;
vector<lolo>adj[1000009];
bool visited[1000009]={false};
lolo mini=1000000000,minii=1000000000;
lolo value[1000009];
void dfs(lolo s)
{
    

        visited[s]=true;
        if(value[s]>=0&&value[s]<mini)
        mini=value[s];
        if(value[s]>=0&&value[s]<minii)
        minii=value[s];
        for(lolo i=0;i<adj[s].size();i++)
        if(visited[adj[s][i]]==false)
        dfs(adj[s][i]);
    
}
int main()
{
    lolo n,m,i,j,k;
    cin>>n>>m;
    while(m--)
    {
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    for(i=1;i<=n;i++)
    cin>>value[i];
    lolo sum=0,c=0,ok=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            c++;
            dfs(i);
            if(mini==1000000000)
            {ok=1;
            break;}
            sum+=mini;
            
            mini=1000000000;
        }
    }
    if(c==1)
    cout<<"0";
    
    else if(ok)
    cout<<"-1";
    else
    cout<<sum+(c-2)*minii;
}
