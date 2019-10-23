#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //aparentemente no es necesario

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ordered_set<int> s;
	s.insert(x); 
	s.erase(x);
	s.order_of_key(x); // the number of elements in s (strictly)less than x
	s.find_by_order(k); // iterator pointing to the k-th smallest element in s (0-based) or to s.end() if there's no such element
}