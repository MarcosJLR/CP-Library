000 //Get the size of every subtree
591 int sz[MAXN];
375 void getsz(int v, int p){
479     sz[v]=1;
412     for(auto u : g[v])
530         if(u!=p){
583             getsz(u,v);
454             sz[v]+=sz[u];
823         }
908 }
908 //Must get size before running the dfs
337 vi *vec[MAXN];
070 int cnt[MAXN];
670 void dfs(int v, int p, bool keep){
859     int mx=-1, bigC=-1;
739     for(auto u : g[v])
386         if(u != p && sz[u]>mx) 
198             mx=sz[u], bigC=u;
126     for(auto u : g[v])
435         if(u != p && u != bigC)
484             dfs(u,v,0);
024     if(bigC != -1)
051         dfs(bigC,v,1),vec[v]=vec[bigC]; 
017     else
187         vec[v] = new vi ();
054     vec[v]->pb(v);
651     cnt[ col[v] ]++;
609     for(auto u: g[v])
749         if(u != p && u != bigC)
360             for(auto x : *vec[u]){
335                 cnt[ col[x] ]++;
974                 vec[v]->pb(x);
564             }
564     //Here you can answer all the queries for node v
564     //Now cnt[c] contains the number of nodes with color c in v's subtree
264     if(!keep)
608         for(auto u : *vec[v])
217             cnt[ col[u] ]--;
217     
870 }
1533303870
