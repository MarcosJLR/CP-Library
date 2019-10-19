000 // Hungarian Algorithm for assignment problem (min or max cost in a perfect bipartite matching)
000 // O(n^3)   for n==m
000 // O(n^2*m) for rectangular problems, n<m
000 // Note that for this implementation, it does not matter whether or not there are in the matrix a[][] negative numbers
000 // For maximum match: a[i][j] *= -1; 
000 // indexed from 1 to n.
000 //
000 // implementation by Andrei Lopatin.
000 
000 // que pasa si no se puede hacer matching maximo? se jode todo? hay que usar min_cost_flow supongo 
000 
744 int n,m;
491 vector < int >  ans(MAXN); //ans( n + 1 ) ;
060 int a[MAXN][MAXN]; //input matrix
060 
454 int hungarian(){
454 
454 	// u and v are potentials (solution is a upper bound of sum of potentials)
118 	vector < int > u ( n + 1 ) , v ( m + 1 ) , p ( m + 1 ) , way ( m + 1 ) ;
118 
118 	//main algorithm loop - O(n^3)/O(n^2*m)
818 	for ( int i = 1 ; i <= n ; ++ i ) {
350 		p [ 0 ] = i ;
204 		int j0 = 0 ;
964 		vector < int > minv ( m + 1 , INF ) ;
327 		vector < char > used ( m + 1 , false ) ;
735 		do {
904 			used [ j0 ] = true ;
043 			int i0 = p [ j0 ] ,  delta = INF,  j1 ;
139 			for ( int j = 1 ; j <= m ; ++ j )
761 				if ( ! used [ j ] ) {
096 					int cur = a [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
324 					if ( cur < minv [ j ] )
714 						minv [ j ] = cur,  way [ j ] = j0 ;
734 					if ( minv [ j ] < delta )
434 						delta = minv [ j ] ,  j1 = j ;
724 				}
504 			for ( int j = 0 ; j <= m ; ++ j )
082 				if ( used [ j ] )
382 					u [ p [ j ] ] += delta,  v [ j ] -= delta ;
890 				else
485 					minv [ j ] -= delta ;
087 			j0 = j1 ;
711 		} while ( p [ j0 ] != 0 ) ;
291 		do {
297 			int j1 = way [ j0 ] ;
402 			p [ j0 ] = p [ j1 ] ;
162 			j0 = j1 ;
727 		} while ( j0 ) ;
368 	}
368 
368 	//vector < int > ans ( n + 1 ) ;
368 	// in ans is the matching (row->column). (also in p, but column->row) // 1<=row<=n, 1<=column<=m
394 	for ( int j = 1 ; j <= m ; ++ j )
977 		ans [ p [ j ] ] = j ;
977 
977 
941 	int cost = - v [ 0 ] ;
770 	return cost; // min (or max) cost of the matching.
770 	// total matching is min(n,m);
015 
-4835296731289284985
