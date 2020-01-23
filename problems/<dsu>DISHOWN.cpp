//<pprockys>
#include<bits/stdc++.h>
using namespace std;
typedef long long lolo;
lolo par(lolo parent[],lolo a)
{
    if(parent[a]==a)
    return a;
    else
    {
        return parent[a]=par(parent,parent[a]);
    } 
}
void Union(lolo parent[],lolo value[],lolo a, lolo b)
{
    a=par(parent,a);
    b=par(parent,b);
    if(a!=b&&value[a]!=value[b])
    {
        if(value[a]<value[b])
         swap(a,b);
        parent[b]=a;
    }

}
int main()
{
    lolo n,m,i,j,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        lolo value[n+1],parent[n+1];
        for(i=1;i<=n;i++)
        {
            cin>>value[i];
            parent[i]=i;
        }
        lolo q;
        cin>>q;
        while(q--)
        {
           cin>>k;
           lolo u,v;
           if(k)
           {
               cin>>u;
               cout<<par(parent,u)<<"\n";
           }
           else
           {
               cin>>u>>v;
               if(par(parent,u)==par(parent,v))
               cout<<"Invalid query!\n";
               Union(parent,value,u,v);

           }
           

        }
    }
    
    
}
