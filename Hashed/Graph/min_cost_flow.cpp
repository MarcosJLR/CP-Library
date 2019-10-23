222 const int MAXN = 600;
055 const ll INF = 1LL<<61;
528 int N;
573 ll cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
892 ll dist[MAXN], pi[MAXN], width[MAXN];
907 pair<int, int> dad[MAXN];
260 bool found[MAXN];
440 void add_edge(int from, int to, ll u, ll c) {
517 	cap[from][to] = u;
263 	cost[from][to] = c;
534 }
754 void relax(int s, int k, ll u, ll c, int dir) {
521 	ll val = dist[s] + pi[s] - pi[k] + c;
345 	if (u && val < dist[k]) {
255 		dist[k] = val;
111 		dad[k] = {s, dir};
759 		width[k] = min(u, width[s]);
548 	}
558 }
128 ll dijk(int s, int t) {
482 	fill(found, found+N+1, false);
440 	fill(dist, dist+N+1, INF);
894 	fill(width, width+N+1, 0);
965 	dist[s] = 0;
002 	width[s] = INF;	
444 	while(s != -1){
356 		int best = -1;
341 		found[s] = true;
804 		FOR(k, 0, N){
576 			if(found[k]) continue;
460 			relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
085 			relax(s, k, flow[k][s], -cost[k][s], -1);
629 			if(best == -1 || dist[k] < dist[best]) best = k;
850 		}
827 		s = best;
653 	}
206 	FOR(k, 0, N) pi[k] = min(pi[k] + dist[k], INF);
643 	return width[t];
804 }
815 pair<ll, ll> get_flow(int s, int t, ll flow_limit = INF){
127 	ll totflow = 0, totcost = 0;
305 	while(ll amt = dijk(s, t)){
540 		if(totflow + amt > flow_limit) amt = flow_limit - totflow;
998 		totflow += amt;
209 		for (int x = t; x != s; x = dad[x].first) {
680 			if (dad[x].second == 1) {
654 				flow[dad[x].first][x] += amt;
379 				totcost += amt * cost[dad[x].first][x];
898 			} else {
085 				flow[x][dad[x].first] -= amt;
917 				totcost -= amt * cost[x][dad[x].first];
664 			}
076 		}
537 		if(totflow == flow_limit) break;
098 	}
890 	return {totflow, totcost};
592 
2030296592
