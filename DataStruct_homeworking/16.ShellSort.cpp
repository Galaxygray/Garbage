#include<stdlib.h>
#include<stdio.h>
#include<algorithm> 
const int maxn = 1e6 + 20;
int A[maxn], dlta[maxn], B[maxn];

void print(int *A, int n){
	for(int i = 1; i <= n; i ++) 	printf("%d%c", A[i], i == n ? '\n':' ');
}

void SelectSort(int *A, int n, int d){
	for(int i = d + 1; i <= n; i ++){
		if(A[i] < A[i - d]){
			A[0] = A[i];
			int j;
			for(j = i - d; j >= 1 && A[j] > A[0]; j -= d){
				A[j + d] = A[j];
			}
			A[j + d] = A[0];
		}
	}
}

void ShellSort(int *A, int n, int t){
	for(int i = 1; i <= t; i ++){
//		print(A, n);
		SelectSort(A, n, dlta[i]);
	}
}

bool check(int n, int t){
	for(int i = 1; i <= n; i ++){
		A[i] = B[i] = rand();
	}
	for(int i = 1; i <= n; i ++) 	B[i] = A[i];
	std::sort(B + 1, B + 1 + n);
	ShellSort(A, n, t);
	for(int i = 1; i <= n; i ++) if(A[i] != B[i])	return false;
	return true;
}

int main(void){
	int t, n;
	scanf("%d %d", &t, &n);
	for(int i = 1; i <= t; i ++) dlta[i] = pow(2, t - i + 1) - 1;
//	print(dlta, t);
	if(check(n, t)){
		printf("Accepted!\n");
	}
	else printf("Wrong Answer!\n");
} 
