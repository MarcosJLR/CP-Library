902 #include <complex>
902 
902 // Se cambia T dependiendo del caso
131 typedef ll T;
372 typedef complex<T> pt;
372 
234 #define x real
937 #define y imag
937 
425 T dot(pt v, pt w) { return (conj(v)*w).x(); }
294 T f(pt l, T x) { return dot(l, {x, 1}); }
294 
294 // Maximum value a query can have
420 const int MAXQ = 2e5+5;
420 
420 // Init en {0, INF}
882 pt LCT[4*MAXQ];
662 void add(pt nw, int id = 1, int l = 0, int r = MAXQ){
702     int m = (l + r)>>1, L = id<<1, R = L|1;
533     bool lef = f(nw, l) < f(LCT[id], l);
026     bool mid = f(nw, m) < f(LCT[id], m);
933     if(mid){
906         swap(LCT[id], nw);
838     }
969     if(r - l == 1) return;
709     if(lef != mid) add(nw, L, l, m);
421     else add(nw, R, m, r);
415 }
415 
415 // Retorna el minimo mx + b
415 // Para el maximo insertar {-m, -b} y hacer -get(x)
757 T get(int x, int id = 1, int l = 0, int r = MAXQ){
070     int m = (l + r)>>1, L = id<<1, R = L|1;
131     if(r - l == 1) return f(LCT[id], x);
361     if(x < m) return min(f(LCT[id], x), get(x, L, l, m));
376     return min(f(LCT[id], x), get(x, R, m, r));
676 
5529709836885637676
