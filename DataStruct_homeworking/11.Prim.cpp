#include<stdio.h>
#include<stdlib.h>
#include<algorithm> 
#include<string.h>
const int maxn = 1e3 + 20;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn], vis[maxn], dis[maxn];
int prim(int n){
	int res = 0;
	for(int i = 2; i <= n; i ++){
		if(G[1][i] != INF) dis[i] = G[1][i];
		else dis[i] = INF;
	}
	vis[1] = 1;
	dis[0] = INF;
	for(int i = 1; i < n; i ++){
		int u = 0;
		for(int j = 1; j <= n; j ++){
			if(dis[j] < dis[u] && !vis[j]){
				u = j;
			}
		}
		if(!u) break;
		res += dis[u];
		vis[u] = 1;
		for(int j = 1; j <= n; j ++){
			if(G[u][j] != INF) dis[j] = std::min(dis[j], G[u][j]);
		}
	}
	return res;
}
int main(void){
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	memset(G, 0x3f, sizeof(G));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < m; i ++){
		scanf("%d %d %d", &a, &b, &c);
		G[a][b] = G[b][a] = c;
	}
	printf("%d\n",prim(n));
} 

/* TestCase
6 10
1 2 6
1 4 5
1 3 1
2 3 5
3 4 5
2 5 3
3 5 6
3 6 4
5 6 6
4 6 2
*/


