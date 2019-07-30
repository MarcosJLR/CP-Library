
// El codigo es una guia, depende mucho del problema


// La raiz es el nodo 0, trie[u][c] apunta al hijo de u que
// representa el caracter c (c+'a')
#define MAXN         // maxima cantidad de nodos en el trie
int TN, trie[MAXN][26];
void insert(string& s){
	int u = 0; // raiz
	int n = s.size();
	FOR(i, 0, n){
		int c = s[i]-'a';
		if(trie[u][c] == -1)   // el nodo u no tiene todavia de hijo la letra s[i]
			trie[u][c] = TN++;
		u = trie[u][c];
	}
}

int main(){
	ms(trie,-1);
	TN = 1;
}
