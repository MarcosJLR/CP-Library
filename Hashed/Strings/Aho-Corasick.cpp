803 const int MAXAL = 26; // Size of alphabet
803 
649 struct node{
722 	node* nxt[MAXAL]; // Array of pointers to childs on trie
586 	bool end; // 1 if cur node is end node or a sufix parent is end node
536 	int c; // parent node -- c -- > current node
654 	node* p; // Parent node
738 	node* sl; // Sufix Link
207 	node* ol; // Output Link
553 	int idx; // Index of the string the current node represents
616 	node(): end(false), c(0), p(NULL), sl(NULL), ol(NULL), idx(-1){
643 		ms(nxt, 0);
537 	}
480 };
480 
480 // Root of trie
776 typedef node* trie;
944 trie root = new node();
944 
944 // Be careful with repeated patterns
381 void add(trie root, const string& s, int k){
437 	trie t = root;
869 	FOR(i, 0, s.size()){
913 		int v = (int) s[i]; // MAP CHARACTERS TO INT 
017 		if(!t->nxt[v]){
365 			trie son = new node();
941 			son->c = v;
909 			son->p = t;
721 			t -> nxt[v] = son;
319 		}
924 		t = t->nxt[v];
685 		if(i == (int)s.size()-1){
860 			t->end = true;
516 			t->idx = k;
553 		}
958 	}
824 }
824 
241 void buildLinks(trie root){
881 	queue<trie> q;
838 	q.push(root);
250 	while(!q.empty()){
686 		trie t = q.front(); q.pop();
158 		trie w = t->p;
727 		if(w){
142 			w = w->sl;
996 			while(w && !w->nxt[t->c]) w = w->sl;
511 			t->sl  = w ? w->nxt[t->c] : root;
372 			t->end = t->end || t->sl->end;
582 			t->ol = (t->sl->idx == -1) ? t->sl->ol : t->sl;
144 		}
044 		FOR(c, 0, MAXAL) if(t->nxt[c]) q.push(t->nxt[c]); 
698 	}
380 }
380 
380 // One of the next to should be used
380 
787 set<int> subString(trie root, string& T){
703 	int n = T.size();
661 	trie x = root;
470 	set<int> ans;
566 	FOR(i, 0, n){
108 		int v = (int) T[i]; // MAP CHARACTERS TO INT 
680 		while(x && !x->nxt[v])
240 			x = x->sl;
921 		x = x ? x->nxt[v] : root;
628 		trie y = x;
052 		while(y){
327 			if(y->idx != -1) ans.insert(y->idx);
786 			y = y -> ol;
873 		}
861 	}
149 	return ans;
245 }
245 
129 bool check(trie root, string &T){
076 	int n = T.size();
244 	trie x = root;
944 	FOR(i, 0, n){
333 		int v = (int) T[i]; // MAP CHARACTERS TO INT 
894 		while(x && !x->nxt[v])
629 			x = x->sl;
680 		x = x ? x->nxt[v] : root;
788 		if(x->end) return true;
005 	}
078 	return false;
481 }
481 
481 ////////////////////////////////////////////////////////////////////////////////////
481 
481 // Primer ocurrencia del final de un string
481 // Calcular todas y ver cual es mejor si 
481 // se necesita la primera
577 ii first_ocurrence(string& T){
245 	int n = T.size();
438 	trie x = root;
086 	FOR(i, 0, n){
955 		int v = T[i];
720 		while(x && !x->nxt[v])
401 			x = x-> sl;
007 		x = x ? x->nxt[v] : root;
228 		if(x->idx != -1) return {i, x->idx};
327 		if(x->ol && x->ol->idx != -1) return {i, x->ol->idx};
467 	}
361 	return {-1, -1};
413 
9047119983216188413
