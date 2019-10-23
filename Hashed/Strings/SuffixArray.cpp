058 const int MAXL=0,MAXLG=0;
791 int N, SA[MAXL], LCP[MAXL], P[MAXLG][MAXL], stp, cnt;
626 struct SAentry {
856 	int S, P1, P2;
746 	bool operator<(const SAentry& e) const {
939 		return P1==e.P1?P2<e.P2:P1<e.P1;
958 	}
705 };
323 void BLCP() {
220 	int i,j,stp2,lcp;
454 	FOR(k,1,N) {
856 		i=SA[k], j=SA[k-1], lcp=0; stp2=stp;
591 		while(i<N && j<N && stp2>=0) {
593 			if(P[stp2][i]==P[stp2][j])
648 				i+=1<<stp2, j+=1<<stp2, lcp+=1<<stp2;
077 			stp2--;
754 		}
214 		LCP[k]=lcp;
562 	}
727 };
530 void BSA() {
344 	SAentry L[MAXL];
323 	FOR(i,0,N) P[0][i]=S[i];
175 	stp=1, cnt=1;
182 	while(cnt<=N) {
927 		FOR(i,0,N) L[i]={i,P[stp-1][i],i+cnt<N?P[stp-1][i+cnt]:-1};
337 		sort(L,L+N);
406 		P[stp][L[0].S]=0;
080 		FOR(i, 1, N)
253 			P[stp][L[i].S]=L[i].P1==L[i-1].P1&&L[i].P2==L[i-1].P2?P[stp][L[i-1].S]:i;
531 		stp++; cnt<<=1;
490 	}
888 	stp--; cnt>>=1;
705 	FOR(i,0,N) SA[P[stp][i]]=i;
601 
1429174601
