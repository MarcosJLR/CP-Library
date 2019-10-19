const int MAXL=0,MAXLG=0;
int N, SA[MAXL], LCP[MAXL], P[MAXLG][MAXL], stp, cnt;
struct SAentry {
	int S, P1, P2;
	bool operator<(const SAentry& e) const {
		return P1==e.P1?P2<e.P2:P1<e.P1;
	}
};
void BLCP() {
	int i,j,stp2,lcp;
	FOR(k,1,N) {
		i=SA[k], j=SA[k-1], lcp=0; stp2=stp;
		while(i<N && j<N && stp2>=0) {
			if(P[stp2][i]==P[stp2][j])
				i+=1<<stp2, j+=1<<stp2, lcp+=1<<stp2;
			stp2--;
		}
		LCP[k]=lcp;
	}
};
void BSA() {
	SAentry L[MAXL];
	FOR(i,0,N) P[0][i]=S[i];
	stp=1, cnt=1;
	while(cnt<=N) {
		FOR(i,0,N) L[i]={i,P[stp-1][i],i+cnt<N?P[stp-1][i+cnt]:-1};
		sort(L,L+N);
		P[stp][L[0].S]=0;
		FOR(i, 1, N)
			P[stp][L[i].S]=L[i].P1==L[i-1].P1&&L[i].P2==L[i-1].P2?P[stp][L[i-1].S]:i;
		stp++; cnt<<=1;
	}
	stp--; cnt>>=1;
	FOR(i,0,N) SA[P[stp][i]]=i;
}