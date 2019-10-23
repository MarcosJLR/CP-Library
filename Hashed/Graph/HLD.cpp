332 int t; // Timer
520 int in[MAXN], out[MAXN], nxt[MAXN], sz[MAXN];
520  
438 void dfsSz(int v = 0, int p = -1){
267     sz[v] = 1;
688     for(auto &u : G[v]) if(u != p){
086         dfsSz(u);
153         sz[v] += sz[u];
530         if(sz[u] > sz[G[v][0]]) swap(u, G[v][0]);
385     }
219 }
704 void dfsHLD(int v = 0, int p = -1){
872     in[v] = t++;
457     for(auto u : G[v]) if(u != p){
916         nxt[u] = (u == G[v][0] ? nxt[v] : u);
140         dfsHLD(u);
632     }
834     out[v] = t;
415 }
415 // [in[v], out[v]) corresponds to v's subtree
415 // [in[nxt[v]], in[v]] path from v to last
415 // vertex in ascending heavy path
-1426492585
