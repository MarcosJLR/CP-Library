000 //Convex Hull Trick
000 
942 struct line{
628     ll m,b;
993 };
278 vector <line> v;
278 
272 double inters(line l1, line l2){
144     return 1.0*(l1.b-l2.b)/(l2.m-l1.m);
488 }
488 
488 //Se deben agregar las rectas en orden decreciente (Lower Hull (buscar min)) o creciente (Upper Hull) de m 
488 //Si se cambian los < por > en add y query se puede hacer al reves
109 void add(line l){
422     int n=v.size();
508     if(n<2) {v.pb(l); return;}
854     if(inters(v[n-1],v[n-2]) < inters(l,v[n-2])) v.pb(l);
275     else{
056         v.pop_back();
401         add(l);
097     }
183 }
183 
183 //Devuelve x que maximice (o minimice) m*x + b para alguna de las rectas (m,b)
469 ll query(ll x){
665     int l = 0, r = v.size(); r--;
542     assert(r != -1);
461     while(l < r){
933         int m = (l+r+1)>>1;
731         if(inters(v[m],v[m-1]) > x) r = m-1;
762         else l = m;
268     }
355     return v[l].m*x + v[l].b;
215 }
8463711183150187215
