000 // String matching KMP-Algorithm
000 
750 vi preff(string &s){
865 	int n = s.length();
488 	vi P(n);
395 	FOR(i,1,n){
570 		int j = P[i-1];
266 		while(j>0 && s[i]!=s[j]) j = P[j-1];
607 		j += s[i] == s[j];
673 		P[i] = j;
221 	}
302 	return P;
963 }
963 
634 vi KMP(string &s, string &t){
177 	int n = s.length();
471 	int m = t.length();
254 	int j = 0;
635 	vi P = preff(t), ans;
637 	FOR(i,0,n){
357 		while(j>0 && s[i]!=t[j]) j = P[j-1];
865 		j += s[i] == t[j];
916 		if(j==m) ans.pb(i-m+1), j = P[j-1];
373 	}
107 	return ans;
152 }
-4723541319847155848
