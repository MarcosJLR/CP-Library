587 struct state{
009 	int len, link;
123 	int mp[26]; // Be careful with size of alphabet
400 };
400 
421 const int MAXLEN = 100000;
945 state SA[MAXLEN*2];
070 int SAN, last;
070 
391 void SA_build(string S){
547 	last = SA[0].len = 0;
026 	SA[0].link = -1;
335 	ms(SA[0].mp, 0);
420 	SAN = 1;
416 	for(auto C : S){
782 		int c=C-'a', v = SAN++, p=last; // Be careful with mapping char to int
526 		ms(SA[v].mp, 0);
926 		SA[v].len = SA[last].len+1;  
677 		for(;p>-1 && !SA[p].mp[c]; p=SA[p].link)
772 			SA[p].mp[c]=v;
808 		if(p == -1){
457 			SA[v].link = 0;
808 		}else{
544 			int q=SA[p].mp[c];
508 			if(SA[p].len+1 == SA[q].len){
068 				SA[v].link = q;
952 			}else{
676 				int qq = SAN++;
725 				SA[qq].len = SA[p].len+1;
461 				memcpy(SA[qq].mp, SA[q].mp, sizeof(SA[qq].mp));
862 				SA[qq].link = SA[q].link;
675 				SA[v].link = SA[q].link = qq;
648 				for(;p>-1 && SA[p].mp[c] == q; p=SA[p].link)
316 					SA[p].mp[c] = qq;
247 			}
755 		}
495 		last = v;
903 	}
002 }
002 
170 /* 
170 
598 Prints suffix automaton transitions and suffix links
598 
231 int main(){
564 	string S; cin>>S;
110 	SA_build(S);
110 	//##################################
352 	FOR(i,0,SAN){
178 		printf("%d:\n",i);
184 		FOR(it,0,26) if(SA[i].mp[it])
213 			printf("  %c -> %d\n",it+'a',SA[i].mp[it]);
722 	}
792 	printf("\n");
502 	FOR(i,0,SAN){
553 		printf("%d   %d\n",i,SA[i].link);
517 	}
644 	printf("##\n\n");
644 	//##################################
608 }
608 
716 *
797451348045294716
