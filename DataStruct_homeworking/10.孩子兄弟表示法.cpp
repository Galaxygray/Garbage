#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
const int maxn = 1000;
typedef struct CSNode{
	char data;
	struct CSNode * firstchild, * nextsibling;
}CSNode, * CSTree; 
char str[10];
void build(CSTree &head){
	CSTree p = NULL;
	while(~scanf("%s", str) && str[0] != '#'){
		if(head == NULL) {
			head = (CSTree)malloc(sizeof(CSNode));
			p = head;
		}
		else{
			p->nextsibling = (CSTree)malloc(sizeof(CSTree));
			p = p->nextsibling;
		}
		p->data = str[0];
		p->nextsibling = p->firstchild = NULL;
		build(p->firstchild);
	}
}

int get_depth(CSTree rt){
	int res = 0;
    for(CSTree p = rt->firstchild; p ; p = p->nextsibling)
    	res = std::max(res, get_depth(p) + 1),printf("%c\n",p->data);
    return res;
}

int main(void){
	CSTree rt;
	rt = (CSTree)malloc(sizeof(CSNode));
	rt->firstchild = rt->nextsibling = NULL;
	build(rt->firstchild);
//	printf("%c\n",tree.nodes[1].data);
	printf("%d\n",get_depth(rt));
	return 0;
}
