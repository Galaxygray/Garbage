#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef struct Car{
	char name[10];
	int time;
	int money;
}car;
car parking_car[100];
int size,Now_time;
struct Queue{
	car queue_car[100];
	int size;
}queue;
void push(car x){
	if(queue.size == 100){
		printf("oh hell ! too many car is waitting!\n");
	}
	queue.queue_car[queue.size ++] = x;
}
void add(car x){
	if(size == 100){
		printf("The park is full ! please waiting.\n");
		push(x);
	}
	else{
		parking_car[size++] = x;
	}
}
int find(char* name){
	for(int i = 0; i < size ; i ++){
		if(strcmp(name,parking_car[i].name) == 0)
			return i;
	}
	return -1;
}
void remove(char* name){
	if(size == 0){
		printf("The park is empty!\n");
	}
	else{
		int pos = find(name);
		if(~pos){
			size --;
			printf("%s  fare is %d\n",parking_car[pos].name,Now_time - parking_car[pos].time);
			if(queue.size){
				parking_car[pos] = queue.queue_car[0];
				printf("Please %s come to %d postion.\n",queue.queue_car[0].name,pos + 1);
				parking_car[pos].time = Now_time;
				queue.size--;
				for(int i = 0; i < queue.size; i ++)
					queue.queue_car[i] = queue.queue_car[i + 1];
			}
			else{
				for(int i = pos; i < size; i ++)
					parking_car[i] = parking_car[i + 1];
			}
		}
		else printf("Doesn't exist this car!\n");
	}
}
void display(char* name){
	int pos = find(name);
	if(~pos)
	printf("%s has spent %d\n",parking_car[pos].name,Now_time - parking_car[pos].time);
	else printf("Doesn't exist this car!\n");
}
int main(void){
	queue.size = 0;
	size = 0;
	Now_time = 0;
	int Type;
	while(~scanf("%d",&Type)){
		Car t;
		char str[10];
		if(Type == 1){
			scanf("%s %d",t.name,&t.time);
			Now_time = t.time;
			add(t);
		}
		else if(Type == 2){
			scanf("%s %d",str,&t.time);
			Now_time = t.time;
			remove(str);
		}
		else if(Type == 3){
			scanf("%s %d",str,&Now_time);
			display(str);
		}
		else break;
	}
}

/* TestCase

1 A 0
1 B 100
1 C 101
1 D 134
3 A 150
3 C 151
2 A 200
2 C 201
2 D 300
2 E 200
2 B 400
 */
