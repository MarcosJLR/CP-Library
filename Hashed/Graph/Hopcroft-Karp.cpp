000 // A from 1 to A
000 // B from A+1 to A+B < MAXN
964 vi G[MAXN]; // edges A->B  //clear G for several test cases
800 int A, B, match[MAXN], dist[MAXN];
437 bool bfs() {
826 	queue<int> q;
475 	FOR(i,1,A+1){
273 		if(match[i]==0){
672 			dist[i]=0;
278 			q.push(i);
004 		} else dist[i]=INF;
341 	}
082 	dist[0] = INF;
246 	while(!q.empty()) {
428 		int v = q.front(); q.pop();
129 		if(v!=0) {
700 			FOR(i,0,G[v].size()){
352 				int u = G[v][i];
859 				if(dist[match[u]]==INF) {
091 					dist[match[u]] = dist[v] + 1;
082 					q.push(match[u]);
785 				}
396 			}
020 		}
481 	}
143 	return (dist[0]!=INF);
926 }
946 bool dfs(int v) {
644 	if(v!=0) {
098 		FOR(i,0,G[v].size()){
744 			int u = G[v][i];
262 			if(dist[match[u]]==dist[v]+1) {
078 				if(dfs(match[u])) {
100 					match[u] = v;
358 					match[v] = u;
390 					return true;
560 				}
538 			}
851 		}
947 		dist[v] = INF;
061 		return false;
898 	}
970 	return true;
696 }
328 int HK(){
624 	ms(match, 0);
968 	int MBM = 0;
000 	while(bfs())
222 		FOR(i,1,A+1)
166 			if(match[i]==0 && dfs(i))
726 				MBM++;
918 	return MBM;
404 
1268583404
