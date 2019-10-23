963 ll BIT[MAXR][MAXC];
054 void updBIT(int r, int c, ll val){
808     r++, c++;
567     for(; r < MAXR; r += r&-r)
524         for(int cc = c; cc < MAXC; cc += cc&-cc)
229             BIT[r][cc] += val;
267 }
866 ll sumBIT(int r, int c){
511     r++, c++;
640     ll ret = 0;
740     for(; r; r -= r&-r)
774         for(int cc = c; cc; cc -= cc&-cc)
808             ret += BIT[r][cc];
234     return ret;
611 }
-116930389
