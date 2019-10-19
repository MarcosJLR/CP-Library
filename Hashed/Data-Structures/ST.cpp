000 // Todos los rangos son semi-abiertos [a,b)
592 int N, A[MAXN];
936 struct STN{
109     void merge(STN& L, STN& R) {}
916     void operator=(int a) {}
079 };
475 STN ST[4*MAXN];
818 void STB(int id = 1, int l = 0, int r = N){
808     if(r - l < 2){
097         ST[id] = A[l];
161         return;
991     }
348     int m = (l+r)>>1, L = id<<1, R = L|1;
839     STB(L, l, m); STB(R, m, r);
899     ST[id].merge(ST[L], ST[R]);
020 }
914 STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
932     if(x == l && y == r) return ST[id];
045     int m = (l+r)>>1, L = id<<1, R = L|1;
309     if(x >= m) return STQ(x, y, R, m, r);
736     if(y <= m) return STQ(x, y, L, l, m);
289     STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
237     return res.merge(ln, rn), res;
730 }
796 void STU(int p, int x, int id = 1, int l = 0, int r = N){
265     if(r - l < 2){
157         ST[id] = x;
307         return;
193     }
361     int m = (l+r)>>1, L = id<<1, R = L|1;
716     if(p < m) STU(p, x, L, l, m);
640     else STU(p, x, R, m, r);
244     ST[id].merge(ST[L], ST[R]);
660 
-7725083258694542340
