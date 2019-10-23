000 // Matrix Inverse
887 bool inv(double **A, double **B, int N) {
317 	int jmax; double tmp;
317 	
562 	for (int i=0; i<N; i++) {
540 		jmax=i;
540 		
756 		for (int j=i+1; j<N; j++)
327 			if (abs(A[j][i])>abs(A[jmax][i])) jmax = j;
327 		
214 		for (int j=0; j<N; j++) {
340 			swap(A[i][j], A[jmax][j]);
611 			swap(B[i][j], B[jmax][j]);
551 		}
551 		
204 		if(abs(A[i][i])<EPS) return false;
760 		tmp=A[i][i];
760 		
891 		for (int j=0; j<N; j++) {
429 			A[i][j]/=tmp; 
922 			B[i][j]/=tmp;
720 		}
335 		for (int j=0; j<N; j++) {
685 			if(i==j) continue;
594 			tmp=A[j][i];
330 			for(int k=0; k<N; k++) {
461 				A[j][k]-=A[i][k]*tmp;
927 				B[j][k]-=B[i][k]*tmp;
919 			}
118 		}
560 	}
538 	return true;
346 }
267 double det(double *m[], int n) {
489 	if (n==2)
823 		return m[0][0]*m[1][1]-m[0][1]*m[1][0];
665 	double deter=0, M[n-1][n-1];
541 	double *m2[n-1];
386 	FOR(i, 0, n) {
794 		int sig=(i%2 ? -1 : 1);
398 		FOR(a, 1, n) {
319 			int k=0;
756 			FOR(b, 0, n) {
075 				if (b==i) continue;
125 				M[a-1][k++]=m[a][b];
213 			}
338 		}
327 		FOR(x, 0, n-1) m2[x]=M[x];
012 		deter = deter + m[0][i]*sig*det(m2, n-1);
083 	}
339 	return deter;
930 }
930 // Gauss Jordan para un vector especifico, sabiendo que el sistema
930 // tiene solucion unica con mas filas que columnas (mas ecuaciones 
930 // que variables)
453 void gauss(int A[][MAXM], int B[], int N, int M){
453 //	N es el numero de filas // 	M es el numero de columnas
499 	int jmax, tmp;
485 	FOR(i, 0, M){
316 		jmax = i;
894 		FOR(j, i+1, N) if(A[j][i] > A[jmax][i]) jmax = j;
983 		FOR(j, 0, M) swap(A[i][j], A[jmax][j]);
956 		swap(B[i], B[jmax]);
204 		tmp = A[i][i];
338 		FOR(j, 0, M) A[i][j] = A[i][j]*inv[tmp]%MOD;
418 		B[i] = (B[i]*inv[tmp])%MOD;
937 		FOR(j, 0, N){
957 			if(i == j) continue;
508 			tmp = A[j][i];
848 			FOR(k, 0, M){
195 				A[j][k] -= A[i][k]*tmp;
630 				A[j][k] = (A[j][k]%MOD + MOD)%MOD;
553 			}
463 			B[j] -= B[i]*tmp;
383 			B[j] = (B[j]%MOD + MOD)%MOD;
033 		}
098 	}
242 
60785242
