000 // Init p[i] = 0, p[0] = p[1] = 0 BE CAREFUL!
747 void fillSieve(int p[]){
195     for(ll i = 4; i < MAXN; i += 2) p[i] = 2;
329     for(ll i = 3; i*i < MAXN; i += 2) if(!p[i])
060         for(ll j = i*i; j < MAXN; j += 2*i) p[j] = i;
861 
884897861
