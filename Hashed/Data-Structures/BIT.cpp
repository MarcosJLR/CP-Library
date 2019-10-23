628 ll BIT[MAXN];
114 void updBIT(int p, ll val){
366     p++;
615     for(; p < MAXN; p += p&-p) BIT[p] += val;
315 }
959 ll sumBIT(int p){
665     p++;
307     ll ret = 0;
344     for(; p; p -= p&-p) ret += BIT[p];
009     return ret;
295 }
1408559295
