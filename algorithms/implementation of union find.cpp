//<pprockys>
//Simple use of union find;

#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;
#define pb push_back
#define mp make_pair

//find function;
lolo find(lolo pp[],lolo a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=find(pp,pp[a]);
}

//union function;
void _union(lolo pp[],lolo a,lolo b)
{
    if(find(pp,a)!=find(pp,b))
    pp[find(pp,b)]=find(pp,a);
}
 
int main() {
	lolo nn,i,j=0,m,n;
	cin>>nn;
	lolo pp[nn+1];                 //array to store parent of each elements;
	for(i=1;i<=nn;i++)
	pp[i]=i;
	for(i=1;i<nn;i++)
	{
	    cin>>m>>n;
	    find(pp,m)!=find(pp,n)?_union(pp,m,n):continue;
	}
	return 0;
}