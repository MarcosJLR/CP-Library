834 using u64 = uint64_t;
209 using u128 = __uint128_t;
209 
306 u64 binPow(u64 a, u64 b, u64 mod){
090     if(b == 0) return 1;
443     if(b&1) return (u128)a * binPow(a, b^1, mod) % mod;
021     return binPow((u128)a * a % mod, b>>1, mod);
428 }
428 
577 bool checkComp(u64 n, u64 a, u64 d, int s){
901     u64 x = binPow(a, d, n);
099     if(x == 1 || x == n-1) return false;
241     FOR(r,1,s){
249         x = (u128)x * x % n;
029         if(x == n-1) return false;
053     }
912     return true;
976 }
976 
792 bool RabinMiller(u64 n){
442     if(n < 2) return false;
386     int r = 0;
088     u64 d = n-1;
425     while(!(d & 1))
010         d >>= 1, r++;
972     for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
707         if(n == a) return true;
166         if(checkComp(n, a, d, r)) return false;
441     }
083     return true;
580 
940226580
