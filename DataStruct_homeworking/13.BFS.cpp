#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
int vis[maxn];
typedef struct VexEdge{
	VexEdge *next;
	int data;
}VexEdge;
typedef struct Vex{
	VexEdge *firstvex; 
}Vex;
typedef struct{
	Vex vex[maxn];
	int n, m;
}Graph;
Graph G;
Vex path[maxn];
void Init(int n){
	for(int i = 1; i <= n; i ++) G.vex[i].firstvex = NULL;
}

void addedge(Vex *vex, int u, int v){
	VexEdge *p = (VexEdge *)malloc(sizeof(VexEdge));
	p->data = v;
	p->next = vex[u].firstvex;
	vex[u].firstvex = p;	
}

int Vec[maxn];

void dfs(int u,int d){
	Vec[d] = u;
	if(!path[u].firstvex){
		for(int i = 1; i <= d; i ++)
		printf("%d%s",Vec[i], i == d ? "\n": "->");
	}
	for(VexEdge *p =  path[u].firstvex; p; p = p->next){
        int v = p->data;
		dfs(v, d + 1);
    }
}

int main(void){
    int a, b;
    scanf("%d %d", &G.n, &G.m);
    Init(G.n);
    for(int i = 0; i < G.m; i ++){
        scanf("%d %d", &a, &b);
        addedge(G.vex, a, b);
        addedge(G.vex, b, a);
    }
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(VexEdge *p =  G.vex[u].firstvex; p; p = p->next){
        	int v = p->data;
            if(vis[v])  continue;
            addedge(path, u, v);
            vis[v] = 1;
            Q.push(v);
        }
    }
    
    dfs(1, 1);
    
    return 0;
}

/* TestCase 
8 9
1 2
1 3
2 4
2 5
5 8
4 8
3 6
3 7
6 7
*/
