// String matching KMP-Algorithm

#define vector<int> vi;
#define FOR(i,n,m) for(int i=0; i<(int)m; i++)
#define push_back pb

vi preff(string &s){
	int n = s.length();
	vi P(n);
	FOR(i,1,n){
		int j = P[i-1];
		while(j>0 && s[i]!=s[j]) j = P[j-1];
		j += s[i] == s[j];
		P[i] = j;
	}
	return P;
}

vi KMP(string &s, string &t){
	int n = s.length();
	int m = t.length();
	int j = 0;
	vi P = preff(s), ans;
	FOR(i,0,n){
		while(j>0 && s[i]!=t[j]) j = P[j-1];
		j += s[i] == t[j];
		if(j==m) ans.pb(i-m+1), j = P[j-1];
	}
	return ans;
}