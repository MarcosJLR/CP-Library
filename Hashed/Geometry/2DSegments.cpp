693 bool inDisk(pt a, pt, b, pt p){
053     return dot(a-p, b-p) <= 0;
201 }
202 bool onSegment(pt a, pt b, pt p){
981     return orient(a,b,p) == 0 && inDisk(a,b,p);
782 }
912 bool properInter(pt a, pt b, pt c, pt d, pt &out){
103     double oa = orient(c, d, a),
413            ob = orient(c, d, b);
084            oc = orient(a, b, c);
898            od = orient(a, b, d);
967     if(oa*ob < 0 && oc*od < 0){
543         out = (a*ob - b*oa) / (ob - oa);
247         return true;
232     }
979     return false;
116 }
094 struct cmpX{
869     bool operator()(pt a, pt b){
981         return mkt(a.x, a.y) < mkt(b.x, b.y);
895     }
792 };
405 set <pt,cmpX> inters(pt a, pt b, pt c, pt d){
653     pt out;
567     if(properInter(a, b, c, d, out)) return {out};
184     set<pt,cmpX> s;
870     if(onSegment(c, d, a)) s.insert(a);
036     if(onSegment(c, d, b)) s.insert(b);
714     if(onSegment(a, b, c)) s.insert(c);
271     if(onSegment(a, b, d)) s.insert(d);
522     return s; 
955 }
499 double segPoint(pt a, pt b, pt p){
464     if(a != b){
156         line l(a, b);
899         if(l.cmpProj(a, p) && l.cmpProj(p, b))
632             return l.dist(p);
804     }
732     return min( abs(p-a), abs(p-b) );
442 }
449 double segSeg(pt a, pt b, pt c, pt d){
627     pt aux;
393     if(properInter(a, b, c, d, aux)) return 0;
896     return min({segPoint(a, b, c), segPoint(a, b, d),
892                 segPoint(c, d, a), segPoint(c, d, b)});
325 }
-9195526078012979675
