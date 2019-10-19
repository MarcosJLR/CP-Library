000 
000 // El codigo es una guia, depende mucho del problema
000 
000 
000 // La raiz es el nodo 0, trie[u][c] apunta al hijo de u que
000 // representa el caracter c (c+'a')
877 #define MAXN         // maxima cantidad de nodos en el trie
267 int TN, trie[MAXN][26];
014 void insert(string& s){
837 	int u = 0; // raiz
414 	int n = s.size();
353 	FOR(i, 0, n){
637 		int c = s[i]-'a';
606 		if(trie[u][c] == -1)   // el nodo u no tiene todavia de hijo la letra s[i]
596 			trie[u][c] = TN++;
113 		u = trie[u][c];
922 	}
437 }
437 
909 int main(){
689 	ms(trie,-1);
973 	TN = 1;
260 }
4132836672555396260
