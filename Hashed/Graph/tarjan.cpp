000 //------------------------------------TARJAN SCC------------------------------------
000 
000 
964 vi G[MAXN];
806 int N;
806 
167 int SCCI[MAXN], SCCN;
591 vector<vi> SCC;
591 
647 int td[MAXN], low[MAXN], dfst;
441 bool onStk[MAXN];
367 stack<int> stk;
014 void tarj(int u){
555 	low[u]=td[u]=dfst++;
406 	stk.push(u);
924 	onStk[u]=true;
540 	FOR(i,0,G[u].size()){
101 		int v=G[u][i];
138 		if(td[v]==-1)
960 			tarj(v);
239 		if(onStk[v])
703 			low[u]=min(low[u],low[v]);
247 	}
247 
601 	if(low[u]==td[u]){
246 		int x = SCC.size();
441 		SCC.pb(vi());
022 		while(true){
311 			int v=stk.top(); stk.pop(); onStk[v]=false;
782 			SCCI[v]=SCCN;
995 			SCC[x].pb(v);
144 			if(u==v) break;
514 		}
136 		SCCN++;
219 	}
987 }
987 
727 void findSCCs(){
407 	ms(onStk,false);
930 	ms(td,-1);
472 	ms(low,0);
615 	ms(SCCI, -1);
431 	dfst=0;
167 	SCCN=0;
467 	SCC.clear();
909 	FOR(u,0,N)
853 		if(td[u]==-1)
344 			tarj(u);
641 }
641 
641 //------------------------------------TARJAN BCC------------------------------------
641 
641 
641 
657 vector<edge> G[MAXN], E;
481 int N;
481 
242 vector<vi> BCC;
384 vi bridges, a_pts;
384 
975 stack<int> stk;
365 int td[MAXN], low[MAXN];
051 void tarj(int v, int p){
602 	low[v] = td[v];
756 	bool is_a_pt = false;
522 	FOR(i,0,G[v].size()){
583 		int u=G[v][i].to, id=G[v][i].id;
310 		if(u==p || td[u] > td[v]) continue;
395 		stk.push(id);
010 		if(td[u]==-1){
965 			td[u] = td[v]+1;
524 			tarj(u,v);
144 			low[v] = min(low[v],low[u]);
500 			if(low[u] >= td[v]){ //v is an articulation point
178 				is_a_pt = true;
024 				int e=-1, x=BCC.size();
175 				BCC.pb(vi());
237 				while(e!=id){
450 					e=stk.top(); stk.pop();
964 					BCC[x].pb(e);
366 				}
562 			}
848 			if(low[u]==td[u]) //v - u is a bridge
273 				bridges.pb(id);
697 		}else low[v] = min(low[v],td[u]);
405 	}
405 	//non-root nodes
790 	if(td[v]!=0 && is_a_pt) a_pts.pb(v);
229 }
229 
307 void findBCCs(){
141 	BCC.clear(), bridges.clear(), a_pts.clear();
872 	ms(td,-1);
747 	stk = stack<int>();
133 	FOR(v,0,N) if(td[v]==-1){
259 		td[v] = 0, tarj(v,-1);
344 		int cnt = 0;
819 		FOR(i,0,G[v].size() && cnt<2)
806 			if(td[G[v][i].to]==1) cnt++;
307 		if(cnt > 1) a_pts.pb(v);
922 	}
270 }
92031270
