099 ll mult(ll a, ll b, ll mod){
697     return (__int128)a * b % mod;
776 }
699 ll f(ll x, ll c, ll mod){
787     return (mult(x, x, mod) + c) % mod;
540 }
978 ll rho(ll n){ // Works in O(n^(1/4) * log(n))
670     ll x = 2, y = 2, g = 1;
614     ll c = rand() % n + 1;
112     while(g == 1){
237         x = f(x, c, n);
765         y = f(y, c, n);
881         y = f(y, c, n);
481         g = __gcd(abs(x - y), n);
256     }
567     return g==n ? rho(n) : g;
377 }
301 map <ll, ll> fact;
423 void factRho(ll n){
528     if(n == 1) return;
126     if(RabinMiller(n)){
575         fact[n]++;
085         return;
144     }
663     ll factor = rho(n);
938     factRho(factor);
467     factRho(n/factor);
919 }
463 void factor(ll n){
351     ll i = 2;
823     while(n > 1 && i < 60){
620         while(n % i == 0) fact[i]++, n /= i;
857         i++;
010     }
192     factRho(n);
502 
1624284521482368502
