#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data[4];
	int size = 4;
	int pos = 0;
}Queue;
int t,pre;
void push(){
	Queue.pos = (Queue.pos + 1) % Queue.size;
	t -= pre;
	pre = Queue.data[Queue.pos];
	printf("%d\n",t); 
	Queue.data[Queue.pos] = t;
	t += t;
}
int main(void){
	Queue.data[0] = 0,Queue.data[1] = 0,Queue.data[2] = 0,Queue.data[3] = 1;
	Queue.pos = 3;
	t = 1; 
	for(int i = 0; ; i ++){
		push();
		if(t - pre > 200)
		break;
	}
}
