070 ll BIT[MAXR][MAXC];
058 void updBIT(int r, int c, ll val){
420     r++, c++;
981     for(; r < MAXR; r += r&-r)
601         for(int cc = c; cc < MAXC; cc += cc&-cc)
438             BIT[r][cc] += val;
773 }
917 ll sumBIT(int r, int c){
191     r++, c++;
200     ll ret = 0;
508     for(; r; r -= r&-r)
019         for(int cc = c; cc; cc -= cc&-cc)
286             ret += BIT[r][cc];
919     return ret;
929 }
568732351095289929
