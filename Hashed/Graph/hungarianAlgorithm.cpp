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
530 int n,m;
585 vector < int >  ans(MAXN); //ans( n + 1 ) ;
077 int a[MAXN][MAXN]; //input matrix
077 
643 int hungarian(){
643 
643 	// u and v are potentials (solution is a upper bound of sum of potentials)
696 	vector < int > u ( n + 1 ) , v ( m + 1 ) , p ( m + 1 ) , way ( m + 1 ) ;
696 
696 	//main algorithm loop - O(n^3)/O(n^2*m)
834 	for ( int i = 1 ; i <= n ; ++ i ) {
163 		p [ 0 ] = i ;
480 		int j0 = 0 ;
628 		vector < int > minv ( m + 1 , INF ) ;
573 		vector < char > used ( m + 1 , false ) ;
968 		do {
624 			used [ j0 ] = true ;
000 			int i0 = p [ j0 ] ,  delta = INF,  j1 ;
051 			for ( int j = 1 ; j <= m ; ++ j )
987 				if ( ! used [ j ] ) {
973 					int cur = a [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
410 					if ( cur < minv [ j ] )
760 						minv [ j ] = cur,  way [ j ] = j0 ;
121 					if ( minv [ j ] < delta )
505 						delta = minv [ j ] ,  j1 = j ;
967 				}
518 			for ( int j = 0 ; j <= m ; ++ j )
668 				if ( used [ j ] )
103 					u [ p [ j ] ] += delta,  v [ j ] -= delta ;
178 				else
058 					minv [ j ] -= delta ;
777 			j0 = j1 ;
972 		} while ( p [ j0 ] != 0 ) ;
782 		do {
645 			int j1 = way [ j0 ] ;
274 			p [ j0 ] = p [ j1 ] ;
998 			j0 = j1 ;
645 		} while ( j0 ) ;
168 	}
168 
168 	//vector < int > ans ( n + 1 ) ;
168 	// in ans is the matching (row->column). (also in p, but column->row) // 1<=row<=n, 1<=column<=m
302 	for ( int j = 1 ; j <= m ; ++ j )
896 		ans [ p [ j ] ] = j ;
896 
896 
691 	int cost = - v [ 0 ] ;
497 	return cost; // min (or max) cost of the matching.
497 	// total matching is min(n,m);
202 
1418937202
