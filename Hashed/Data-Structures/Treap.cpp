789 struct node{
612 	int key, prior, sz;
728 	node *l, *r;
232 	node(int key) : key(key), prior(rand()), sz(1), l(0), r(0) {}
527 };
688 typedef node* pnode;
006 int sz(pnode t) { return t ? t->sz : 0; }
715 void updSz(pnode t){
255 	if(t) t->sz = 1 + sz(t->l) + sz(t->r);
366 }
366 // Element with key = x goes into r
121 void split(pnode t, int x, pnode &l, pnode &r){
991 	if(!t) l = r = 0;
946 	else if(x < t->key) split(t->l, x, l, t->l), r = t;
010 	else split(t->r, x, t->r, r), l = t;
620 	updSz(t);
082 }
000 void merge(pnode &t, pnode l, pnode r){
843 	if(!l || !r) t = l ? l : r;
270 	else if(l->prior > r->prior)
926 		merge(l->r, l->r, r), t = l;
929 	else
337 		merge(r->l, l, r->l), t = r;
579 	updSz(t);
686 }
126 void insert(pnode &t, pnode it){
371 	if(!t) t = it;
876 	else if(it->prior > t->prior)
926 		split(t, it->key, it->l, it->r), t = it;
310 	else
824 		insert(it->key < t->key ? t->l : t->r, it);
401 	updSz(t);
723 }
636 void erase(pnode &t, int x){
366 	if(t->key == x) merge(t, t->l, t->r);
964 	else erase(x < t->key ? t->l : t->r, x);
223 	updSz(t);
999 }
191 void eraseTree(pnode &t){
360 	if(!t) return;
309 	eraseTree(t->l);
571 	eraseTree(t->r);
237 	delete t;
541 	t = 0;
339 }
339 
-8303762246613501661
