000 // Chinese Remainder theorem (CRT) (tested with (https://open.kattis.com/problems/generalchineseremainder) )
000 
000 // lowest common multiple of two integers (ll).
341 ll lcm(ll a, ll b){
572 	return a / __gcd(a, b) * b;
321 }
321 
321 // Auxiliar struct for the return type of extended euclidean algorithm for gcd.
294 struct GCDtuple { ll x, y, d; };
294 // Extended euclidean algorithm for gcd. 
294 // Also return integers x,y of the bezout's identity (if gcd(a,b)=d then exist x and y such that ax+by=d)
802 GCDtuple extGCD(ll a, ll b){
802 
802 	//if(a==0 && b==0) return {1,1,0};
183     if (b == 0) return {1, 0, a};
007     if (a == 0) return {0, 1, b};
007 
989     GCDtuple ret = extGCD(b, a % b);
244     return {ret.y, ret.x - a / b * ret.y, ret.d};
167 }
167 
041 int t; //number of congruences of the CRT system.
009 ll a[MAXN], n[MAXN], LCM; // array a of remainder mod moduli, and array n of modulis. LCM of modulis.
009 
009 // Algorithm to solve a system of congruences with the Chinese Remainder Theorem.
009 // (is not needed the modulis to be pairwise coprime)
589 ll CRT(){
589 
430 	ll ans = a[0];
519 	LCM = n[0];
519 
094 	FOR(i,1,t){
094 
916 		auto eg = extGCD(LCM, n[i]);
391 		int x1 = eg.x;
513 		int d = eg.d;
513 
285 		if((a[i]-ans)%d!=0){ // No solution
095 			printf("no solution\n");
725 			return -1;
132 		}
132 
595 		ans = (ans + (((x1*((a[i]-ans)/d))%(n[i]/d))*LCM)%(LCM/d*n[i]) + LCM/d*n[i] )%(LCM/d*n[i]);
595 
829 		LCM = lcm(LCM,n[i]);
467 	}
467 
972 	return ans;
290 
-2438203684892203710
