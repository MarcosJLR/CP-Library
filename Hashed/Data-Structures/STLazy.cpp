000 // Todos los rangos son semi-abiertos [a,b)
235 int N, A[MAXN];
895 struct STN{
783     void merge(STN& L, STN& R) {}
808     void operator=(ll a) {}
670 };
023 STN ST[4*MAXN];
871 ll lzy[4*MAXN];
422 void STB(int id = 1, int l = 0, int r = N){
708     if(r - l < 2){
060         ST[id] = A[l];
011         return;
184     }
677     int m = (l+r)>>1, L = id<<1, R = L|1;
456     STB(L, l, m); STB(R, m, r);
586     ST[id].merge(ST[L], ST[R]);
917 }
917 // Actualiza el nodo y guarda en lazy
158 void upd(int id, int l, int r, ll x){
770     lzy[id] += x;
738     ST[id].val += (r - l)*x;
712 }
712 // Propaga el update en lazy
712 void shift(int id, int l, int r){
019     int m = (l+r)>>1, L = id<<1, R = L|1;
242     upd(L, l, m, lzy[id]);
839     upd(R, m, r, lzy[id]);
315     lzy[id] = 0;
632 }
128 STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
460     if(x == l && y == r) return ST[id];
945     shift(id, l, r);
034     int m = (l+r)>>1, L = id<<1, R = L|1;
603     if(x >= m) return STQ(x, y, R, m, r);
773     if(y <= m) return STQ(x, y, L, l, m);
231     STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
193     return res.merge(ln, rn), res;
109 }
637 void STU(int x, int y, int v, int id = 1, int l = 0, int r = N){
794     if(x >= r || y <= l) return;
150     if(x <= l && y >= r) {
337         upd(id, l, r, v);
204         return;
606     }
978     shift(id, l, r);
177     int m = (l+r)>>1, L = id<<1, R = L|1;
825     STU(x, y, v, L, l, m);
513     STU(x, y, v, R, m, r);
873     ST[id].merge(ST[L], ST[R]);
715 
9202177397996687715
