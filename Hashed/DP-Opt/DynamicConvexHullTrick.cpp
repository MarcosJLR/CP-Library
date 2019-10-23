000 //Contenedor que puede agregar lineas mx + b y preguntar max x
000 
839 struct Line{
708     mutable ll m, b, p;
405     bool operator<(const Line& o) const { return m < o.m; }
862     bool operator<(ll x) const { return p < x; }
959 };
959 
777 struct LineContainer : multiset<Line, less<>> {
082     const ll inf = LLONG_MAX;
082     // (para doubles usar inf = 1/.0, div(a, b) = a / b;)
333     ll div(ll a, ll b){
714         return a / b - ((a ^ b) < 0 && a % b);
055     }
349     bool isect(iterator x, iterator y){
859         if(y == end()) { x->p = inf; return false; }
091         if(x->m == y->m) x->p = x->b > y->b ? inf : -inf;
127         else x->p = div(y->b - x->b, x->m - y->m);
586         return x->p >= y->p;
075     }
137     void add(ll m, ll b){
052         auto z = insert({m, b, 0}), y = z++, x = y;
813         while(isect(y, z)) z = erase(z);
350         if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
328         while((y = x) != begin() && (--x)->p >= y->p)
791             isect(x, erase(y));
278     }
235     ll query(ll x){
381         assert(!empty());
802         auto l = *lower_bound(x);
764         return l.m * x + l.b;
409     }
067 }
-1327688933
