125 struct edge {
979 	int a, b;
471 	ll cap, flow;
280 };
280  
249 int N, M, s, t, d[MAXN], ptr[MAXN];
032 vector<edge> e;
585 vi G[MAXN];
585  
951 void add_edge(int a, int b, ll cap) {
320 	edge e1 = { a, b, cap, 0 };
793 	edge e2 = { b, a, 0, 0 };
360 	G[a].pb((int)e.size());
909 	e.pb(e1);
727 	G[b].pb((int) e.size());
498 	e.pb(e2);
383 }
383  
798 bool bfs() {
493 	queue<int> q; q.push(s);
753 	memset (d, -1, (N+1) * sizeof d[0]);
504 	d[s] = 0;
590 	while(!q.empty() && d[t] == -1) {
591 		int v = q.front(); q.pop();
984 		FOR(i,0,G[v].size()){
295 			int id = G[v][i], u = e[id].b;
046 			if(d[u] == -1 && e[id].flow < e[id].cap){
234 				q.push(u);
975 				d[u] = d[v] + 1;
740 			}
051 		}
627 	}
557 	return d[t] != -1;
388 }
388  
648 ll dfs(int v, ll flow){
862 	if(!flow) return 0;
486 	if (v == t)  return flow;
564 	for (; ptr[v]<(int)G[v].size(); ++ptr[v]) {
222 		int id = G[v][ptr[v]], u = e[id].b;
132 		if(d[u] != d[v]+1) continue;
831 		int pushed = dfs(u, min(flow, (ll) e[id].cap - e[id].flow));
739 		if(pushed){
951 			e[id].flow += pushed;
148 			e[id^1].flow -= pushed;
059 			return pushed;
620 		}
190 	}
567 	return 0;
282 }
282  
830 ll dinic() {
857 	ll flow = 0;
419 	while(true){
724 		if (!bfs())  break;
689 		memset (ptr, 0, (N+1) * sizeof ptr[0]);
467 		while (ll pushed = dfs(s, INF))
873 			flow += pushed;
586 	}
794 	return flow;
744 
516721848566112744
