//Get the size of every subtree
int sz[MAXN];
void getsz(int v, int p){
    sz[v]=1;
    for(auto u : g[v])
        if(u!=p){
            getsz(u,v);
            sz[v]+=sz[u];
        }
}
//Must get size before running the dfs

vi *vec[MAXN];
int cnt[MAXN];
void dfs(int v, int p, bool keep){
    int mx=-1, bigC=-1;
    for(auto u : g[v])
        if(u != p && sz[u]>mx) 
            mx=sz[u], bigC=u;
    for(auto u : g[v])
        if(u != p && u != bigC)
            dfs(u,v,0);
    if(bigC != -1)
        dfs(bigC,v,1),vec[v]=vec[bigC]; 
    else
        vec[v] = new vi ();
    vec[v]->pb(v);
    cnt[ col[v] ]++;
    for(auto u: g[v])
        if(u != p && u != bigC)
            for(auto x : *vec[u]){
                cnt[ col[x] ]++;
                vec[v]->pb(x);
            }
    //Here you can answer all the queries for node v
    //Now cnt[c] contains the number of nodes with color c in v's subtree
    if(!keep)
        for(auto u : *vec[v])
            cnt[ col[u] ]--;
    
}
