043 int t; // Timer
442 int in[MAXN], out[MAXN], nxt[MAXN], sz[MAXN];
442  
818 void dfsSz(int v = 0, int p = -1){
604     sz[v] = 1;
873     for(auto &u : G[v]) if(u != p){
740         dfsSz(u);
125         sz[v] += sz[u];
558         if(sz[u] > sz[G[v][0]]) swap(u, G[v][0]);
399     }
611 }
530 void dfsHLD(int v = 0, int p = -1){
106     in[v] = t++;
165     for(auto u : G[v]) if(u != p){
293         nxt[u] = (u == G[v][0] ? nxt[v] : u);
806         dfsHLD(u);
349     }
610     out[v] = t;
650 }
650 // [in[v], out[v]) corresponds to v's subtree
650 // [in[nxt[v]], in[v]] path from v to last
650 // vertex in ascending heavy path
6521306505178750650
