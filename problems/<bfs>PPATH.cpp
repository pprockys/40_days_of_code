//<pprockys>

#include <bits/stdc++.h>
using namespace std;

vector<int>prime;
void list_of_prime()
{
    int i,j;
    int a[10009]={0};
    for(i=2;i<=10000;i++)
    {
        for(j=i*i;j<=10000;j+=i)
        if(j%i==0)
        a[j]=1;
    }
    for(i=1000;i<=9999;i++)
    if(!a[i])
    prime.push_back(i);
}

int main() {
    list_of_prime();
    vector<int>adj[10009];
    int t,i,j,k;
    sort(prime.begin(),prime.end());
    for(i=0;i<prime.size();i++)
    {
        for(j=i+1;j<prime.size();j++)
        {
            string x=to_string(prime[i]),y=to_string(prime[j]);
            k=0;
            for(int m=0;m<4;m++)
            if(x[m]!=y[m])
            k++;
            if(k==1)
            {
                adj[prime[i]].push_back(prime[j]);
                adj[prime[j]].push_back(prime[i]);
            }
        }
    }
    
	
	cin>>t;
	while(t--)
	{
	    int start,finish;
	    cin>>start>>finish;
	    int dist[10000]={0};
	    bool visited[10000]={false};
	    queue<int>q;
	    q.push(start);
	    int k=0;
	    while(!q.empty())
	    {
	        int u=q.front();
	        q.pop();
	        visited[u]=true;
	        for(i=0;i<adj[u].size();i++)
	        {
	            if(visited[adj[u][i]]==false)
	            {
	                visited[adj[u][i]]=true;
	                q.push(adj[u][i]);
	                dist[adj[u][i]]=dist[u]+1;
	                if(adj[u][i]==finish)
	                {
	                    k=1;break;
	                }
	         
	            }
	        }
	        if(k)
	        break;
	    }
	    cout<<dist[finish]<<"\n";
	}
	return 0;
}
