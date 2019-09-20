// Hungarian Algorithm for assignment problem (min or max cost in a perfect bipartite matching)
// O(n^3)

#define N 55 //max number of vertices in one part
#define INF 100000000 //just infinity
int cost[N][N]; //cost matrix
int n, max_match; //n workers and n jobs
int lx[N], ly[N]; //labels of X and Y parts
int xy[N]; //xy[x] - vertex that is matched with x,
int yx[N]; //yx[y] - vertex that is matched with y
bool S[N], T[N]; //sets S and T in algorithm
int slack[N]; //as in the algorithm description
int slackx[N]; //slackx[y] such a vertex, that
// l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
int prev[N]; //array for memorizing alternating paths

void init_labels(){
	ms(lx,0);
	ms(ly,0);
	FOR(x,0,n) FOR(y,0,n)
	lx[x] = max(lx[x], cost[x][y]);
}

void update_labels(){
	int delta = INF; //init delta as infinity
	FOR(y,0,n) if(!T[y]) delta = min(delta, slack[y]); //calculate delta using slack
	FOR(x,0,n) if (S[x]) lx[x] -= delta; //update X labels
	FOR(y,0,n) if (T[y]) ly[y] += delta; //update Y labels
	FOR(y,0,n) if (!T[y]) slack[y] -= delta; //update slack array
}

//x - current vertex,prevx - vertex from X before x in the alternating path,
//so we add edges (prevx, xy[x]), (xy[x], x)
void add_to_tree(int x, int prevx){
	S[x] = true; //add x to S
	prev[x] = prevx; //we need this when augmenting
	FOR(y,0,n) //update slacks, because we add new vertex to S
	if (lx[x] + ly[y] - cost[x][y] < slack[y]){
		slack[y] = lx[x] + ly[y] - cost[x][y];
		slackx[y] = x;
	}
}

//main function of the algorithm
void augment(){
	if (max_match == n) return; //check wether matching is already perfect
	int root; //just root vertex
	int q[N], wr = 0, rd = 0; //q - queue for bfs, wr,rd - write and read
	//pos in queue
	ms(S,false); //init set S
	ms(T,false); //init set T
	ms(prev,-1); //init set prev - for the alternating tree
	FOR(x,0,n) if (xy[x] == -1){ //finding root of the tree
		q[wr++] = root = x;
		prev[x] = -2;
		S[x] = true;
		break;
	}
	FOR(y,0,n){ //initializing slack array
		slack[y] = lx[root] + ly[y] - cost[root][y];
		slackx[y] = root;
	}

	while(true){
		while (rd < wr){ //building tree with bfs cycle
			x = q[rd++]; //current vertex from X part
			FOR(y,0,n) if(cost[x][y] == lx[x] + ly[y] && !T[y]){ //iterate through all edges in equality graph
				if(yx[y] == -1) break; //an exposed vertex in Y found, so augmenting path exists!
				T[y] = true; //else just add y to T,
				q[wr++] = yx[y]; //add vertex yx[y], which is matched with y, to the queue
				add_to_tree(yx[y], x); //add edges (x,y) and (y,yx[y]) to the tree
			}
			if(y < n) break; //augmenting path found!
		}
		if(y < n) break; //augmenting path found!
		update_labels(); //augmenting path not found, so improve labeling
		wr = rd = 0;

		//in this cycle we add edges that were added to the equality graph as a result of improving the labeling,
		// we add edge (slackx[y], y) to the tree if and only if !T[y] && slack[y] == 0, 
		//also with this edge we add another one (y, yx[y]) or augment the matching, if y was exposed
		FOR(y,0,n)if(!T[y] && slack[y] == 0){
			if(yx[y] == -1){ x = slackx[y]; break; } //exposed vertex in Y found - augmenting path exists!
			else{
				T[y] = true; //else just add y to T,
				if(!S[yx[y]]){
					q[wr++] = yx[y]; //add vertex yx[y], which is matched with y, to the queue
					add_to_tree(yx[y], slackx[y]); //and add edges (x,y) and (y, yx[y]) to the tree
				}
			}
		}
		if(y < n) break; //augmenting path found!
	}
	if(y < n){ //we found augmenting path!
		max_match++; //increment matching
		for(int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty){ //in this cycle we inverse edges along augmenting path
			ty = xy[cx];
			yx[cy] = cx;
			xy[cx] = cy;
		}
		augment(); //recall function, go to step 1 of the algorithm
	}
}

//driver function 
int hungarian(){
	int ret = 0; //weight of the optimal matching
	max_match = 0; //number of vertices in current matching
	ms(xy,-1);
	ms(yx,-1);
	init_labels(); //step 0
	augment(); //steps 1-3
	FOR(x,0,n) //forming answer there
	ret += cost[x][xy[x]];
	return ret;
}