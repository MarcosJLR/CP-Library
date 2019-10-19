000 // Matrix Inverse
696 bool inv(double **A, double **B, int N) {
657 	int jmax; double tmp;
657 	
440 	for (int i=0; i<N; i++) {
344 		jmax=i;
344 		
879 		for (int j=i+1; j<N; j++)
744 			if (abs(A[j][i])>abs(A[jmax][i])) jmax = j;
744 		
873 		for (int j=0; j<N; j++) {
485 			swap(A[i][j], A[jmax][j]);
731 			swap(B[i][j], B[jmax][j]);
290 		}
290 		
389 		if(abs(A[i][i])<EPS) return false;
539 		tmp=A[i][i];
539 		
116 		for (int j=0; j<N; j++) {
480 			A[i][j]/=tmp; 
934 			B[i][j]/=tmp;
811 		}
153 		for (int j=0; j<N; j++) {
060 			if(i==j) continue;
821 			tmp=A[j][i];
817 			for(int k=0; k<N; k++) {
282 				A[j][k]-=A[i][k]*tmp;
180 				B[j][k]-=B[i][k]*tmp;
972 			}
160 		}
065 	}
991 	return true;
718 }
718 
718 
647 double det(double *m[], int n) {
679 	if (n==2)
400 		return m[0][0]*m[1][1]-m[0][1]*m[1][0];
907 	double deter=0, M[n-1][n-1];
949 	double *m2[n-1];
858 	FOR(i, 0, n) {
496 		int sig=(i%2 ? -1 : 1);
961 		FOR(a, 1, n) {
996 			int k=0;
181 			FOR(b, 0, n) {
658 				if (b==i) continue;
853 				M[a-1][k++]=m[a][b];
266 			}
960 		}
319 		FOR(x, 0, n-1) m2[x]=M[x];
285 		deter = deter + m[0][i]*sig*det(m2, n-1);
750 	}
822 	return deter;
263 }
263 
263 // Gauss Jordan para un vector especifico, sabiendo que el sistema
263 // tiene solucion unica con mas filas que columnas (mas ecuaciones 
263 // que variables)
017 void gauss(int A[][MAXM], int B[], int N, int M){
017 //	N es el numero de filas // 	M es el numero de columnas
787 	int jmax, tmp;
859 	FOR(i, 0, M){
345 		jmax = i;
821 		FOR(j, i+1, N) if(A[j][i] > A[jmax][i]) jmax = j;
066 		FOR(j, 0, M) swap(A[i][j], A[jmax][j]);
183 		swap(B[i], B[jmax]);
721 		tmp = A[i][i];
418 		FOR(j, 0, M) A[i][j] = A[i][j]*inv[tmp]%MOD;
748 		B[i] = (B[i]*inv[tmp])%MOD;
938 		FOR(j, 0, N){
595 			if(i == j) continue;
544 			tmp = A[j][i];
980 			FOR(k, 0, M){
885 				A[j][k] -= A[i][k]*tmp;
579 				A[j][k] = (A[j][k]%MOD + MOD)%MOD;
625 			}
741 			B[j] -= B[i]*tmp;
976 			B[j] = (B[j]%MOD + MOD)%MOD;
807 		}
380 	}
585 
-4874361345208087415
