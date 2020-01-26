//<pprockys>
//https://www.spoj.com/problems/AKBAR/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t,i,j,k,l;
	cin>>t;
    while(t--)
    {
        ll n,m;
 	    cin>>n>>m>>k;
 	    vector<ll>adj[n+1];
 	    while(m--)
 	    {
 	        cin>>i>>j;
 	        adj[i].push_back(j);
 	        adj[j].push_back(i);
 	    }
 	    ll value[n+1];
        ll flag=0,u;
        ll ans[n+1]={0};
        bool visited[n+1]={false};
        ll level[n+1]={0};
 	    while(k--)
 	    { 
 	        ll sr,x;
 		    cin>>sr>>x;
 		    queue<ll>q;
    		q.push(sr);
     		visited[sr]=true;
	        if(ans[sr])
 	        flag=1;
 	        else
 	        ans[sr]=1;
 	        level[sr]=0;
 	    	while(flag==0&&!q.empty())
 		    {
 			   u=q.front();
 			   q.pop();
 			   visited[u]=true;
 		       for(i=0;i<adj[u].size();i++)
 			   {
 				  if(visited[adj[u][i]]==false)
 				  {
 					visited[adj[u][i]]=true;
                    level[adj[u][i]]=level[u]+1;
 					if(level[adj[u][i]]<=x)
 					{
 					    q.push(adj[u][i]);
 					    if(ans[adj[u][i]])
 					    {
 					        flag=1;
 					        break;
 					    }
 					    else
 					    ans[adj[u][i]]=1;
 					}
 				  }
 		      }
 			}
 	   }
 	   for(i=1;i<=n;i++)
 	   if(ans[i]==0)
 	   flag=1;
 	   if(flag==1)
 	   cout<<"No\n";
 	   else
       cout<<"Yes\n";
   }
}
