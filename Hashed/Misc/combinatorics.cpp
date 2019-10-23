000 //----------------NUMEROS DE BELL------
000 //
181 ll BELL[];
587 ll bell(int n){
875 	if(BELL[n]!=-1)
975 		return BELL[n];
073 	ll b =0;
502 	for(int k=0; k<n; k++)
782 		b += (COMB(n-1,k) * bell(k);
782 		//b = (b+(COMB(n-1,k) * bell(k))%MOD)%MOD;
186 	return BELL[n] = b;
343 }
998 ms(BELL,-1)
998 //-------Permutaciones de Multiconjunto------
998 //k es el vector de ocurrencias de cada elemento
998 //{a,a,a,b,c,c} -> k = [3,1,2]
304 ll mcomb(vi k){
594 	ll r = 1;
931 	ll s=0;
259 	for(int i=0; i<k.size(); i++){
633 		s+=k[i];
705 		r*= comb(s,k[i]);
534 	}
699 	return r;
426 }
426 //------- Recurrencias --------------
567 #define MN 2 //matriz MNxMN
432 typedef vector<ll>  vll;
746 typedef vector<vll>  MAT;
071 MAT operator*(MAT &a, MAT &b) {
622 	MAT res(MN, vll(MN));
042 	FOR(i,0,MN) FOR(j,0,MN) FOR(k,0,MN)
431 		res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
431 		//res[i][j] = res[i][j] + a[i][k] * b[k][j];
737 	return res;
114 }
789 MAT pot(MAT b, ll e){
721 	if(e==1) return b;
305 	if(e==2) return b*b;
142 	MAT r = pot(pot(b,e/2),2);
998 	if(e&1) return b*r;
323 	return r;
488 }
612 ll fib(ll n){
741 	if(n==0)
688 		return 0;
717 	else if(n==2 || n==1)
614 		return 1;
760 	MAT F(MN, vll(MN,1)); F[1][1]=0;
796 	return pot(F,n-1)[0][0];
219 }
219 
633111219
