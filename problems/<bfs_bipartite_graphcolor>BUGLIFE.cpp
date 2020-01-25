//<pprockys>
//https://www.spoj.com/problems/BUGLIFE/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[100000];
bool odd_cycle(vector<ll>vec[],ll start,ll n)
{
    ll color[n+1];
    for(ll i=1;i<=n;i++)
    color[i]=-1;
    queue<ll>q;
    q.push(start);
    color[start]=1;
    while(q.size()!=0)
    {
        ll u=q.front();
        q.pop();
        visited[u]=true;
        for(ll i=0;i<vec[u].size();i++)
        {
            ll v=vec[u][i];
            if(color[u]==color[v])
            return true;
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
        }
    }
    return false;
}

int main()
{
    ll t=1,i,j,o;
    cin>>o;
    while(t<=o)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>vec[n+1];
        while(m--)
        {
            cin>>i>>j;
            vec[i].push_back(j);
            vec[j].push_back(i);
        }
        cout<<"Scenario #"<<t<<":\n";
        ll k=1;
        for(i=0;i<=n;i++)
        visited[i]=false;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==false&&odd_cycle(vec,i,n))
            {
                cout<<"Suspicious bugs found!"<<"\n";
                k=0;
                break;
            }
        }
        if(k)
        cout<<"No suspicious bugs found!"<<"\n";
        t++;
    }
}
