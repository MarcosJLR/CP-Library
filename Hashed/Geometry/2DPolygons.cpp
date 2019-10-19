386 double areaPoly(vector<pt> &p){
598     double area = 0.0;
830     int n = p.size();
021     FOR(i,0,n)
474         area += cross(p[i], p[(i+1)%n]);
057     return abs(area) / 2.0;
847 }
561 bool above(pt a, pt p){
051     return p.y >= a.y;
067 }
519 bool crossesRay(pt a, pt p, pt q){
480     return (above(a,q) - above(a,p)) * (orient(a, p, q) > 0);
221 }
221 // if strict return 0 if a is on the boundary
637 bool inPoly(vector<pt> &p, pt a, bool strict = 1){
073     int numCross = 0, n = p.size();
484     FOR(i,0,n){
589         if(onSegment(p[i], p[(i+1)%n], a))
235             return !strict;
469         numCross += crossesRay(a, p[i], p[(i+1)%n]);
868     }
213     return numCross & 1;
148 
9158691955039218148
