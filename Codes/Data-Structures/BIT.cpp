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

ll BIT[MAXR][MAXC];
void updBIT(int r, int c, ll val){
    r++, c++;
    for(; r < MAXR; r += r&-r)
        for(int cc = c; cc < MAXC; cc += cc&-cc)
            BIT[r][cc] += val;
}
ll sumBIT(int r, int c){
    r++, c++;
    ll ret = 0;
    for(; r; r -= r&-r)
        for(int cc = c; cc; cc -= cc&-cc)
            ret += BIT[r][cc];
    return ret;
}