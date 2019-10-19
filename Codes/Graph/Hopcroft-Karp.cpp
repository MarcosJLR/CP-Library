// A from 1 to A
// B from A+1 to A+B < MAXN
vi G[MAXN]; // edges A->B  //clear G for several test cases
int A, B, match[MAXN], dist[MAXN];
bool bfs() {
	queue<int> q;
	FOR(i,1,A+1){
		if(match[i]==0){
			dist[i]=0;
			q.push(i);
		} else dist[i]=INF;
	}
	dist[0] = INF;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		if(v!=0) {
			FOR(i,0,G[v].size()){
				int u = G[v][i];
				if(dist[match[u]]==INF) {
					dist[match[u]] = dist[v] + 1;
					q.push(match[u]);
				}
			}
		}
	}
	return (dist[0]!=INF);
}
bool dfs(int v) {
	if(v!=0) {
		FOR(i,0,G[v].size()){
			int u = G[v][i];
			if(dist[match[u]]==dist[v]+1) {
				if(dfs(match[u])) {
					match[u] = v;
					match[v] = u;
					return true;
				}
			}
		}
		dist[v] = INF;
		return false;
	}
	return true;
}
int HK(){
	ms(match, 0);
	int MBM = 0;
	while(bfs())
		FOR(i,1,A+1)
			if(match[i]==0 && dfs(i))
				MBM++;
	return MBM;
}