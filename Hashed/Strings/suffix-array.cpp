236 const int MAXL=0,MAXLG=0;
480 int N, SA[MAXL], LCP[MAXL], P[MAXLG][MAXL], stp, cnt;
518 struct SAentry {
560 	int S, P1, P2;
024 	bool operator<(const SAentry& e) const {
098 		return P1==e.P1?P2<e.P2:P1<e.P1;
238 	}
390 };
510 void BLCP() {
255 	int i,j,stp2,lcp;
558 	FOR(k,1,N) {
269 		i=SA[k], j=SA[k-1], lcp=0; stp2=stp;
546 		while(i<N && j<N && stp2>=0) {
232 			if(P[stp2][i]==P[stp2][j])
184 				i+=1<<stp2, j+=1<<stp2, lcp+=1<<stp2;
028 			stp2--;
173 		}
986 		LCP[k]=lcp;
586 	}
497 };
058 void BSA() {
852 	SAentry L[MAXL];
530 	FOR(i,0,N) P[0][i]=S[i];
590 	stp=1, cnt=1;
114 	while(cnt<=N) {
505 		FOR(i,0,N) L[i]={i,P[stp-1][i],i+cnt<N?P[stp-1][i+cnt]:-1};
610 		sort(L,L+N);
011 		P[stp][L[0].S]=0;
746 		FOR(i, 1, N)
843 			P[stp][L[i].S]=L[i].P1==L[i-1].P1&&L[i].P2==L[i-1].P2?P[stp][L[i-1].S]:i;
325 		stp++; cnt<<=1;
954 	}
303 	stp--; cnt>>=1;
491 	FOR(i,0,N) SA[P[stp][i]]=i;
729 
-7272721146780732271
