//<pprockys>
//Implementation of union find;


//arr pp[] is to manage parent of elements;
//arr size[] is to store size of each disjoint set---initially 1 is stored;


//find function;
int find(int a)
{
    if(pp[a]==a)
    return a;
    return pp[a]=find(pp[a]);  //parent changes to the root parent while function returns;
}

//union function;
void union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
       if(size[a]<size[b])
       swap(a,b);
       pp[b]=a;            //we always attach set having smaller size with the set having larger size;
       size[a]+=size[b];
    }
}
