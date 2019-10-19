118 #include <bits/stdc++.h>
303 #include <ext/pb_ds/assoc_container.hpp>
401 #include <ext/pb_ds/tree_policy.hpp> //aparentemente no es necesario
401 
331 using namespace __gnu_pbds;
881 using namespace std;
975 template <typename T>
865 using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
865 
182 int main(){
626 	ordered_set<int> s;
388 	s.insert(x); 
614 	s.erase(x);
969 	s.order_of_key(x); // the number of elements in s (strictly)less than x
581 	s.find_by_order(k); // iterator pointing to the k-th smallest element in s (0-based) or to s.end() if there's no such element
902 
3717310111177551902
