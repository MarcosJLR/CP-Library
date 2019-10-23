000 //Convex Hull Trick
000 
645 struct line{
451     ll m,b;
618 };
104 vector <line> v;
104 
370 double inters(line l1, line l2){
753     return 1.0*(l1.b-l2.b)/(l2.m-l1.m);
695 }
695 
695 //Se deben agregar las rectas en orden decreciente (Lower Hull (buscar min)) o creciente (Upper Hull) de m 
695 //Si se cambian los < por > en add y query se puede hacer al reves
632 void add(line l){
315     int n=v.size();
260     if(n<2) {v.pb(l); return;}
997     if(inters(v[n-1],v[n-2]) < inters(l,v[n-2])) v.pb(l);
124     else{
418         v.pop_back();
013         add(l);
527     }
491 }
491 
491 //Devuelve x que maximice (o minimice) m*x + b para alguna de las rectas (m,b)
525 ll query(ll x){
772     int l = 0, r = v.size(); r--;
422     assert(r != -1);
197     while(l < r){
761         int m = (l+r+1)>>1;
286         if(inters(v[m],v[m-1]) > x) r = m-1;
199         else l = m;
844     }
395     return v[l].m*x + v[l].b;
029 }
-1195034971
