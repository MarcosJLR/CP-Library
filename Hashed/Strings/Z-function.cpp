100 vector<int> z_function(string &s) {
234     int n = s.length();
420     vector<int> Z(n,0);
796     int l = 0, r = 0;
761     FOR(i,1,n){
420         if (i <= r)
985             Z[i] = min (r - i + 1, Z[i - l]);
488         while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
472             Z[i]++;
426         if (i + Z[i] - 1 > r)
159             l = i, r = i + Z[i] - 1;
456     }
698     return Z;
788 
-3668944363980507212
