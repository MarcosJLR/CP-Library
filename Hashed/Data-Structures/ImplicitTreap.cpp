008 struct node{
344 	int prior, sz;
151 	ll val, sum, lzy;
971 	node *l, *r;
053 	node(int v) : prior(rand()), sz(1), val(v), 
117 					sum(v), lzy(0), l(0), r(0) {}
900 };
316 typedef node* pnode;
221 int sz(pnode t) { return t ? t->sz : 0; }
898 ll sum(pnode t) { return t ? t->sum : 0; }
991 void push(pnode t){
132 	if(!t || !t->lzy) return;
685 	t->val += t->lzy;
166 	t->sum += t->lzy*sz(t);
562 	if(t->l) t->l->lzy += t->lzy;
560 	if(t->r) t->r->lzy += t->lzy;
709 	t->lzy = 0;
571 }
193 void upd(pnode t){
202 	if(!t) return;
862 	t->sz = 1 + sz(t->l) + sz(t->r);
125 	push(t->l); push(t->r);
349 	t->sum = t->val + sum(t->l) + sum(t->r);
031 }
031 // Element in position pos goes in r
435 void split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
165 	if(!t) return void(l = r = 0);
345 	push(t);
127 	int cur = add + sz(t->l);
935 	if(cur < pos) split(t->r, t->r, r, pos, cur+1), l = t;
350 	else split(t->l, l, t->l, pos, add), r = t;
746 	upd(t);
798 }
023 void merge(pnode &t, pnode l, pnode r){
358 	push(l); push(r);
466 	if(!l || !r) t = l ? l : r;
934 	else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
645 	else merge(r->l, l, r->l), t = r;
061 	upd(t);
475 }
695 ll queryRange(pnode t, int l, int r){
378 	pnode L, M, R;
723 	split(t, M, R, r);
811 	split(M, L, M, l);
363 	ll ans = M->sum;
503 	merge(t, L, M);
129 	merge(t, t, R);
628 	return ans;
678 }
981 void updateRange(pnode t, int l, int r, ll val){
927 	pnode L, M, R;
707 	split(t, M, R, r);
126 	split(M, L, M, l);
472 	M->lzy += val;
059 	merge(t, L, M);
975 	merge(t, t, R);
836 }
147 void eraseTree(pnode &t){
957 	if(!t) return;
931 	eraseTree(t->l);
638 	eraseTree(t->r);
883 	delete t;
461 	t = 0;
996 }
-453034992196842004
