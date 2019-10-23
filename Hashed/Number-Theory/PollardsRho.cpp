004 ll mult(ll a, ll b, ll mod){
593     return (__int128)a * b % mod;
260 }
420 ll f(ll x, ll c, ll mod){
733     return (mult(x, x, mod) + c) % mod;
011 }
661 ll rho(ll n){ // Works in O(n^(1/4) * log(n))
977     ll x = 2, y = 2, g = 1;
684     ll c = rand() % n + 1;
944     while(g == 1){
543         x = f(x, c, n);
628         y = f(y, c, n);
956         y = f(y, c, n);
318         g = __gcd(abs(x - y), n);
680     }
535     return g==n ? rho(n) : g;
115 }
637 map <ll, ll> fact;
916 void factRho(ll n){
631     if(n == 1) return;
713     if(RabinMiller(n)){
316         fact[n]++;
372         return;
588     }
855     ll factor = rho(n);
566     factRho(factor);
014     factRho(n/factor);
409 }
353 void factor(ll n){
961     ll i = 2;
373     while(n > 1 && i < 60){
137         while(n % i == 0) fact[i]++, n /= i;
467         i++;
431     }
976     factRho(n);
743 
-1299128257
