011 struct node{
256 	int key, prior, sz;
215 	node *l, *r;
958 	node(int key) : key(key), prior(rand()), sz(1), l(0), r(0) {}
023 };
341 typedef node* pnode;
190 int sz(pnode t) { return t ? t->sz : 0; }
622 void updSz(pnode t){
164 	if(t) t->sz = 1 + sz(t->l) + sz(t->r);
143 }
143 // Element with key = x goes into r
732 void split(pnode t, int x, pnode &l, pnode &r){
912 	if(!t) l = r = 0;
563 	else if(x < t->key) split(t->l, x, l, t->l), r = t;
170 	else split(t->r, x, t->r, r), l = t;
172 	updSz(t);
814 }
068 void merge(pnode &t, pnode l, pnode r){
562 	if(!l || !r) t = l ? l : r;
463 	else if(l->prior > r->prior)
447 		merge(l->r, l->r, r), t = l;
045 	else
611 		merge(r->l, l, r->l), t = r;
533 	updSz(t);
931 }
452 void insert(pnode &t, pnode it){
323 	if(!t) t = it;
289 	else if(it->prior > t->prior)
345 		split(t, it->key, it->l, it->r), t = it;
774 	else
195 		insert(it->key < t->key ? t->l : t->r, it);
367 	updSz(t);
445 }
610 void erase(pnode &t, int x){
942 	if(t->key == x) merge(t, t->l, t->r);
701 	else erase(x < t->key ? t->l : t->r, x);
163 	updSz(t);
239 }
329 void eraseTree(pnode &t){
123 	if(!t) return;
480 	eraseTree(t->l);
748 	eraseTree(t->r);
601 	delete t;
226 	t = 0;
322 }
322 
-995262678
