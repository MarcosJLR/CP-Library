000 //----------------NUMEROS DE BELL------
000 //
710 ll BELL[];
281 ll bell(int n){
692 	if(BELL[n]!=-1)
886 		return BELL[n];
048 	ll b =0;
964 	for(int k=0; k<n; k++)
541 		b += (COMB(n-1,k) * bell(k);
541 		//b = (b+(COMB(n-1,k) * bell(k))%MOD)%MOD;
189 	return BELL[n] = b;
022 }
014 ms(BELL,-1)
014 //-------Permutaciones de Multiconjunto------
014 //k es el vector de ocurrencias de cada elemento
014 //{a,a,a,b,c,c} -> k = [3,1,2]
334 ll mcomb(vi k){
342 	ll r = 1;
122 	ll s=0;
995 	for(int i=0; i<k.size(); i++){
351 		s+=k[i];
530 		r*= comb(s,k[i]);
114 	}
148 	return r;
363 }
363 //------- Recurrencias --------------
127 #define MN 2 //matriz MNxMN
369 typedef vector<ll>  vll;
866 typedef vector<vll>  MAT;
703 MAT operator*(MAT &a, MAT &b) {
788 	MAT res(MN, vll(MN));
406 	FOR(i,0,MN) FOR(j,0,MN) FOR(k,0,MN)
062 		res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
062 		//res[i][j] = res[i][j] + a[i][k] * b[k][j];
956 	return res;
110 }
396 MAT pot(MAT b, ll e){
775 	if(e==1) return b;
004 	if(e==2) return b*b;
410 	MAT r = pot(pot(b,e/2),2);
740 	if(e&1) return b*r;
206 	return r;
714 }
196 ll fib(ll n){
757 	if(n==0)
458 		return 0;
313 	else if(n==2 || n==1)
913 		return 1;
659 	MAT F(MN, vll(MN,1)); F[1][1]=0;
012 	return pot(F,n-1)[0][0];
285 }
285 
-8808754556597027715
