605 #include <bits/stdc++.h>
088 #include <ext/pb_ds/assoc_container.hpp>
807 #include <ext/pb_ds/tree_policy.hpp> //aparentemente no es necesario
235 using namespace __gnu_pbds;
494 using namespace std;
564 template <typename T>
994 using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
318 int main(){
580 	ordered_set<int> s;
817 	s.insert(x); 
082 	s.erase(x);
026 	s.order_of_key(x); // the number of elements in s (strictly)less than x
270 	s.find_by_order(k); // iterator pointing to the k-th smallest element in s (0-based) or to s.end() if there's no such element
633 
867199633
