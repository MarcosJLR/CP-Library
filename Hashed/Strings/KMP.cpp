000 // String matching KMP-Algorithm
247 vi preff(string &s){
026 	int n = s.length();
793 	vi P(n);
384 	FOR(i,1,n){
664 		int j = P[i-1];
247 		while(j>0 && s[i]!=s[j]) j = P[j-1];
050 		j += s[i] == s[j];
016 		P[i] = j;
075 	}
072 	return P;
277 }
743 vi KMP(string &s, string &t){
551 	int n = s.length();
409 	int m = t.length();
720 	int j = 0;
272 	vi P = preff(t), ans;
082 	FOR(i,0,n){
073 		while(j>0 && s[i]!=t[j]) j = P[j-1];
189 		j += s[i] == t[j];
242 		if(j==m) ans.pb(i-m+1), j = P[j-1];
530 	}
243 	return ans;
461 }
2145626461
