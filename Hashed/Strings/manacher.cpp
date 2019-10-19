135 typedef vector<int> vi;
135 
639 vi m1(){
112     vi d1(n);
787     for (int i = 0, l = 0, r = -1; i < n; i++) {
390         int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
881         while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
926             k++;
662         }
975         d1[i] = k--;
378         if (i + k > r) {
051             l = i - k;
167             r = i + k;
071         }
196     }
362     return d1;
107 }
107 
827 vi m2(){
755     vi d2(n);
414     for (int i = 0, l = 0, r = -1; i < n; i++) {
538         int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
272         while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
288             k++;
437         }
222         d2[i] = k--;
052         if (i + k > r) {
718             l = i - k - 1;
755             r = i + k ;
101         }
887     }
237     return d2;
333 }
333 
333 
-7328996711659808667
