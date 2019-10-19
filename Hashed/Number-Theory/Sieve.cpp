000 // Init p[i] = 0, p[0] = p[1] = 0 BE CAREFUL!
743 void fillSieve(int p[]){
646     for(ll i = 4; i < MAXN; i += 2) p[i] = 2;
230     for(ll i = 3; i*i < MAXN; i += 2) if(!p[i])
995         for(ll j = i*i; j < MAXN; j += 2*i) p[j] = i;
333 
7723532060920372333
