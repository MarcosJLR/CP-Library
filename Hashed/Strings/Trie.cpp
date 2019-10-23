000 // El codigo es una guia, depende mucho del problema
000 // La raiz es el nodo 0, trie[u][c] apunta al hijo de u que
000 // representa el caracter c (c+'a')
632 #define MAXN         // maxima cantidad de nodos en el trie
393 int TN, trie[MAXN][26];
944 void insert(string& s){
338 	int u = 0; // raiz
238 	int n = s.size();
822 	FOR(i, 0, n){
609 		int c = s[i]-'a';
227 		if(trie[u][c] == -1)   // el nodo u no tiene todavia de hijo la letra s[i]
492 			trie[u][c] = TN++;
280 		u = trie[u][c];
547 	}
775 }
031 int main(){
559 	ms(trie,-1);
880 	TN = 1;
013 }
-2145262987
