struct state{
	int len, link;
	int mp[26]; // Be careful with size of alphabet
};

const int MAXLEN = 100000;
state SA[MAXLEN*2];
int SAN, last;

void SA_build(string S){
	last = SA[0].len = 0;
	SA[0].link = -1;
	ms(SA[0].mp, 0);
	SAN = 1;
	for(auto C : S){
		int c=C-'a', v = SAN++, p=last; // Be careful with mapping char to int
		ms(SA[v].mp, 0);
		SA[v].len = SA[last].len+1;  
		for(;p>-1 && !SA[p].mp[c]; p=SA[p].link)
			SA[p].mp[c]=v;
		if(p == -1){
			SA[v].link = 0;
		}else{
			int q=SA[p].mp[c];
			if(SA[p].len+1 == SA[q].len){
				SA[v].link = q;
			}else{
				int qq = SAN++;
				SA[qq].len = SA[p].len+1;
				memcpy(SA[qq].mp, SA[q].mp, sizeof(SA[qq].mp));
				SA[qq].link = SA[q].link;
				SA[v].link = SA[q].link = qq;
				for(;p>-1 && SA[p].mp[c] == q; p=SA[p].link)
					SA[p].mp[c] = qq;
			}
		}
		last = v;
	}
}

/* 

Prints suffix automaton transitions and suffix links

int main(){
	string S; cin>>S;
	SA_build(S);
	//##################################
	FOR(i,0,SAN){
		printf("%d:\n",i);
		FOR(it,0,26) if(SA[i].mp[it])
			printf("  %c -> %d\n",it+'a',SA[i].mp[it]);
	}
	printf("\n");
	FOR(i,0,SAN){
		printf("%d   %d\n",i,SA[i].link);
	}
	printf("##\n\n");
	//##################################
}

*/