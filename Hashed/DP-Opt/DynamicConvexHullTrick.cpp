000 //Contenedor que puede agregar lineas mx + b y preguntar max x
000 
802 struct Line{
978     mutable ll m, b, p;
481     bool operator<(const Line& o) const { return m < o.m; }
743     bool operator<(ll x) const { return p < x; }
951 };
951 
145 struct LineContainer : multiset<Line, less<>> {
281     const ll inf = LLONG_MAX;
281     // (para doubles usar inf = 1/.0, div(a, b) = a / b;)
818     ll div(ll a, ll b){
908         return a / b - ((a ^ b) < 0 && a % b);
449     }
289     bool isect(iterator x, iterator y){
675         if(y == end()) { x->p = inf; return false; }
352         if(x->m == y->m) x->p = x->b > y->b ? inf : -inf;
422         else x->p = div(y->b - x->b, x->m - y->m);
141         return x->p >= y->p;
455     }
975     void add(ll m, ll b){
536         auto z = insert({m, b, 0}), y = z++, x = y;
787         while(isect(y, z)) z = erase(z);
781         if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
729         while((y = x) != begin() && (--x)->p >= y->p)
719             isect(x, erase(y));
268     }
820     ll query(ll x){
921         assert(!empty());
941         auto l = *lower_bound(x);
682         return l.m * x + l.b;
070     }
032 }
-2291913629705544968
