011 struct node{
716 	int prior, sz;
539 	ll val, sum, lzy;
029 	node *l, *r;
065 	node(int v) : prior(rand()), sz(1), val(v), 
821 					sum(v), lzy(0), l(0), r(0) {}
161 };
765 typedef node* pnode;
919 int sz(pnode t) { return t ? t->sz : 0; }
555 ll sum(pnode t) { return t ? t->sum : 0; }
655 void push(pnode t){
297 	if(!t || !t->lzy) return;
481 	t->val += t->lzy;
470 	t->sum += t->lzy*sz(t);
598 	if(t->l) t->l->lzy += t->lzy;
839 	if(t->r) t->r->lzy += t->lzy;
921 	t->lzy = 0;
582 }
284 void upd(pnode t){
664 	if(!t) return;
478 	t->sz = 1 + sz(t->l) + sz(t->r);
443 	push(t->l); push(t->r);
651 	t->sum = t->val + sum(t->l) + sum(t->r);
029 }
029 // Element in position pos goes in r
292 void split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
605 	if(!t) return void(l = r = 0);
596 	push(t);
724 	int cur = add + sz(t->l);
038 	if(cur < pos) split(t->r, t->r, r, pos, cur+1), l = t;
941 	else split(t->l, l, t->l, pos, add), r = t;
395 	upd(t);
735 }
535 void merge(pnode &t, pnode l, pnode r){
819 	push(l); push(r);
763 	if(!l || !r) t = l ? l : r;
651 	else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
228 	else merge(r->l, l, r->l), t = r;
503 	upd(t);
495 }
975 ll queryRange(pnode t, int l, int r){
674 	pnode L, M, R;
937 	split(t, M, R, r);
020 	split(M, L, M, l);
683 	ll ans = M->sum;
662 	merge(t, L, M);
382 	merge(t, t, R);
266 	return ans;
097 }
360 void updateRange(pnode t, int l, int r, ll val){
186 	pnode L, M, R;
905 	split(t, M, R, r);
878 	split(M, L, M, l);
542 	M->lzy += val;
647 	merge(t, L, M);
088 	merge(t, t, R);
775 }
012 void eraseTree(pnode &t){
873 	if(!t) return;
306 	eraseTree(t->l);
578 	eraseTree(t->r);
272 	delete t;
369 	t = 0;
107 }
-2460893
