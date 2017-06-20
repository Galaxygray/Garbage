#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
const int maxn = 1e6 + 20;
int A[maxn], B[maxn], C[maxn]; 

void print(int *A, int n){
	for(int i = 1; i <= n; i ++) 	printf("%d%c", A[i], i == n ? '\n':' ');
}

void InsertSort(int *A, int n){
	for(int i = 2; i <= n; i ++){
		A[0] = A[i];
		int L = 1, R = i - 1, mid = 0;
		while(R >= L){
			mid = L + R >> 1;
			if(A[mid] < A[i]) L = mid + 1;
			else R = mid - 1;
		}
		for(int j = i - 1; j >= R + 1; j --)
			A[j + 1] = A[j];
		A[R + 1] = A[0];
	}
}

int SelectMin(int *A, int n){
	int min = 1e9, minp = 1;
	for(int i = 0; i < n; i ++){
		if(min > A[i]){
			min = A[i];
			minp = i;
		}
	}
	return minp;
}

void SelectSort(int *A, int n){
	for(int i = 1; i <= n; i ++){
		std::swap(A[i], A[SelectMin(A + i, n - i + 1) + i]);
	} 
} 

int partition(int *A, int L, int R){
	int p = A[L];
	while(L < R){
		while(L < R && A[R] >= p) R--;
		A[L] = A[R];
		while(L < R && A[L] <= p) L ++;
		A[R] = A[L]; 
	}
	A[L] = p;
	return L;
} 

void QSort(int *A, int L, int R){
	if(L >= R) return ; 
	int p = partition(A, L, R);
	QSort(A, L, p - 1);
	QSort(A, p + 1, R);	
}

void BubbleSort(int *A, int n){
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n - i; j ++)
		if(A[j + 1] < A[j]) std::swap(A[j], A[j + 1]);
	}
}

void MergeSort(int *A, int L, int R){
	if(L >= R) return ;
	int mid = L + R >> 1;
	MergeSort(A, L, mid);
	MergeSort(A, mid + 1, R);
	int cnt = 0, l = L, r = mid + 1;
	while(l <= mid && r <= R){
		while(l <= mid && A[l] <= A[r]) C[cnt ++] = A[l ++];
		while(r <= R && A[l] > A[r]) C[cnt ++] = A[r ++];
	}
	while(l <= mid) C[cnt ++] = A[l ++];
	while(r <= R) C[cnt ++] = A[r ++];
	for(int i = 0; i < cnt; i ++) A[L + i] = C[i]; 
}

void Heapadjust(int *A, int n, int p){
	int j = 2 * p ,t = A[p];
	while(j <= n){
		if(j + 1 <= n && A[j] < A[j + 1]) j ++;
		if(A[j] < t) break;
		A[p] = A[j];
		p = j;
		j = p * 2;
	}
	A[p] = t;
}

void HeapSort(int *A, int n){
	for(int i = n / 2; i >= 1; i --){
		Heapadjust(A, n, i);
	}
	for(int i = 1; i <= n; i ++){
		std::swap(A[1],A[n - i + 1]);
		Heapadjust(A, n - i, 1);
	}
}


bool check(int n, int type){
	for(int i = 1; i <= n; i ++){
		A[i] = B[i] = rand();
	}
	for(int i = 1; i <= n; i ++) 	B[i] = A[i];
	std::sort(B + 1, B + 1 + n);
	switch(type){
		case 1 :  InsertSort(A, n); break;
		case 2 : BubbleSort(A, n); break;
		case 3 : SelectSort(A, n); break;
		case 4 : QSort(A, 1, n); break;
		case 5 : MergeSort(A, 1, n); break;
		case 6 : HeapSort(A, n);
	}
	for(int i = 1; i <= n; i ++) if(A[i] != B[i])	return false;
	return true;
}

int main(void){
	int n;
	scanf("%d", &n);
//	for(int i = 1; i <= n; i ++) scanf("%d", &A[i]);
//	BubbleSort(A, n);
//	insertSort(A, n);
//	print(A, n);
	for(int i = 1; i <= 6; i ++)
	if(check(n, i)){
	//	print(A, n);
		printf("Accepted!\n");
	}
	else printf("Wrong Answer!\n");
	return 0;
} 


/* TestCase
10
45 123 45 12 3 1 45 21 87 34
*/
