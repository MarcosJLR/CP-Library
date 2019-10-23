000 // Todos los rangos son semi-abiertos [a,b)
149 int N, A[MAXN];
674 struct STN{
657     void merge(STN& L, STN& R) {}
250     void operator=(int a) {}
175 };
913 STN ST[4*MAXN];
076 void STB(int id = 1, int l = 0, int r = N){
009     if(r - l < 2){
174         ST[id] = A[l];
384         return;
586     }
641     int m = (l+r)>>1, L = id<<1, R = L|1;
124     STB(L, l, m); STB(R, m, r);
277     ST[id].merge(ST[L], ST[R]);
613 }
875 STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
737     if(x == l && y == r) return ST[id];
403     int m = (l+r)>>1, L = id<<1, R = L|1;
175     if(x >= m) return STQ(x, y, R, m, r);
187     if(y <= m) return STQ(x, y, L, l, m);
219     STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
587     return res.merge(ln, rn), res;
532 }
292 void STU(int p, int x, int id = 1, int l = 0, int r = N){
570     if(r - l < 2){
145         ST[id] = x;
268         return;
397     }
357     int m = (l+r)>>1, L = id<<1, R = L|1;
355     if(p < m) STU(p, x, L, l, m);
987     else STU(p, x, R, m, r);
440     ST[id].merge(ST[L], ST[R]);
791 
-773363209
