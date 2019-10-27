//<pprockys>
//Counting number of inversion in a given array using merge sort;

#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;

//This function returns the number of inversion while merging the array;
lolo merging(lolo a[],lolo l,lolo mid,lolo r)
{
    lolo n1=mid-l,n2=r-mid+1,i,j,k=0,mm=0;
    lolo x[n1],y[n2];
    for(i=l;i<mid;i++)
    x[k++]=a[i];
    k=0;
    for(i=mid;i<=r;i++)
    y[k++]=a[i];
    i=0;j=0;k=l;
    while(i<n1&&j<n2)
    {
        if(x[i]>y[j])
        {
            mm+=n1-i;//Here we get the required inversion count;
            a[k++]=y[j++];
        }
        else
        a[k++]=x[i++];
    }
    while(i<n1)
    a[k++]=x[i++];
    while(j<n2)
    a[k++]=y[j++];
    return mm;
}

lolo mergesort(lolo a[],lolo l,lolo r)
{   lolo ans=0;
    if(l<r)
    {
        lolo mid=(r+l)/2;
        ans+=mergesort(a,l,mid);
        ans+=mergesort(a,mid+1,r);
        ans+=merging(a,l,mid+1,r);
    }
    return ans;
}

int main() {
	lolo n,i;
	cin>>n;
	lolo a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<mergesort(a,0,n-1);
	return 0;
}