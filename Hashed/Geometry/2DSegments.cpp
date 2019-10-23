555 bool inDisk(pt a, pt, b, pt p){
807     return dot(a-p, b-p) <= 0;
332 }
280 bool onSegment(pt a, pt b, pt p){
656     return orient(a,b,p) == 0 && inDisk(a,b,p);
282 }
112 bool properInter(pt a, pt b, pt c, pt d, pt &out){
532     double oa = orient(c, d, a),
621            ob = orient(c, d, b);
311            oc = orient(a, b, c);
066            od = orient(a, b, d);
267     if(oa*ob < 0 && oc*od < 0){
551         out = (a*ob - b*oa) / (ob - oa);
655         return true;
069     }
432     return false;
663 }
016 struct cmpX{
480     bool operator()(pt a, pt b){
723         return mkt(a.x, a.y) < mkt(b.x, b.y);
034     }
609 };
475 set <pt,cmpX> inters(pt a, pt b, pt c, pt d){
423     pt out;
872     if(properInter(a, b, c, d, out)) return {out};
774     set<pt,cmpX> s;
407     if(onSegment(c, d, a)) s.insert(a);
844     if(onSegment(c, d, b)) s.insert(b);
039     if(onSegment(a, b, c)) s.insert(c);
908     if(onSegment(a, b, d)) s.insert(d);
761     return s; 
379 }
194 double segPoint(pt a, pt b, pt p){
931     if(a != b){
945         line l(a, b);
504         if(l.cmpProj(a, p) && l.cmpProj(p, b))
416             return l.dist(p);
022     }
371     return min( abs(p-a), abs(p-b) );
761 }
086 double segSeg(pt a, pt b, pt c, pt d){
351     pt aux;
281     if(properInter(a, b, c, d, aux)) return 0;
404     return min({segPoint(a, b, c), segPoint(a, b, d),
685                 segPoint(c, d, a), segPoint(c, d, b)});
517 }
-116832483
