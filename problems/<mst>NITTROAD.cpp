//<pprockys>
//https://www.spoj.com/problems/NITTROAD/


#include <bits/stdc++.h>
using namespace std;
int find(int pp[],int a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=find(pp,pp[a]);
}

void Union(int pp[],int size[],int a,int b)
{
    a=find(pp,a);
    b=find(pp,b);
    if(a!=b)
    {
        if(size[a]<size[b])
        swap(a,b);
        pp[b]=a;
        size[a]+=size[b];
    }
}

int main() {
    int t;
    cin>>t;
    int i,j;
    while(t--)
    {
        int n,q;
    	cin>>n;
        int pp[n+1],size[n+1];
	    for(int i=0;i<=n;i++)
	    {
	       size[i]=1;
	       pp[i]=i;
    	}
        vector<pair<int,int>>p;
        for(int k=1;k<=n-1;k++)
        {
            cin>>i>>j;
            p.push_back(make_pair(i,j));
        }
        cin>>q;
        stack<int>s;
        bool removed[n]={false};
        while(q--)
        {
            char po;
            cin>>po;
            if(po=='R')
            {
                cin>>i;
                s.push(i-1);
                removed[i-1]=true;
            }
            else
            {
               s.push(-1); 
            }
        }
        int count=(n*(n-1))/2;
        for(i=0;i<n-1;i++)
        if(!removed[i])
        {
            count-=(size[find(pp,p[i].first)]*size[find(pp,p[i].second)]);
            Union(pp,size,p[i].first,p[i].second);
        }
        
        stack<int>result;
        while(s.size()!=0)
        {
            int u=s.top();
            s.pop();
            if(u==-1)
            {
                result.push(count);
            }
            else
            {
                count-=(size[find(pp,p[u].first)]*size[find(pp,p[u].second)]);
                Union(pp,size,p[u].first,p[u].second);
            }
        }
        while(result.size()!=0)
        {
            cout<<result.top()<<"\n";
            result.pop();
        }
        cout<<"\n";
    }
	
	return 0;
}
