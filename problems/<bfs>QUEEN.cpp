#include <bits/stdc++.h>
using namespace std;
int A[8]={-1,-1,-1,0,0,1,1,1};
int B[8]={-1,0,1,-1,1,-1,0,1};
int main() {
	int t,i,j,m,n;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    string a[1009];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    int dist[1009][1009];
	    pair<int,int>start,finish,point,temp;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            dist[i][j]=0;
	            if(a[i][j]=='S')
	            {
	                start.first=i;
	                start.second=j;
	                dist[i][j]=1;
	            }
	            else if(a[i][j]=='F')
	            {
	                finish.first=i;
	                finish.second=j;
	            }
	        }
	    }
	    queue<pair<int,int>>pp;
	    pp.push(start);
	    while(pp.size()!=0)
	    {
	       point=pp.front();
	       temp=point;
	       pp.pop();
	       int x=point.first,y=point.second;
	       for(i=0;i<8;i++)
	       {
	          x=point.first;
	          y=point.second;
	          x+=A[i];
	          y+=B[i];
	          while(x>=0&&y>=0&&x<n&&y<m&&a[x][y]!='X')
	          {
	              if(dist[x][y]==0)
	              {
	                  dist[x][y]+=dist[point.first][point.second]+1;
	                  temp.first=x;
	                  temp.second=y;
	                  pp.push(temp);
	              }
	              else if(dist[x][y]!=dist[point.first][point.second]+1)
	              break;
	              x+=A[i];
	              y+=B[i];
	          }
	       }
	    }
	    cout<<dist[finish.first][finish.second]-1<<"\n";
	}
	return 0;
}
