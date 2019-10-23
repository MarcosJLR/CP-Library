645 struct line {
755     pt v; T c;
755     // Direction v, Offset c
516     line(pt v, T c) : v(v), c(c) {}
516     // Eq ax + by = c
660     line(T a, T b, T c) : v(b, -a), c(c) {}
660     // Points p and q
473     line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
473     // < 0 right, = 0 inline, > 0 left
853     T side(pt p) {return cross(v, p) - c;}
583     double dist(pt p) {return abs(side(p)) / abs(v);}
196     double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
511     line perpThrough(pt p) {return {p, p + perp(v)};}
161     bool cmpProj(pt p, pt q) {return dot(v,p) < dot(v,q);}
285     line translate(pt t) {return {v, c + cross(v, t)};}
992     line shiftLeft(double d) {return {v, c + d*abs(v)};}
531     pt proj(pt p) {return p - perp(v) * side(p) / sq(v);}
163     pt refl(pt p) {return p - perp(v) * 2 * side(p) / sq(v);}
264 };
806 bool inter(line l1, line l2, pt &out){
759     T d = cross(l1.v, l2.v);
099     if(d == 0) return false;
958     out = (l2.v*l1.c - l1.v*l2.c) / d;
599     return true;
571 }
571 // Interior: bisector pointing between 2 directions
942 line bisector(line l1, line l2, bool interior){
053     assert(cross(l1.v, l2.v) != 0);
543     double sign = interior ? 1 : -1;
615     return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
667             l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
064 }
-1276088936
