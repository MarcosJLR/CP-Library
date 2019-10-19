255 const int MAXN = 600;
458 const ll INF = 1LL<<61;
458 
193 int N;
667 ll cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
781 ll dist[MAXN], pi[MAXN], width[MAXN];
881 pair<int, int> dad[MAXN];
636 bool found[MAXN];
351 void add_edge(int from, int to, ll u, ll c) {
646 	cap[from][to] = u;
971 	cost[from][to] = c;
568 }
484 void relax(int s, int k, ll u, ll c, int dir) {
450 	ll val = dist[s] + pi[s] - pi[k] + c;
788 	if (u && val < dist[k]) {
183 		dist[k] = val;
891 		dad[k] = {s, dir};
925 		width[k] = min(u, width[s]);
825 	}
103 }
137 ll dijk(int s, int t) {
977 	fill(found, found+N+1, false);
686 	fill(dist, dist+N+1, INF);
752 	fill(width, width+N+1, 0);
511 	dist[s] = 0;
491 	width[s] = INF;	
971 	while(s != -1){
727 		int best = -1;
554 		found[s] = true;
538 		FOR(k, 0, N){
875 			if(found[k]) continue;
083 			relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
794 			relax(s, k, flow[k][s], -cost[k][s], -1);
516 			if(best == -1 || dist[k] < dist[best]) best = k;
711 		}
442 		s = best;
333 	}
697 	FOR(k, 0, N) pi[k] = min(pi[k] + dist[k], INF);
980 	return width[t];
531 }
531 
571 pair<ll, ll> get_flow(int s, int t, ll flow_limit = INF){
690 	ll totflow = 0, totcost = 0;
563 	while(ll amt = dijk(s, t)){
558 		if(totflow + amt > flow_limit) amt = flow_limit - totflow;
360 		totflow += amt;
573 		for (int x = t; x != s; x = dad[x].first) {
187 			if (dad[x].second == 1) {
690 				flow[dad[x].first][x] += amt;
032 				totcost += amt * cost[dad[x].first][x];
551 			} else {
604 				flow[x][dad[x].first] -= amt;
147 				totcost -= amt * cost[x][dad[x].first];
793 			}
183 		}
203 		if(totflow == flow_limit) break;
367 	}
449 	return {totflow, totcost};
807 
1123315120342212807
