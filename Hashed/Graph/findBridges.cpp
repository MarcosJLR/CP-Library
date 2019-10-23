818 int n;
664 vi G[MAXN];
664 
679 bool vist[MAXN];
292 int tin[MAXN], low[MAXN];
292 
471 int T;
471 
341 void dfs(int v, int p = -1){
204 	vist[v] = 1;
863 	tin[v] = low[v] = T++;
214 	int ch = 0;
005 	for(int u : G[v]) if(u != p){
800 		if(vist[u]) low[v] = min(low[v], tin[u]);
485 		else{
696 			dfs(u, v);
498 			low[v] = min(low[v], low[u]);
693 			if(low[u] > tin[v])
693 				// (v,u) is bridge!
480 			if(low[u] >= tin[v] && p!=-1)
480 				// v is articulation point!
724 			ch++;
986 		}
429 	}
852 	if(p == -1 && ch > 1)
852 		// v is articulation point!
099 }
099 
538 void findBridges(){
327 	T = 0;
651 	ms(vist, 0);
673 	ms(tin,-1);
094 	ms(low,-1);
947 	FOR(i,0,n) if(!vist[i]) dfs(i); 
464 
1580780464
