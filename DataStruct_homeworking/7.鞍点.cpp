#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
const int maxn = 1e3 + 20;
const int INF = 0x3f3f3f3f;
int A[maxn][maxn], row[maxn], col[maxn];
bool Get(int A[][maxn], int n, int m){
	for(int i = 1; i <= n; i ++) row[i] = INF;
	for(int i = 1; i <= m; i ++) col[i] = - INF;
	for(int i = 1;i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			row[i] = std::min(row[i], A[i][j]);
		}
	}
	bool flag = false;
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			col[i] = std::max(col[i], A[j][i]);
		}
		for(int j = 1; j <= n; j ++){
			if(col[i] == row[j]) {
				printf("%d %d\n", j, i);
				flag = true;
			}
		}
	}
	if(!flag) printf("Don't exist the entry!\n");
	return flag;
}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++)
		scanf("%d", &A[i][j]);
	}
	Get(A, n, m);
	return 0;
} 

/*	TestCase
3 3
1 3 6
8 5 9
7 2 2
*/

