#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    node* left ;node* right;
    int value;
   // node(){left = NULL,right = NULL;value = -1;}
}Node;
int type;
void BuildTree(Node** parents){
    int value;
    scanf("%d" , &value);
    if(~value){
        Node* rt = (Node *)malloc(sizeof(Node));
        BuildTree(&(rt->left));
        BuildTree(&(rt->right));
        rt->value = value;
        (*parents) = rt;
    } 
    else (*parents) = NULL;
}

void printTree(Node* parents){
    if(parents == NULL) {return ;}
    if(type == 1)   printf("%d\n" , parents->value);
    printTree(parents->left);
    if(type == 2)   printf("%d\n" , parents->value);
    printTree(parents->right);
    if(type == 3)   printf("%d\n" , parents->value);
}
stack<Node *> S;
void printTree_stack(Node* root){
    Node* T = root;
    while(T != NULL || !S.empty()){
        while(T != NULL){
            S.push(T);
            T = T->left;
        }
        T = S.top();
        S.pop();
        if(T != NULL) printf("%d\n",T->value);
        T = T->right;
      //  S.pop();
    }
}
queue<Node *>Q;
void printTree_queue(Node* root){
    Q.push(root);
    Node* T;
    while(!Q.empty()){
        T = Q.front();
        Q.pop();
        printf("%d\n",T->value);
        if(T->left != NULL) Q.push(T->left);
        if(T->right != NULL) Q.push(T->right);
    }
}

int Get_depth(Node* root,int d){
	int ans = d;
	if(root->left != NULL) ans = max(ans, Get_depth(root->left, d + 1));
	if(root->right != NULL) ans = max(ans, Get_depth(root->right, d + 1));
	return ans;
}
int main(void){
    Node* root = NULL;
    BuildTree(&root);
    printTree_stack(root);
    printTree_queue(root);
    while(scanf("%d", &type) && type)
    {
		printTree(root); 
    }
    printf("The Teedepth is %d\n", Get_depth(root, 0)); 
    return 0; 
}

/* TestCase
1
2
-1 -1
3
-1 -1
*/
