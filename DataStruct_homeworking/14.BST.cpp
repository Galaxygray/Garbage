#include<stdlib.h>
#include<stdio.h>
const int maxn = 1e5 + 20;
typedef struct Node{
	Node *ch[2];
	int v;
}*BNode; 
int size;
void insert(BNode *rt, int v){
	if(*rt == NULL){
		*rt = (BNode)malloc(sizeof(Node));
		(*rt)->v = v;
		(*rt)->ch[0] = (*rt)->ch[1] = NULL;
		return ;
	}
	if((*rt)->v >= v) insert(&((*rt)->ch[0]), v);
	else insert(&((*rt)->ch[1]), v);
}

void print(Node *rt){
	if(rt == NULL) return ;
	print(rt->ch[0]);
	printf("%d ", rt->v);
	print(rt->ch[1]);
}

void erase(BNode *rt, int v){
	if(*rt == NULL){
		printf("Don't exist this elements!\n");
		return ;
	}
	if((*rt)->v == v){
		if((*rt)->ch[0] != NULL && (*rt)->ch[1] != NULL){
			BNode p = *rt, q = (*rt)->ch[0];
			while(q->ch[1] != NULL){
				p = q;
				q = q->ch[1];
			}
			(*rt)->v = q->v;
			if(p != *rt) p->ch[1] = q->ch[0];      //  Cautions !   Because It's possible that q has leftchild.
			else p->ch[0] = q->ch[0];
			free(q);
		}
		else if((*rt)->ch[0] != NULL){
			BNode t = *rt;
			*rt = (*rt)->ch[0];			
			free(t);
		}
		else{
			BNode t = *rt;				
			*rt = (*rt)->ch[1];			//   rt = &((*rt)->ch[0]);    this don't equal !
			free(t);
		}
		return ;
	}
	if((*rt)->v > v) erase(&((*rt)->ch[0]), v);
	else erase(&((*rt)->ch[1]), v);
}
int main(void){
	BNode rt = NULL;
	for(int i = 0 ; i < 10; i ++) insert(&rt, i);
	print(rt);
	puts("");
	int t;
	while(~scanf("%d", &t)){
		erase(&rt, t);
		print(rt);
		puts("");
	}
	return 0;
}

/*TestCase
3 8 9 0 1
*/

