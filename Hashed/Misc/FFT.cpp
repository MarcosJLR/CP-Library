817 const double TAU = 4.0 * acos(0);
769 const int MAXN = 1 << 15; // ONLY POWERS OF 2!!!
097 typedef double ld;
399 struct cd{
212     ld x, y;
890     cd(ld x, ld y) : x(x), y(y) {}
164     cd(ld z = 0) : x(z), y(0) {}
919     cd operator +(cd z) {return cd(x + z.x, y + z.y);}
335     cd operator -(cd z) {return cd(x - z.x, y - z.y);}
686     cd operator *(cd z) {return cd(x*z.x - y*z.y, x*z.y + y*z.x);}
051     cd operator /(ld z) {return cd(x/z, y/z);}
905 };
685 void FFT(cd *a, int rev){
559     int n = MAXN;
089     for(int i = 1, j = 0; i < n; i++){
806         int k = n >> 1;
335         for(; j & k; k >>= 1) j ^= k;
176         j ^= k;
077         if(i < j) swap(a[i], a[j]);
084     } 
405     for(int s = 2, ds = 1; s <= n; ds = s, s <<= 1){
824         ld ang = TAU / s * rev;
612         cd wn(cos(ang), sin(ang));
310         for(int i = 0; i < n; i += s){
177             cd w(1), t;
411             for(int j = i; j < i + ds; j++, w = w*wn){
876                 cd u = a[j], v = a[j+ds] * w;
016                 a[j] = u + v; 
140                 a[j+ds] = u - v;
064             }
857         }
010     }
804     if(rev == -1)
987         FOR(i,0,n) a[i] = a[i] / n;
996 }
489 void mult(cd *p, cd *q, cd *r){
468     FFT(p,1); FFT(q,1);
433     FOR(i,0,MAXN) r[i] = p[i]*q[i];
664     FFT(r,-1);
416 }
-134500584
