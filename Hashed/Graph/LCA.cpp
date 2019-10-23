907 int H[MAXN];
158 int anc[MAXN][MAXLOG]; // init -1
685 void dfs_pre_LCA(int v, int p = -1){
130 	anc[v][0] = p;
796 	if(p != -1) H[v] = H[p] + 1;
837 	else H[v]=0;
333 	FOR(i,1,MAXLOG) if(anc[v][i-1] != -1)
318 		anc[v][i] = anc[anc[v][i-1]][i-1];
488 	FOR(i,0,G[v].size()){
621 		int u=G[v][i];
513 		if(p != u) dfs_pre_LCA(u,v);
603 	}
944 }
944 
944 //Query:
731 int LCA(int u,int v){
328 	if(H[v] < H[u]) swap(v,u);
838 	FORR(i,MAXLOG-1,-1)
459 		if(anc[v][i] != -1 && H[anc[v][i]] >= H[u])
908 			v = anc[v][i];
902 	if(v == u) return v;
904 	FORR(i,MAXLOG-1,-1)
946 		if(anc[v][i] != anc[u][i])
714 			v = anc[v][i], u = anc[u][i];
730 	return anc[v][0];
715 
-1467803285
