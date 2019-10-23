928 typedef double T;
625 typedef complex<T> pt;
530 #define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
426 #define y imag() 
200 #define mkt make_tuple
758 const double PI = 2*acos(0.0);
758 
758 
531 int sgn(T a) {return (a < 0) - (a > 0);}
342 T sq(pt p) {return p.x*p.x + p.y*p.y;}
472 double abs(pt p) {return sqrt(sq(p));}
472 
472 // Transformations
099 pt translate(pt v, pt p) {return p+v;} //Move p through v
682 pt scale(pt c, double fact, pt p) {return c + (p - c)*fact;}
906 pt rot(pt p, double a) {return p * polar(1.0, a);}
600 pt perp(pt p) {return {-p.y, p.x};}
600 
600 // Arbitrary linear Transformation f given f(p) and f(q)
451 pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq){
189     return fp + (r-p) * (fq-fp) / (q-p);
530 }
530 
530 // Products
402 T dot(pt v, pt w) {return (conj(v)*w).x;}
034 T cross(pt v, pt w) {return (conj(v)*w).y;}
034 
034 // Orientation
646 bool isPerp(pt v, pt w) {return dot(v, w) == 0;}
249 double angle(pt v, pt w){ // Range [0, pi]
005     double cosTh = dot(v,w) / abs(v) / abs(w);
243     return acos(max(-1.0, min(1.0, cosTh)));
742 }
742 // < 0 c is left of ab, > 0 c is right, = 0 colinear
927 T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
814 bool inAngle(pt a, pt b, pt c, pt p){ // P is in angle BAC
897     assert(orient(a,b,c) != 0);
270     if(orient(a,b,c) < 0) swap(b, c);
432     return orient(a, b, p) >= p && orient(a, c, p) <= 0;
365 }
180 double orientAngle(pt a, pt b, pt c){
494     return (orient(a,b,c) >= 0) ? 
319             angle(b-a,c-a) : 2*PI - angle(b-a,c-a);
792 }
743 bool isConvex(vector<pt> p){
216     bool hasPos = 0, hasNeg = 0;
058     int n = p.size();
560     FOR(i,0,n){
620         int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
705         if(o > 0) hasPos = 1;
307         if(o < 0) hasNeg = 1;
473     }
776     return !(hasPos && hasNeg);
052 }
052 
052 // Polar Sort
102 bool half(pt p){
262     assert(p.x != 0 || p.y != 0);
927     return p.y > 0 || (p.y == 0 && p.x < 0);
449 }
683 void polarSort(vector<pt> &v) {
711     sort(all(v), [](pt v, pt w) {
192         return mkt(half(v), 0, sq(v)) < 
172                mkt(half(w), cross(v, w), sq(w));
877     }
634 
422103634
