//<pprockys>
//https://www.codechef.com/problems/DIGJUMP


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bfs(vector<ll>digit[],string s)
{
    ll n=s.size();
    bool visited[n]={false};
    ll level[n]={0};
    queue<ll>q;
    ll u=0;
    q.push(u);
    visited[u]=true;
    while(q.size()!=0)
    {
        ll v=q.front();
        q.pop();
        ll k=s[v]-'0';
        for(ll i=0;i<digit[k].size();i++)
        {
            if(!visited[digit[k][i]])
            {
                visited[digit[k][i]]=true;
                level[digit[k][i]]=level[v]+1;
                q.push(digit[k][i]);
            }
        }
        digit[k].clear();
        if(v!=0&&!visited[v-1])
        {
            level[v-1]=level[v]+1;
            visited[v-1]=true;
            q.push(v-1);
        }
        if(v!=n-1&&!visited[v+1])
        {
            level[v+1]=level[v]+1;
            visited[v+1]=true;
            q.push(v+1);
        }
    }
    return level[n-1];
}
int main()
{
    ll i,j;
    string s;
    cin>>s;
    ll n =s.length();
    vector<ll>digit[10];
    for(i=0;i<n;i++)
    digit[s[i]-'0'].push_back(i);
    cout<<bfs(digit,s);
}
