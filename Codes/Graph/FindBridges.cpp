int n;
vi G[MAXN];

bool vist[MAXN];
int tin[MAXN], low[MAXN];

int T;

void dfs(int v, int p = -1){
	vist[v] = 1;
	tin[v] = low[v] = T++;
	int ch = 0;
	for(int u : G[v]) if(u != p){
		if(vist[u]) low[v] = min(low[v], tin[u]);
		else{
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if(low[u] > tin[v])
				// (v,u) is bridge!
			if(low[u] >= tin[v] && p!=-1)
				// v is articulation point!
			ch++;
		}
	}
	if(p == -1 && ch > 1)
		// v is articulation point!
}

void findBridges(){
	T = 0;
	ms(vist, 0);
	ms(tin,-1);
	ms(low,-1);
	FOR(i,0,n) if(!vist[i]) dfs(i); 
}