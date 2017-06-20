#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	node* next;node* pre;
	int Id,code;
}Node;
Node* head;

void InitList(int n){
	head = NULL;
	Node* t;Node* p;
	for(int i = 1; i <= n; i ++)
	{
		p = (Node *)malloc(sizeof(Node));
		scanf("%d",&p->code);
		p->Id = i;
		if(head == NULL){
			head = p;
			p->next = head;
			p->pre = head;
			t = p;
			continue;
		}
		t->next = p;
		p->pre = t;
		p->next = head;
		t = p;
	}
	head->pre = p;
}

void remove(int m,int n){
	int tot = n;
	Node* p = head;Node* t = NULL;
	while(p->next != p){
		for(int i = 0 ; i < m - 1; i ++){
			p = p->next;
		}
		printf("%d is out\n",p->Id);
		m = p->code;
		t = p->pre;
		t->next  = p->next;
		p->next->pre = t;
		t =  t->next;
		free(p);
		p = t;
	}
	printf("%d is winner\n",p->Id);
	free(p);
}

int main(void){
	int n,m;
	printf("-----Please enter the number of people and the first code-----\n");
	while(~scanf("%d%d",&n,&m) && n && m){
		InitList(n);
		remove(m,n);
		printf("-----Please enter the number of people and the first code-----\n");
	}
}


/*
TestCase
6 3
1 2 3 4 5 6 
6 1 
1 1 1 1 1 1
6 2
123 132 456 32 123 456
6 54645646
131313 4564646 1313 64545 3213 31312
1 3212
132
2 132
132 123
*/
