//<pprockys>
//Simple use of union find;
//Codeforces ::problem_link----https://codeforces.com/contest/25/problem/D

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
	vector<pair<lolo,lolo>>kt;     //vector to store roads that can be closed;
	for(i=1;i<nn;i++)
	{
	    cin>>m>>n;
	    find(pp,m)!=find(pp,n)?_union(pp,m,n):kt.pb(mp(m,n));
	}
	//I will check that whether it is possible to reach at each city from city 1;
	//If it is not possible to reach at any specific city from city 1 then i will
	//build one road b/w them;
	
	
	cout<<kt.size()<<"\n";
	for(i=2;i<=nn;i++)
	{
	    if(j==kt.size())
	    break;
	    if(find(pp,1)!=find(pp,i))
	    {
	        cout<<kt[j++].first<<" "<<kt[j].second<<" "<<"1 "<<i<<"\n";
	        _union(pp,1,i);
	    }
	}
	return 0;
}
