559 ll BIT[MAXN];
363 void updBIT(int p, ll val){
065     p++;
021     for(; p < MAXN; p += p&-p) BIT[p] += val;
174 }
186 ll sumBIT(int p){
197     p++;
078     ll ret = 0;
376     for(; p; p -= p&-p) ret += BIT[p];
732     return ret;
308 }
4700934216831523308
