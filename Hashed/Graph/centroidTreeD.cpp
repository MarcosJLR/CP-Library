000 // Centroid Tree Decomposition
000 // Run buildCT to build the cetroid tree
000 
964 vi G[MAXN];
807 int centroid[MAXN];
807 
807 // Precalculate sizes of subtrees from some root.
217 int sz[MAXN];
936 void dfsSZ(int v, int p){
620 	sz[v] = 1;
266 	for(int u:G[v]) if(u!=p && !centroid[u]){
996 		dfsSZ(u,v);
079 		sz[v] += sz[u];
577 	}
208 }
208 
208 // Find the centroid of a tree
286 int findCentroid(int v, int p, int n){
211 	for(int u:G[v]) if(u!=p && !centroid[u] && sz[u]>n/2){
443 		return findCentroid(u,v,n);
122 	}
335 	return v;
034 }
034 
345 int p[MAXN]; //parent link of the CTD. Here we store the CTD.
450 int h[MAXN]; // level of the node in the CTD. could be useful.
450 // Calculate the CTD. O(nlogn)
168 int buildCT(int v, int hv){
168 
681 	dfsSZ(v,-1);
913 	int c = findCentroid(v, -1, sz[v]);
913 
913 	//here you can pre-calculate some data for the centroids. 
764 	centroid[c] = 1;
365 	h[c] = hv;
574 	if(!hv) p[c] = -1;
574 
252 	for(int u:G[c]) if(!centroid[u]){
400 		int cu = buildCT(u, hv+1);
600 		p[cu] = c;
246 	}
246 
883 	return c;
018 }
018 
018 // sample query
713 void query(int v){
737 	int u = v;
530 	while(u!=-1){
530 		// update / do / calculate something
572 		u = p[u];
738 	}
738 	//return something;
038 
349602038
