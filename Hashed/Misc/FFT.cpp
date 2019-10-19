346 const double TAU = 4.0 * acos(0);
699 const int MAXN = 1 << 15; // ONLY POWERS OF 2!!!
651 typedef double ld;
854 struct cd{
327     ld x, y;
213     cd(ld x, ld y) : x(x), y(y) {}
798     cd(ld z = 0) : x(z), y(0) {}
490     cd operator +(cd z) {return cd(x + z.x, y + z.y);}
010     cd operator -(cd z) {return cd(x - z.x, y - z.y);}
106     cd operator *(cd z) {return cd(x*z.x - y*z.y, x*z.y + y*z.x);}
929     cd operator /(ld z) {return cd(x/z, y/z);}
439 };
543 void FFT(cd *a, int rev){
992     int n = MAXN;
416     for(int i = 1, j = 0; i < n; i++){
726         int k = n >> 1;
002         for(; j & k; k >>= 1) j ^= k;
363         j ^= k;
122         if(i < j) swap(a[i], a[j]);
219     } 
770     for(int s = 2, ds = 1; s <= n; ds = s, s <<= 1){
901         ld ang = TAU / s * rev;
896         cd wn(cos(ang), sin(ang));
607         for(int i = 0; i < n; i += s){
433             cd w(1), t;
693             for(int j = i; j < i + ds; j++, w = w*wn){
694                 cd u = a[j], v = a[j+ds] * w;
686                 a[j] = u + v; 
338                 a[j+ds] = u - v;
783             }
401         }
013     }
920     if(rev == -1)
268         FOR(i,0,n) a[i] = a[i] / n;
362 }
315 void mult(cd *p, cd *q, cd *r){
039     FFT(p,1); FFT(q,1);
162     FOR(i,0,MAXN) r[i] = p[i]*q[i];
834     FFT(r,-1);
059 }
3448663106045290059
