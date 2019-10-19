867 struct line {
207     pt v; T c;
207     // Direction v, Offset c
060     line(pt v, T c) : v(v), c(c) {}
060     // Eq ax + by = c
747     line(T a, T b, T c) : v(b, -a), c(c) {}
747     // Points p and q
864     line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
864     // < 0 right, = 0 inline, > 0 left
045     T side(pt p) {return cross(v, p) - c;}
949     double dist(pt p) {return abs(side(p)) / abs(v);}
375     double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
529     line perpThrough(pt p) {return {p, p + perp(v)};}
244     bool cmpProj(pt p, pt q) {return dot(v,p) < dot(v,q);}
612     line translate(pt t) {return {v, c + cross(v, t)};}
121     line shiftLeft(double d) {return {v, c + d*abs(v)};}
901     pt proj(pt p) {return p - perp(v) * side(p) / sq(v);}
978     pt refl(pt p) {return p - perp(v) * 2 * side(p) / sq(v);}
987 };
987 
692 bool inter(line l1, line l2, pt &out){
503     T d = cross(l1.v, l2.v);
883     if(d == 0) return false;
142     out = (l2.v*l1.c - l1.v*l2.c) / d;
036     return true;
488 }
488 
488 // Interior: bisector pointing between 2 directions
998 line bisector(line l1, line l2, bool interior){
082     assert(cross(l1.v, l2.v) != 0);
350     double sign = interior ? 1 : -1;
439     return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
592             l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
636 }
-2434096907699059364
