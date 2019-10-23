575 typedef vector<int> vi;
575 
984 vi m1(){
781     vi d1(n);
274     for (int i = 0, l = 0, r = -1; i < n; i++) {
638         int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
223         while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
068             k++;
972         }
441         d1[i] = k--;
823         if (i + k > r) {
094             l = i - k;
459             r = i + k;
512         }
611     }
370     return d1;
647 }
647 
986 vi m2(){
196     vi d2(n);
360     for (int i = 0, l = 0, r = -1; i < n; i++) {
610         int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
527         while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
613             k++;
567         }
613         d2[i] = k--;
170         if (i + k > r) {
891             l = i - k - 1;
721             r = i + k ;
405         }
577     }
502     return d2;
679 }
679 
679 
1475311679
