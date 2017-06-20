#include<stdio.h>
#include<stdlib.h>
#include<algorithm> 
const int maxn = 1000;
typedef struct CTNode{
	int child;
	struct CTNode *next;
}* ChildPtr;
typedef struct {
	char data;
	ChildPtr first;
}CTBox;
typedef struct {
	CTBox nodes[maxn];
	int n, r;
}CTree;
CTree tree;
char str[10];
void build(ChildPtr &head){
	ChildPtr p = NULL;
	while(~scanf("%s", str) && str[0] != '#'){
		tree.nodes[++ tree.n].data = str[0];
		if(head == NULL) {
			head = (ChildPtr)malloc(sizeof(CTNode));
			p = head;
		}
		else{
			p->next = (ChildPtr)malloc(sizeof(CTNode));
			p = p->next;
		}
		p->child = tree.n;
		p->next = NULL;
		build(tree.nodes[tree.n].first);
	}
}

int get_depth(int rt){
	int res = 0;
    for(ChildPtr p = tree.nodes[rt].first; p ; p = p->next)
    	res = std::max(res, get_depth(p->child) + 1),printf("%c\n",tree.nodes[p->child].data);
    return res;
}

int main(void){
	tree.nodes[0].first = NULL;
	build(tree.nodes[0].first);
//	printf("%c\n",tree.nodes[1].data);
	printf("%d\n",get_depth(0));
}


/* TestCase
R
A
D
#
E
#
#
B
#
C
F
G
#
H
#
K
#
#
#
#
#*/
 
