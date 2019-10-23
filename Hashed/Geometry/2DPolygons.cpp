617 double areaPoly(vector<pt> &p){
466     double area = 0.0;
628     int n = p.size();
373     FOR(i,0,n)
488         area += cross(p[i], p[(i+1)%n]);
855     return abs(area) / 2.0;
933 }
363 bool above(pt a, pt p){
313     return p.y >= a.y;
997 }
122 bool crossesRay(pt a, pt p, pt q){
566     return (above(a,q) - above(a,p)) * (orient(a, p, q) > 0);
252 }
252 // if strict return 0 if a is on the boundary
584 bool inPoly(vector<pt> &p, pt a, bool strict = 1){
201     int numCross = 0, n = p.size();
047     FOR(i,0,n){
288         if(onSegment(p[i], p[(i+1)%n], a))
004             return !strict;
444         numCross += crossesRay(a, p[i], p[(i+1)%n]);
315     }
756     return numCross & 1;
431 
59685431
