vi adj[N],depth(N),euler,tree(N),st(N,-1);
void dfs(ll u,ll parent,ll d){
    depth[u]=d;
    euler.pb(u);
    for(ll i=0;i<adj[u].size();i++){
        if(adj[u][i]!=parent){
            dfs(adj[u][i],u,d+1);
            euler.pb(u);
        }
    }
}
void build(ll node,ll start,ll end){
    if(start==end){
        tree[node]=start;
    }
    else{
        ll mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        ll index1=tree[2*node];
        ll index2=tree[2*node+1];
        if(depth[euler[index1]]<depth[euler[index2]]){
            tree[node]=index1;
        }
        else{
            tree[node]=index2;
        }
    }
}
ll query(ll node,ll start,ll end,ll l,ll r){
    if(r<start || end<l){
        return -1;
    }
    if(l<=start && r>=end){
        return tree[node];
    }
    ll mid=(start+end)/2;
    ll index1=query(2*node,start,mid,l,r);
    ll index2=query(2*node+1,mid+1,end,l,r);
    if(index2==-1){
        return index1;
    }
    else if(index1==-1){
        return index2;
    }
    else if(depth[euler[index1]]<depth[euler[index2]]){
        return index1;
    }
    else{
        return index2;
    }
}
ll lca(ll a,ll b){
    return euler[query(1,0,euler.size()-1,st[a],st[b])];
}
int main(){

    she_taught_me_to_code

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0,0);
    for(ll i=0;i<euler.size();i++){
        if(st[euler[i]]==-1){
            st[euler[i]]=i;
        }
    }
    depth[0]=0;
    build(1,0,euler.size()-1);
    ll a,b;
    cin>>a>>b;
    cout<<lca(a,b)<<endl;
}
