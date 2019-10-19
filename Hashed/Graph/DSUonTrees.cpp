000 //Get the size of every subtree
981 int sz[MAXN];
578 void getsz(int v, int p){
269     sz[v]=1;
990     for(auto u : g[v])
218         if(u!=p){
406             getsz(u,v);
091             sz[v]+=sz[u];
353         }
039 }
039 //Must get size before running the dfs
039 
456 vi *vec[MAXN];
757 int cnt[MAXN];
120 void dfs(int v, int p, bool keep){
268     int mx=-1, bigC=-1;
513     for(auto u : g[v])
248         if(u != p && sz[u]>mx) 
196             mx=sz[u], bigC=u;
180     for(auto u : g[v])
996         if(u != p && u != bigC)
040             dfs(u,v,0);
969     if(bigC != -1)
759         dfs(bigC,v,1),vec[v]=vec[bigC]; 
468     else
233         vec[v] = new vi ();
581     vec[v]->pb(v);
401     cnt[ col[v] ]++;
760     for(auto u: g[v])
760         if(u != p && u != bigC)
606             for(auto x : *vec[u]){
935                 cnt[ col[x] ]++;
321                 vec[v]->pb(x);
790             }
790     //Here you can answer all the queries for node v
790     //Now cnt[c] contains the number of nodes with color c in v's subtree
696     if(!keep)
778         for(auto u : *vec[v])
038             cnt[ col[u] ]--;
038     
030 }
3378033857628442030
