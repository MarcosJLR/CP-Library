000 // Centroid Tree Decomposition
000 // Run buildCT to build the cetroid tree
000 
718 vi G[MAXN];
304 int centroid[MAXN];
304 
304 // Precalculate sizes of subtrees from some root.
135 int sz[MAXN];
981 void dfsSZ(int v, int p){
875 	sz[v] = 1;
568 	for(int u:G[v]) if(u!=p && !centroid[u]){
963 		dfsSZ(u,v);
961 		sz[v] += sz[u];
278 	}
784 }
784 
784 // Find the centroid of a tree
940 int findCentroid(int v, int p, int n){
125 	for(int u:G[v]) if(u!=p && !centroid[u] && sz[u]>n/2){
875 		return findCentroid(u,v,n);
411 	}
910 	return v;
521 }
521 
405 int p[MAXN]; //parent link of the CTD. Here we store the CTD.
046 int h[MAXN]; // level of the node in the CTD. could be useful.
046 // Calculate the CTD. O(nlogn)
881 int buildCT(int v, int hv){
881 
177 	dfsSZ(v,-1);
822 	int c = findCentroid(v, -1, sz[v]);
822 
822 	//here you can pre-calculate some data for the centroids. 
237 	centroid[c] = 1;
015 	h[c] = hv;
696 	if(!hv) p[c] = -1;
696 
068 	for(int u:G[c]) if(!centroid[u]){
062 		int cu = buildCT(u, hv+1);
430 		p[cu] = c;
925 	}
925 
455 	return c;
377 }
377 
377 // sample query
012 void query(int v){
305 	int u = v;
231 	while(u!=-1){
231 		// update / do / calculate something
066 		u = p[u];
640 	}
640 	//return something;
372 
-1864054805190003628
