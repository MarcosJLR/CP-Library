000 // Todos los rangos son semi-abiertos [a,b)
149 int N, A[MAXN];
674 struct STN{
657     void merge(STN& L, STN& R) {}
266     void operator=(ll a) {}
701 };
240 STN ST[4*MAXN];
277 ll lzy[4*MAXN];
456 void STB(int id = 1, int l = 0, int r = N){
921     if(r - l < 2){
898         ST[id] = A[l];
291         return;
937     }
136     int m = (l+r)>>1, L = id<<1, R = L|1;
536     STB(L, l, m); STB(R, m, r);
727     ST[id].merge(ST[L], ST[R]);
858 }
858 // Actualiza el nodo y guarda en lazy
286 void upd(int id, int l, int r, ll x){
681     lzy[id] += x;
818     ST[id].val += (r - l)*x;
951 }
951 // Propaga el update en lazy
307 void shift(int id, int l, int r){
376     int m = (l+r)>>1, L = id<<1, R = L|1;
000     upd(L, l, m, lzy[id]);
496     upd(R, m, r, lzy[id]);
025     lzy[id] = 0;
020 }
979 STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
579     if(x == l && y == r) return ST[id];
061     shift(id, l, r);
120     int m = (l+r)>>1, L = id<<1, R = L|1;
919     if(x >= m) return STQ(x, y, R, m, r);
580     if(y <= m) return STQ(x, y, L, l, m);
836     STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
776     return res.merge(ln, rn), res;
986 }
491 void STU(int x, int y, int v, int id = 1, int l = 0, int r = N){
222     if(x >= r || y <= l) return;
440     if(x <= l && y >= r) {
577         upd(id, l, r, v);
263         return;
052     }
265     shift(id, l, r);
238     int m = (l+r)>>1, L = id<<1, R = L|1;
618     STU(x, y, v, L, l, m);
056     STU(x, y, v, R, m, r);
109     ST[id].merge(ST[L], ST[R]);
280 
463156280
