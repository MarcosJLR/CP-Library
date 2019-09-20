ll BIT[MAXN];
void updBIT(int p, ll val){
    p++;
    for(; p < MAXN; p += p&-p) BIT[p] += val;
}
ll sumBIT(int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) ret += BIT[p];
    return ret;
}
