267 struct frac{
347 	ll p,q;
276 	frac(ll p=0, ll q=1):p(p),q(q) {norm();}
149 	ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a; }
084 	void norm(){
107 		ll a = gcd(p,q);
750 		if(a) p/=a, q/=a;
435 		else q=1;
442 		if (q<0) q=-q, p=-p;}
123 	frac operator+(const frac& o){
252 		ll a = gcd(q,o.q);
710 		return frac(p*(o.q/a)+o.p*(q/a), q*(o.q/a));}
234 	frac operator-(const frac& o){
366 		ll a = gcd(q,o.q);
831 		return frac(p*(o.q/a)-o.p*(q/a), q*(o.q/a));}
843 	frac operator*(frac o){
806 		ll a = gcd(q,o.p), b = gcd(o.q,p);
246 		return frac((p/b)*(o.p/a), (q/a)*(o.q/b));}
012 	frac operator/(frac o){
336 		ll a = gcd(q,o.q), b = gcd(o.p,p);
598 		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));}
619 	bool operator<(const frac &o) const{return p*o.q < o.p*q;}
801 	bool operator==(frac o){return p==o.p && q==o.q;}
905 }
-950489095
