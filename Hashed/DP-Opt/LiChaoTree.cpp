945 #include <complex>
945 // Se cambia T dependiendo del caso
968 typedef ll T;
620 typedef complex<T> pt;
737 #define x real
484 #define y imag
315 T dot(pt v, pt w) { return (conj(v)*w).x(); }
422 T f(pt l, T x) { return dot(l, {x, 1}); }
422 // Maximum value a query can have
514 const int MAXQ = 2e5+5;
514 // Init en {0, INF}
607 pt LCT[4*MAXQ];
078 void add(pt nw, int id = 1, int l = 0, int r = MAXQ){
184     int m = (l + r)>>1, L = id<<1, R = L|1;
349     bool lef = f(nw, l) < f(LCT[id], l);
161     bool mid = f(nw, m) < f(LCT[id], m);
941     if(mid){
524         swap(LCT[id], nw);
747     }
623     if(r - l == 1) return;
522     if(lef != mid) add(nw, L, l, m);
210     else add(nw, R, m, r);
427 }
427 // Retorna el minimo mx + b
427 // Para el maximo insertar {-m, -b} y hacer -get(x)
026 T get(int x, int id = 1, int l = 0, int r = MAXQ){
822     int m = (l + r)>>1, L = id<<1, R = L|1;
392     if(r - l == 1) return f(LCT[id], x);
504     if(x < m) return min(f(LCT[id], x), get(x, L, l, m));
832     return min(f(LCT[id], x), get(x, R, m, r));
603 
100856603
