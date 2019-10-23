const int MAXN = 600;
const ll INF = 1LL<<61;

int N;
ll cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
ll dist[MAXN], pi[MAXN], width[MAXN];
pair<int, int> dad[MAXN];
bool found[MAXN];
void add_edge(int from, int to, ll u, ll c) {
	cap[from][to] = u;
	cost[from][to] = c;
}
void relax(int s, int k, ll u, ll c, int dir) {
	ll val = dist[s] + pi[s] - pi[k] + c;
	if (u && val < dist[k]) {
		dist[k] = val;
		dad[k] = {s, dir};
		width[k] = min(u, width[s]);
	}
}
ll dijk(int s, int t) {
	fill(found, found+N+1, false);
	fill(dist, dist+N+1, INF);
	fill(width, width+N+1, 0);
	dist[s] = 0;
	width[s] = INF;	
	while(s != -1){
		int best = -1;
		found[s] = true;
		FOR(k, 0, N){
			if(found[k]) continue;
			relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
			relax(s, k, flow[k][s], -cost[k][s], -1);
			if(best == -1 || dist[k] < dist[best]) best = k;
		}
		s = best;
	}
	FOR(k, 0, N) pi[k] = min(pi[k] + dist[k], INF);
	return width[t];
}

pair<ll, ll> get_flow(int s, int t, ll flow_limit = INF){
	ll totflow = 0, totcost = 0;
	while(ll amt = dijk(s, t)){
		if(totflow + amt > flow_limit) amt = flow_limit - totflow;
		totflow += amt;
		for (int x = t; x != s; x = dad[x].first) {
			if (dad[x].second == 1) {
				flow[dad[x].first][x] += amt;
				totcost += amt * cost[dad[x].first][x];
			} else {
				flow[x][dad[x].first] -= amt;
				totcost -= amt * cost[x][dad[x].first];
			}
		}
		if(totflow == flow_limit) break;
	}
	return {totflow, totcost};
}