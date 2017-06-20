#include<stdio.h>
#include<stdlib.h>
const int mod = 11;
int Hash[mod];
void insert(int v){
	int hash = v % mod, cnt = 0;
	while(Hash[(hash + cnt) % mod] != -1){
		cnt ++;
	}
	if(cnt >= mod) {
		printf("Hash Tab is full !");
		return ;
	}
	Hash[(hash + cnt) % mod] = v;
}

void find(int v){
	int hash = v % mod, cnt = 0;
	while(Hash[(hash + cnt) % mod] != -1){
		cnt ++;
	}
	if(cnt >= mod || Hash[(hash + cnt) % mod] != v) {
		printf("Don't exits this value!");
		return ;
	}
	Hash[(hash + cnt) % mod] = v;
}

void print(){
	for(int i = 0; i < mod; i ++){
		printf("%d ", Hash[i]);
	}
	puts("");
}
int main(void){
	for(int i = 0; i < mod; i ++) Hash[i] = -1;
	int n;
	while(~scanf("%d", &n)){
		insert(n); 
		print();
	}
} 

/* TestCase
20 123 456 1321465 131323 4654 1321346 45 565456 87 87912 23
*/
