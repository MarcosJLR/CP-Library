000 // A from 1 to A
000 // B from A+1 to A+B < MAXN
489 vi G[MAXN]; // edges A->B  //clear G for several test cases
669 int A, B, match[MAXN], dist[MAXN];
420 bool bfs() {
880 	queue<int> q;
875 	FOR(i,1,A+1){
282 		if(match[i]==0){
425 			dist[i]=0;
989 			q.push(i);
272 		} else dist[i]=INF;
827 	}
893 	dist[0] = INF;
268 	while(!q.empty()) {
040 		int v = q.front(); q.pop();
625 		if(v!=0) {
212 			FOR(i,0,G[v].size()){
382 				int u = G[v][i];
466 				if(dist[match[u]]==INF) {
864 					dist[match[u]] = dist[v] + 1;
775 					q.push(match[u]);
837 				}
043 			}
878 		}
716 	}
618 	return (dist[0]!=INF);
061 }
594 bool dfs(int v) {
519 	if(v!=0) {
414 		FOR(i,0,G[v].size()){
354 			int u = G[v][i];
320 			if(dist[match[u]]==dist[v]+1) {
900 				if(dfs(match[u])) {
843 					match[u] = v;
701 					match[v] = u;
410 					return true;
133 				}
632 			}
374 		}
440 		dist[v] = INF;
999 		return false;
945 	}
964 	return true;
127 }
127 int HK(){
985 	ms(match, 0);
577 	int MBM = 0;
069 	while(bfs())
044 		FOR(i,1,A+1)
573 			if(match[i]==0 && dfs(i))
460 				MBM++;
274 	return MBM;
705 
678296235537721705
