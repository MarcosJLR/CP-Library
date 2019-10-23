000 // Chinese Remainder theorem (CRT) (tested with (https://open.kattis.com/problems/generalchineseremainder) )
000 // lowest common multiple of two integers (ll).
997 ll lcm(ll a, ll b){
741 	return a / __gcd(a, b) * b;
109 }
109 // Auxiliar struct for the return type of extended euclidean algorithm for gcd.
105 struct GCDtuple { ll x, y, d; };
105 // Extended euclidean algorithm for gcd. 
105 // Also return integers x,y of the bezout's identity (if gcd(a,b)=d then exist x and y such that ax+by=d)
738 GCDtuple extGCD(ll a, ll b){
738 	//if(a==0 && b==0) return {1,1,0};
282     if (b == 0) return {1, 0, a};
914     if (a == 0) return {0, 1, b};
431     GCDtuple ret = extGCD(b, a % b);
417     return {ret.y, ret.x - a / b * ret.y, ret.d};
760 }
598 int t; //number of congruences of the CRT system.
997 ll a[MAXN], n[MAXN], LCM; // array a of remainder mod moduli, and array n of modulis. LCM of modulis.
997 // Algorithm to solve a system of congruences with the Chinese Remainder Theorem.
997 // (is not needed the modulis to be pairwise coprime)
009 ll CRT(){
918 	ll ans = a[0];
420 	LCM = n[0];
754 	FOR(i,1,t){
269 		auto eg = extGCD(LCM, n[i]);
192 		int x1 = eg.x;
543 		int d = eg.d;
826 		if((a[i]-ans)%d!=0){ // No solution
644 			printf("no solution\n");
328 			return -1;
356 		}
573 		ans = (ans + (((x1*((a[i]-ans)/d))%(n[i]/d))*LCM)%(LCM/d*n[i]) + LCM/d*n[i] )%(LCM/d*n[i]);
763 		LCM = lcm(LCM,n[i]);
013 	}
419 	return ans;
288 
1093502288
