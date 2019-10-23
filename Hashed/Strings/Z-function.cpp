528 vector<int> z_function(string &s) {
285     int n = s.length();
435     vector<int> Z(n,0);
660     int l = 0, r = 0;
737     FOR(i,1,n){
754         if (i <= r)
811             Z[i] = min (r - i + 1, Z[i - l]);
244         while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
044             Z[i]++;
031         if (i + Z[i] - 1 > r)
037             l = i, r = i + Z[i] - 1;
250     }
223     return Z;
260 
-1812139740
