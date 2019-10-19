881 using u64 = uint64_t;
646 using u128 = __uint128_t;
646 
388 u64 binPow(u64 a, u64 b, u64 mod){
988     if(b == 0) return 1;
080     if(b&1) return (u128)a * binPow(a, b^1, mod) % mod;
472     return binPow((u128)a * a % mod, b>>1, mod);
400 }
400 
139 bool checkComp(u64 n, u64 a, u64 d, int s){
126     u64 x = binPow(a, d, n);
732     if(x == 1 || x == n-1) return false;
132     FOR(r,1,s){
666         x = (u128)x * x % n;
463         if(x == n-1) return false;
602     }
037     return true;
776 }
776 
177 bool RabinMiller(u64 n){
930     if(n < 2) return false;
219     int r = 0;
091     u64 d = n-1;
074     while(!(d & 1))
488         d >>= 1, r++;
243     for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
747         if(n == a) return true;
360         if(checkComp(n, a, d, r)) return false;
530     }
069     return true;
814 
5387276272628750814
