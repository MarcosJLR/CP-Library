633 struct STN{
350     STN *l, *r;
182     int val;
409     STN(int val) : l(0), r(0), val(val) {}
188     STN(STN *l, STN *r) : l(l), r(r), val(0){
748         if(l) val += l->val;
635         if(r) val += r->val;
413     }
066 };
044 int N, A[MAXN];
057 STN* STB(int l = 0, int r = N){
907     if(r - l < 2) return new STN(A[l]);
294     int m = (l+r)>>1;
918     return new STN(STB(l, m), STB(m, r));
160 }
703 int STQ(int x, int y, STN* v, int l = 0, int r = N){
229     if(l >= r || x >= y) return 0;
631     if(x == l && y == r) return v->val;
698     int m = (l+r)>>1;
375     return STQ(x, min(y, m), v->l, l, m)
273          + STQ(max(x, m), y, v->r, m, r);
930 }
932 STN* STU(int p, int x, STN *v, int l = 0, int r = N){
064     if(r - l < 2) return new STN(x);
764     int m = (l+r)>>1;
579     if(p < m)
273         return new STN(STU(p, x, v->l, l, m), v->r);
870     else
381         return new STN(v->l, STU(p, x, v->r, m, r));
827 }
1566195827
