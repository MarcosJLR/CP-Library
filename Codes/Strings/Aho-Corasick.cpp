const int MAXAL = 26; // Size of alphabet

struct node{
	node* nxt[MAXAL]; // Array of pointers to childs on trie
	bool end; // 1 if cur node is end node or a sufix parent is end node
	int c; // parent node -- c -- > current node
	node* p; // Parent node
	node* sl; // Sufix Link
	node* ol; // Output Link
	int idx; // Index of the string the current node represents
	node(): end(false), c(0), p(NULL), sl(NULL), ol(NULL), idx(-1){
		ms(nxt, 0);
	}
};

// Root of trie
typedef node* trie;
trie root = new node();

// Be careful with repeated patterns
void add(trie root, const string& s, int k){
	trie t = root;
	FOR(i, 0, s.size()){
		int v = (int) s[i]; // MAP CHARACTERS TO INT 
		if(!t->nxt[v]){
			trie son = new node();
			son->c = v;
			son->p = t;
			t -> nxt[v] = son;
		}
		t = t->nxt[v];
		if(i == (int)s.size()-1){
			t->end = true;
			t->idx = k;
		}
	}
}

void buildLinks(trie root){
	queue<trie> q;
	q.push(root);
	while(!q.empty()){
		trie t = q.front(); q.pop();
		trie w = t->p;
		if(w){
			w = w->sl;
			while(w && !w->nxt[t->c]) w = w->sl;
			t->sl  = w ? w->nxt[t->c] : root;
			t->end = t->end || t->sl->end;
			t->ol = (t->sl->idx == -1) ? t->sl->ol : t->sl;
		}
		FOR(c, 0, MAXAL) if(t->nxt[c]) q.push(t->nxt[c]); 
	}
}

// One of the next to should be used

set<int> subString(trie root, string& T){
	int n = T.size();
	trie x = root;
	set<int> ans;
	FOR(i, 0, n){
		int v = (int) T[i]; // MAP CHARACTERS TO INT 
		while(x && !x->nxt[v])
			x = x->sl;
		x = x ? x->nxt[v] : root;
		trie y = x;
		while(y){
			if(y->idx != -1) ans.insert(y->idx);
			y = y -> ol;
		}
	}
	return ans;
}

bool check(trie root, string &T){
	int n = T.size();
	trie x = root;
	FOR(i, 0, n){
		int v = (int) T[i]; // MAP CHARACTERS TO INT 
		while(x && !x->nxt[v])
			x = x->sl;
		x = x ? x->nxt[v] : root;
		if(x->end) return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////////

// Primer ocurrencia del final de un string
// Calcular todas y ver cual es mejor si 
// se necesita la primera
ii first_ocurrence(string& T){
	int n = T.size();
	trie x = root;
	FOR(i, 0, n){
		int v = T[i];
		while(x && !x->nxt[v])
			x = x-> sl;
		x = x ? x->nxt[v] : root;
		if(x->idx != -1) return {i, x->idx};
		if(x->ol && x->ol->idx != -1) return {i, x->ol->idx};
	}
	return {-1, -1};
}