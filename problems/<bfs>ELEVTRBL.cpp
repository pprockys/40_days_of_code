<pprockys>
#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;
int main() {
	lolo total_floor,start,finish,up,down;
	cin>>total_floor>>start>>finish>>up>>down;
	if((start)==finish)
	{
	    cout<<"0";
	    return 0;
	}
	vector<lolo>adj[total_floor+9];
	lolo dist[total_floor+9]={0};
	bool visited[total_floor+9]={false};
	for(lolo i=1;i<=total_floor;i++)
	{
	    if(i+up<=total_floor)
	    adj[i].push_back(i+up);
	    if(i-down>0)
	    adj[i].push_back(i-down);
	    //adj[i].push_back(i);
	}
	queue<lolo>q;
	q.push(start);
	lolo k=0;
	while(q.size()!=0)
	{
	   lolo u=q.front();
	   visited[u]=true;
	   q.pop();
	   for(lolo i=0;i<adj[u].size();i++)
	   {
	       if(visited[adj[u][i]]==false)
	       {
	           visited[adj[u][i]]=true;
	           q.push(adj[u][i]);
	           dist[adj[u][i]]=dist[u]+1;
	       }
	       if(adj[u][i]==finish)
	       {
	           k=1;
	           break;
	       }
	   }
	   if(k)
	   break;
	}
	if(dist[finish])
	cout<<dist[finish];
	else
	cout<<"use the stairs";
	return 0;
}
