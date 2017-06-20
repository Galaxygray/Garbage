#include<stdio.h>
#include<stdlib.h>
const int maxn = 12500;
typedef struct{
	int i, j, elements;
}Triple;
typedef struct{
	Triple data[maxn];
	int rows, cols, cnt;
}TSmatrix;
TSmatrix T, P;

void swap(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
}

int num[maxn];
struct SparseMatrix{
	
	void createMartix(TSmatrix *T){
		scanf("%d %d %d", &T->rows, &T->cols, &T->cnt);
		for(int i = 0; i < T->cnt; i ++){
			scanf("%d %d %d", &T->data[i].i, &T->data[i].j, &T->data[i].elements);
		}
	}
	
	void TransposeMatrix(TSmatrix T, TSmatrix *P){
		// Init
		for(int i = 0; i <= T.cols; i ++) num[i] = 0;
		for(int i = 0; i < T.cnt; i ++) num[T.data[i].j] ++;
		for(int i = 1; i <= T.cols; i ++) num[i] += num[i - 1];
		
		// transpose
		P->cnt = T.cnt, P->cols = T.cols, P->rows = T.rows;
		int pos;
		for(int i = 0; i < T.cnt; i ++){
			pos = num[T.data[i].j - 1];
			P->data[pos] = T.data[i];
			swap(&P->data[pos].i, &P->data[pos].j);
			num[T.data[i].j - 1] ++;
		}
		
	}
	
	void printMatrix(TSmatrix T){
		for(int i = 0; i < T.cnt; i ++){
			printf("%d %d %d\n",T.data[i].i, T.data[i].j, T.data[i].elements);
		}
		puts("*********************************");
	}
	
}Test;
int main(void){
	Test.createMartix(&T);
	printf("%d\n", T.cnt);
	Test.printMatrix(T);
	Test.TransposeMatrix(T, &P);
	Test.printMatrix(P);
} 

/*   Testcase
10 10 8
1 2 12
1 3 9
3 1 -3
3 6 14
4 3 24
5 2 18
6 1 15
6 4 -7
*/
