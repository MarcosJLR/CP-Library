645 struct STN{
483     STN *l, *r;
425     int val;
514     STN(int val) : l(0), r(0), val(val) {}
377     STN(STN *l, STN *r) : l(l), r(r), val(0){
460         if(l) val += l->val;
695         if(r) val += r->val;
762     }
053 };
053 
606 int N, A[MAXN];
606 
845 STN* STB(int l = 0, int r = N){
128     if(r - l < 2) return new STN(A[l]);
599     int m = (l+r)>>1;
653     return new STN(STB(l, m), STB(m, r));
698 }
654 int STQ(int x, int y, STN* v, int l = 0, int r = N){
868     if(l >= r || x >= y) return 0;
472     if(x == l && y == r) return v->val;
532     int m = (l+r)>>1;
023     return STQ(x, min(y, m), v->l, l, m)
182          + STQ(max(x, m), y, v->r, m, r);
171 }
292 STN* STU(int p, int x, STN *v, int l = 0, int r = N){
129     if(r - l < 2) return new STN(x);
212     int m = (l+r)>>1;
033     if(p < m)
200         return new STN(STU(p, x, v->l, l, m), v->r);
718     else
253         return new STN(v->l, STU(p, x, v->r, m, r));
723 }
56166737623969723
