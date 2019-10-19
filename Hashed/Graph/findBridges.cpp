287 int n;
177 vi G[MAXN];
177 
319 bool vist[MAXN];
960 int tin[MAXN], low[MAXN];
960 
818 int T;
818 
577 void dfs(int v, int p = -1){
336 	vist[v] = 1;
651 	tin[v] = low[v] = T++;
441 	int ch = 0;
508 	for(int u : G[v]) if(u != p){
585 		if(vist[u]) low[v] = min(low[v], tin[u]);
984 		else{
454 			dfs(u, v);
207 			low[v] = min(low[v], low[u]);
916 			if(low[u] > tin[v])
916 				// (v,u) is bridge!
477 			if(low[u] >= tin[v] && p!=-1)
477 				// v is articulation point!
143 			ch++;
545 		}
554 	}
184 	if(p == -1 && ch > 1)
184 		// v is articulation point!
180 }
180 
747 void findBridges(){
719 	T = 0;
527 	ms(vist, 0);
990 	ms(tin,-1);
464 	ms(low,-1);
857 	FOR(i,0,n) if(!vist[i]) dfs(i); 
133 
-3558356495312506867
