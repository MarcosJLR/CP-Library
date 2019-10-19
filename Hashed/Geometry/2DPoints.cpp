190 typedef double T;
019 typedef complex<T> pt;
880 #define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
754 #define y imag() 
866 #define mkt make_tuple
350 const double PI = 2*acos(0.0);
350 
350 
916 int sgn(T a) {return (a < 0) - (a > 0);}
528 T sq(pt p) {return p.x*p.x + p.y*p.y;}
148 double abs(pt p) {return sqrt(sq(p));}
148 
148 // Transformations
535 pt translate(pt v, pt p) {return p+v;} //Move p through v
146 pt scale(pt c, double fact, pt p) {return c + (p - c)*fact;}
316 pt rot(pt p, double a) {return p * polar(1.0, a);}
322 pt perp(pt p) {return {-p.y, p.x};}
322 
322 // Arbitrary linear Transformation f given f(p) and f(q)
301 pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq){
538     return fp + (r-p) * (fq-fp) / (q-p);
153 }
153 
153 // Products
935 T dot(pt v, pt w) {return (conj(v)*w).x;}
418 T cross(pt v, pt w) {return (conj(v)*w).y;}
418 
418 // Orientation
106 bool isPerp(pt v, pt w) {return dot(v, w) == 0;}
543 double angle(pt v, pt w){ // Range [0, pi]
450     double cosTh = dot(v,w) / abs(v) / abs(w);
571     return acos(max(-1.0, min(1.0, cosTh)));
837 }
837 // < 0 c is left of ab, > 0 c is right, = 0 colinear
153 T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
227 bool inAngle(pt a, pt b, pt c, pt p){ // P is in angle BAC
357     assert(orient(a,b,c) != 0);
215     if(orient(a,b,c) < 0) swap(b, c);
728     return orient(a, b, p) >= p && orient(a, c, p) <= 0;
627 }
464 double orientAngle(pt a, pt b, pt c){
340     return (orient(a,b,c) >= 0) ? 
199             angle(b-a,c-a) : 2*PI - angle(b-a,c-a);
092 }
155 bool isConvex(vector<pt> p){
639     bool hasPos = 0, hasNeg = 0;
654     int n = p.size();
973     FOR(i,0,n){
697         int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
655         if(o > 0) hasPos = 1;
952         if(o < 0) hasNeg = 1;
812     }
454     return !(hasPos && hasNeg);
093 }
093 
093 // Polar Sort
036 bool half(pt p){
282     assert(p.x != 0 || p.y != 0);
990     return p.y > 0 || (p.y == 0 && p.x < 0);
740 }
106 void polarSort(vector<pt> &v) {
573     sort(all(v), [](pt v, pt w) {
594         return mkt(half(v), 0, sq(v)) < 
277                mkt(half(w), cross(v, w), sq(w));
987     }
938 
8784931721569666938
