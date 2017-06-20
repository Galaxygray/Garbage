#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
const int maxn = 1e2 + 10;
typedef struct {
    char data;
    int parent;
}Node;
typedef struct {
	Node node[maxn];
	int sz;
}Tree;
Tree tree;
char str[10];
void build(int rt){
	while(~scanf("%s", str) && str[0] != '#'){
		tree.node[++ tree.sz].data = str[0];
		tree.node[tree.sz].parent = rt;
		build(tree.sz);
	}
}
int get_Depth(){
    int res = 0;
    for(int i = 1; i <= tree.sz; i ++){
        int rt = tree.node[i].parent, cnt = 1;
        while(rt){
            rt = tree.node[rt].parent;
            cnt ++;
        }
        res = std::max(res, cnt);
    }
    return res;
}

int main(void){
	build(0);
	printf("%d\n",get_Depth());
	return 0;
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
