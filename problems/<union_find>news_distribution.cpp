//<pprockys>
//problem_link--https://codeforces.com/contest/1167/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;
lolo find(lolo pp[],lolo a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=find(pp,pp[a]);
}
void unionn(lolo pp[],lolo a,lolo b,lolo size[])
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
    lolo nn,k,i,j,l,m,n,o,p;
    cin>>nn>>k;
    lolo pp[nn+1],size[nn+1],ans[nn+1]={0};
    for(i=1;i<=nn;i++)
    {
        pp[i]=i;
        size[i]=1;
    }
    while(k--)
    {
        cin>>p;
        if(!p)
        continue;
        if(p==1)
        {cin>>o;continue;}
        lolo a[p];
        for(i=0;i<p;i++)
        cin>>a[i];
        for(i=0;i<p-1;i++)
        unionn(pp,a[i],a[i+1],size);
    }
    for(i=1;i<=nn;i++)
    {
        ans[find(pp,i)]++;
    }
    for(i=1;i<nn+1;i++)
    cout<<ans[find(pp,i)]<<" ";
	return 0;
}
