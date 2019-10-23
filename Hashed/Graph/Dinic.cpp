789 struct edge {
456 	int a, b;
079 	ll cap, flow;
688 };
688  
429 int N, M, s, t, d[MAXN], ptr[MAXN];
315 vector<edge> e;
722 vi G[MAXN];
722  
718 void add_edge(int a, int b, ll cap) {
939 	edge e1 = { a, b, cap, 0 };
751 	edge e2 = { b, a, 0, 0 };
757 	G[a].pb((int)e.size());
941 	e.pb(e1);
961 	G[b].pb((int) e.size());
875 	e.pb(e2);
898 }
898  
475 bool bfs() {
054 	queue<int> q; q.push(s);
723 	memset (d, -1, (N+1) * sizeof d[0]);
530 	d[s] = 0;
445 	while(!q.empty() && d[t] == -1) {
647 		int v = q.front(); q.pop();
865 		FOR(i,0,G[v].size()){
555 			int id = G[v][i], u = e[id].b;
919 			if(d[u] == -1 && e[id].flow < e[id].cap){
875 				q.push(u);
275 				d[u] = d[v] + 1;
169 			}
203 		}
885 	}
390 	return d[t] != -1;
185 }
185  
244 ll dfs(int v, ll flow){
705 	if(!flow) return 0;
831 	if (v == t)  return flow;
713 	for (; ptr[v]<(int)G[v].size(); ++ptr[v]) {
167 		int id = G[v][ptr[v]], u = e[id].b;
024 		if(d[u] != d[v]+1) continue;
729 		int pushed = dfs(u, min(flow, (ll) e[id].cap - e[id].flow));
043 		if(pushed){
267 			e[id].flow += pushed;
441 			e[id^1].flow -= pushed;
778 			return pushed;
830 		}
996 	}
226 	return 0;
094 }
094  
718 ll dinic() {
699 	ll flow = 0;
364 	while(true){
351 		if (!bfs())  break;
137 		memset (ptr, 0, (N+1) * sizeof ptr[0]);
999 		while (ll pushed = dfs(s, INF))
141 			flow += pushed;
333 	}
932 	return flow;
455 
711922455
