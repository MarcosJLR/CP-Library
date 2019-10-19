675 int H[MAXN];
190 int anc[MAXN][MAXLOG]; // init -1
420 void dfs_pre_LCA(int v, int p = -1){
107 	anc[v][0] = p;
234 	if(p != -1) H[v] = H[p] + 1;
159 	else H[v]=0;
071 	FOR(i,1,MAXLOG) if(anc[v][i-1] != -1)
801 		anc[v][i] = anc[anc[v][i-1]][i-1];
118 	FOR(i,0,G[v].size()){
437 		int u=G[v][i];
668 		if(p != u) dfs_pre_LCA(u,v);
276 	}
513 }
513 
513 //Query:
083 int LCA(int u,int v){
604 	if(H[v] < H[u]) swap(v,u);
005 	FORR(i,MAXLOG-1,-1)
718 		if(anc[v][i] != -1 && H[anc[v][i]] >= H[u])
613 			v = anc[v][i];
013 	if(v == u) return v;
269 	FORR(i,MAXLOG-1,-1)
604 		if(anc[v][i] != anc[u][i])
002 			v = anc[v][i], u = anc[u][i];
023 	return anc[v][0];
735 
-5438168917153532265
