768 struct state{
258 	int len, link;
539 	int mp[26]; // Be careful with size of alphabet
944 };
500 const int MAXLEN = 100000;
624 state SA[MAXLEN*2];
558 int SAN, last;
656 void SA_build(string S){
689 	last = SA[0].len = 0;
120 	SA[0].link = -1;
604 	ms(SA[0].mp, 0);
918 	SAN = 1;
652 	for(auto C : S){
381 		int c=C-'a', v = SAN++, p=last; // Be careful with mapping char to int
062 		ms(SA[v].mp, 0);
733 		SA[v].len = SA[last].len+1;  
490 		for(;p>-1 && !SA[p].mp[c]; p=SA[p].link)
667 			SA[p].mp[c]=v;
240 		if(p == -1){
346 			SA[v].link = 0;
805 		}else{
982 			int q=SA[p].mp[c];
990 			if(SA[p].len+1 == SA[q].len){
470 				SA[v].link = q;
271 			}else{
836 				int qq = SAN++;
496 				SA[qq].len = SA[p].len+1;
554 				memcpy(SA[qq].mp, SA[q].mp, sizeof(SA[qq].mp));
893 				SA[qq].link = SA[q].link;
549 				SA[v].link = SA[q].link = qq;
010 				for(;p>-1 && SA[p].mp[c] == q; p=SA[p].link)
924 					SA[p].mp[c] = qq;
604 			}
546 		}
210 		last = v;
273 	}
738 }
470 /* 
230 Prints suffix automaton transitions and suffix links
862 int main(){
178 	string S; cin>>S;
061 	SA_build(S);
061 	//##################################
951 	FOR(i,0,SAN){
430 		printf("%d:\n",i);
031 		FOR(it,0,26) if(SA[i].mp[it])
805 			printf("  %c -> %d\n",it+'a',SA[i].mp[it]);
341 	}
680 	printf("\n");
778 	FOR(i,0,SAN){
593 		printf("%d   %d\n",i,SA[i].link);
970 	}
058 	printf("##\n\n");
058 	//##################################
696 }
988 *
-1856743012
