#include<stdlib.h>
#include<stdio.h>
const int maxn = 100;
int col[maxn],diag[maxn],diag1[maxn],A[maxn],cnt,n;
void print(){
	for(int i = 1; i <= n; i ++){
		for(int j = 0;  j < n ; j++)
		if(A[i] == j) putchar('*');
		else putchar('.');
		puts("");
	}
	puts("-----------------------------------");
}
void solve(){
	int top = 1;
	A[top] = 0;
	while(top){
		while(A[top] < n && (col[A[top]] || diag[A[top] + top - 1] || diag1[-A[top] + top + n - 2]))
		{
			A[top] ++;
		}
		if(A[top] < n){
			col[A[top]] = diag[A[top] + top - 1] = diag1[-A[top] + top + n - 2] = 1;
			A[++top] = 0;
			if(top == n + 1)	cnt++,print();
		}
		else
		{
			top--;
			col[A[top]] = diag[A[top] + top - 1] = diag1[-A[top] + top + n - 2] = 0;
			A[top]++;
		}
	}
}

int main(void){
	while(~scanf("%d",&n)){
		cnt = 0;
		solve();
		printf("%d\n",cnt);
	}
} 
