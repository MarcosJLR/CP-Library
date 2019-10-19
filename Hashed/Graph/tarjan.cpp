000 //------------------------------------TARJAN SCC------------------------------------
000 
000 
731 vi G[MAXN];
842 int N;
842 
418 int SCCI[MAXN], SCCN;
667 vector<vi> SCC;
667 
075 int td[MAXN], low[MAXN], dfst;
083 bool onStk[MAXN];
930 stack<int> stk;
171 void tarj(int u){
763 	low[u]=td[u]=dfst++;
803 	stk.push(u);
813 	onStk[u]=true;
199 	FOR(i,0,G[u].size()){
463 		int v=G[u][i];
557 		if(td[v]==-1)
135 			tarj(v);
519 		if(onStk[v])
444 			low[u]=min(low[u],low[v]);
144 	}
144 
921 	if(low[u]==td[u]){
309 		int x = SCC.size();
191 		SCC.pb(vi());
584 		while(true){
246 			int v=stk.top(); stk.pop(); onStk[v]=false;
466 			SCCI[v]=SCCN;
375 			SCC[x].pb(v);
754 			if(u==v) break;
298 		}
165 		SCCN++;
761 	}
171 }
171 
118 void findSCCs(){
691 	ms(onStk,false);
060 	ms(td,-1);
595 	ms(low,0);
480 	ms(SCCI, -1);
140 	dfst=0;
519 	SCCN=0;
154 	SCC.clear();
867 	FOR(u,0,N)
807 		if(td[u]==-1)
030 			tarj(u);
594 }
594 
594 //------------------------------------TARJAN BCC------------------------------------
594 
594 
594 
619 vector<edge> G[MAXN], E;
245 int N;
245 
392 vector<vi> BCC;
744 vi bridges, a_pts;
744 
172 stack<int> stk;
199 int td[MAXN], low[MAXN];
314 void tarj(int v, int p){
780 	low[v] = td[v];
123 	bool is_a_pt = false;
810 	FOR(i,0,G[v].size()){
070 		int u=G[v][i].to, id=G[v][i].id;
460 		if(u==p || td[u] > td[v]) continue;
775 		stk.push(id);
168 		if(td[u]==-1){
261 			td[u] = td[v]+1;
638 			tarj(u,v);
504 			low[v] = min(low[v],low[u]);
969 			if(low[u] >= td[v]){ //v is an articulation point
089 				is_a_pt = true;
239 				int e=-1, x=BCC.size();
238 				BCC.pb(vi());
034 				while(e!=id){
797 					e=stk.top(); stk.pop();
170 					BCC[x].pb(e);
429 				}
431 			}
823 			if(low[u]==td[u]) //v - u is a bridge
306 				bridges.pb(id);
608 		}else low[v] = min(low[v],td[u]);
597 	}
597 	//non-root nodes
534 	if(td[v]!=0 && is_a_pt) a_pts.pb(v);
474 }
474 
493 void findBCCs(){
668 	BCC.clear(), bridges.clear(), a_pts.clear();
016 	ms(td,-1);
669 	stk = stack<int>();
378 	FOR(v,0,N) if(td[v]==-1){
634 		td[v] = 0, tarj(v,-1);
576 		int cnt = 0;
491 		FOR(i,0,G[v].size() && cnt<2)
341 			if(td[G[v][i].to]==1) cnt++;
083 		if(cnt > 1) a_pts.pb(v);
562 	}
092 }
7144813784199092092
