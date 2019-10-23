462 const int MAXAL = 26; // Size of alphabet
462 
336 struct node{
115 	node* nxt[MAXAL]; // Array of pointers to childs on trie
659 	bool end; // 1 if cur node is end node or a sufix parent is end node
457 	int c; // parent node -- c -- > current node
530 	node* p; // Parent node
631 	node* sl; // Sufix Link
642 	node* ol; // Output Link
132 	int idx; // Index of the string the current node represents
976 	node(): end(false), c(0), p(NULL), sl(NULL), ol(NULL), idx(-1){
462 		ms(nxt, 0);
119 	}
851 };
851 
851 // Root of trie
092 typedef node* trie;
328 trie root = new node();
328 
328 // Be careful with repeated patterns
860 void add(trie root, const string& s, int k){
211 	trie t = root;
818 	FOR(i, 0, s.size()){
878 		int v = (int) s[i]; // MAP CHARACTERS TO INT 
538 		if(!t->nxt[v]){
055 			trie son = new node();
122 			son->c = v;
942 			son->p = t;
779 			t -> nxt[v] = son;
131 		}
993 		t = t->nxt[v];
043 		if(i == (int)s.size()-1){
142 			t->end = true;
984 			t->idx = k;
888 		}
258 	}
738 }
738 
080 void buildLinks(trie root){
120 	queue<trie> q;
643 	q.push(root);
470 	while(!q.empty()){
478 		trie t = q.front(); q.pop();
159 		trie w = t->p;
378 		if(w){
328 			w = w->sl;
216 			while(w && !w->nxt[t->c]) w = w->sl;
463 			t->sl  = w ? w->nxt[t->c] : root;
325 			t->end = t->end || t->sl->end;
254 			t->ol = (t->sl->idx == -1) ? t->sl->ol : t->sl;
060 		}
163 		FOR(c, 0, MAXAL) if(t->nxt[c]) q.push(t->nxt[c]); 
903 	}
643 }
643 
643 // One of the next to should be used
643 
696 set<int> subString(trie root, string& T){
776 	int n = T.size();
128 	trie x = root;
233 	set<int> ans;
766 	FOR(i, 0, n){
724 		int v = (int) T[i]; // MAP CHARACTERS TO INT 
224 		while(x && !x->nxt[v])
340 			x = x->sl;
249 		x = x ? x->nxt[v] : root;
780 		trie y = x;
176 		while(y){
359 			if(y->idx != -1) ans.insert(y->idx);
789 			y = y -> ol;
262 		}
984 	}
439 	return ans;
440 }
440 
868 bool check(trie root, string &T){
757 	int n = T.size();
174 	trie x = root;
387 	FOR(i, 0, n){
103 		int v = (int) T[i]; // MAP CHARACTERS TO INT 
511 		while(x && !x->nxt[v])
654 			x = x->sl;
202 		x = x ? x->nxt[v] : root;
183 		if(x->end) return true;
404 	}
506 	return false;
497 }
497 
497 ////////////////////////////////////////////////////////////////////////////////////
497 
497 // Primer ocurrencia del final de un string
497 // Calcular todas y ver cual es mejor si 
497 // se necesita la primera
700 ii first_ocurrence(string& T){
100 	int n = T.size();
648 	trie x = root;
387 	FOR(i, 0, n){
661 		int v = T[i];
331 		while(x && !x->nxt[v])
453 			x = x-> sl;
097 		x = x ? x->nxt[v] : root;
592 		if(x->idx != -1) return {i, x->idx};
402 		if(x->ol && x->ol->idx != -1) return {i, x->ol->idx};
456 	}
312 	return {-1, -1};
470 
1135839470
