783 struct frac{
304 	ll p,q;
292 	frac(ll p=0, ll q=1):p(p),q(q) {norm();}
158 	ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a; }
557 	void norm(){
991 		ll a = gcd(p,q);
162 		if(a) p/=a, q/=a;
827 		else q=1;
320 		if (q<0) q=-q, p=-p;}
849 	frac operator+(const frac& o){
564 		ll a = gcd(q,o.q);
227 		return frac(p*(o.q/a)+o.p*(q/a), q*(o.q/a));}
456 	frac operator-(const frac& o){
242 		ll a = gcd(q,o.q);
265 		return frac(p*(o.q/a)-o.p*(q/a), q*(o.q/a));}
187 	frac operator*(frac o){
203 		ll a = gcd(q,o.p), b = gcd(o.q,p);
335 		return frac((p/b)*(o.p/a), (q/a)*(o.q/b));}
500 	frac operator/(frac o){
226 		ll a = gcd(q,o.q), b = gcd(o.p,p);
408 		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));}
945 	bool operator<(const frac &o) const{return p*o.q < o.p*q;}
942 	bool operator==(frac o){return p==o.p && q==o.q;}
386 }
-89445605368403614
