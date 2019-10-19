struct edge {
	int a, b;
	ll cap, flow;
};
 
int N, M, s, t, d[MAXN], ptr[MAXN];
vector<edge> e;
vi G[MAXN];
 
void add_edge(int a, int b, ll cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	G[a].pb((int)e.size());
	e.pb(e1);
	G[b].pb((int) e.size());
	e.pb(e2);
}
 
bool bfs() {
	queue<int> q; q.push(s);
	memset (d, -1, (N+1) * sizeof d[0]);
	d[s] = 0;
	while(!q.empty() && d[t] == -1) {
		int v = q.front(); q.pop();
		FOR(i,0,G[v].size()){
			int id = G[v][i], u = e[id].b;
			if(d[u] == -1 && e[id].flow < e[id].cap){
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
ll dfs(int v, ll flow){
	if(!flow) return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)G[v].size(); ++ptr[v]) {
		int id = G[v][ptr[v]], u = e[id].b;
		if(d[u] != d[v]+1) continue;
		int pushed = dfs(u, min(flow, (ll) e[id].cap - e[id].flow));
		if(pushed){
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic() {
	ll flow = 0;
	while(true){
		if (!bfs())  break;
		memset (ptr, 0, (N+1) * sizeof ptr[0]);
		while (ll pushed = dfs(s, INF))
			flow += pushed;
	}
	return flow;
}