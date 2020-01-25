//<pprockys>
//https://www.spoj.com/problems/CAM5/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lolo;
lolo par(lolo pp[],lolo a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=par(pp,pp[a]);
}
void Union(lolo pp[],lolo size[],lolo a,lolo b)
{
    a=par(pp,a);
    b=par(pp,b);
    if(a!=b)
    {
        if(size[a]<size[b])
        swap(a,b);
        pp[b]=a;
        size[a]+=size[b];
    }
}
int main() {
	lolo t,nn,i,j,k,l,m,n,o;
	cin>>t;
	while(t--)
	{
	    cin>>nn;
	    lolo pp[nn],size[nn];
	    for(i=0;i<nn;i++)
	    {
	        pp[i]=i;
	        size[i]=1;
	    }
	    cin>>m;
	    while(m--)
	    {
	        cin>>i>>j;
	        Union(pp,size,i,j);
	    }
	    lolo b[nn]={0};
	    for(i=0;i<nn;i++)
	    b[par(pp,i)]++;
	    lolo sum=0;
	    for(i=0;i<nn;i++)
	    if(b[i])
	    sum++;
	    cout<<sum<<"\n";
	}
	return 0;
}
