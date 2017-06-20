#include<stdio.h>
typedef struct Person{
	char name[10];
	int id;
	int type;
}P;
typedef struct Queue{
	P p[100];
	int size;
}queue;
int state[6];
queue accumulation_fund,credit_card,Managment_card; 
void pop(queue* Q){
	Q->size--;
	for(int i = 0; i < Q->size; i ++){
		Q->p[i] = Q->p[i + 1]; 
	}
}
void push(queue* Q, P Person){
	Q->p[Q->size ++] = Person;
}
void add(P p){
	if(p.type == 1){
		if(state[1]){
			printf("The 1st window is busy! Please wait!\n");
			push(&accumulation_fund, p);
		}
		else{
			state[1] = p.id;
			printf("%d please come to 1st window\n",p.id);
		}
	}
	else if(p.type == 2){
		bool flag = false;
		for(int i = 2; i <= 4 ; i ++){
			if(!state[i]){
				state[i] = p.id;
				printf("%d please come to %d window\n",p.id,i);
				flag = true;
				break;
			}	
		}
		if(!flag){
			printf("The 2,3,4 window is busy! Please wait!\n");
			push(&credit_card, p);
		}
	}
	else if(p.type == 3){
		bool flag = false;
		for(int i = 5; i <= 6 ; i ++){
			if(!state[i]){
				state[i] = p.id;
				printf("%d please come to %d window\n",p.id,i);
				flag = true;
				break;
			}
		}
		if(!flag){
			bool ok = false;
			for(int i = 2; i <= 4 ; i ++){
			if(!state[i]){
				state[i] = p.id;
				printf("%d please come to %d window\n",p.id,i);
				ok = true;
				break;
			}	
		}
			if(!ok){
				printf("The 5,6,2,3,4 window is busy! Please wait!\n");
				push(&Managment_card, p);
			}
		}
	}
}

void remove(int id){
	bool flag = false;
	int pos = -1;
	for(int i = 1; i <= 6; i ++){
		if(state[i] == id){
			pos = i;
			break;
		}
	}	
	if(pos == -1){
		printf("Doesn't exist this id\n");
		return ;
	}
	if(pos == 1){
		if(accumulation_fund.size){
			flag = true;
			state[pos] = accumulation_fund.p[0].id;
			pop(&accumulation_fund);
			printf("%d please come to 1 window\n", state[pos]);
		}
	}
	else if(pos <= 4){
		if(credit_card.size){
			flag = true;
			state[pos] = credit_card.p[0].id;
			pop(&credit_card);
			printf("%d please come to %d window\n",state[pos] , pos);
		}
		else if(Managment_card.size){
			flag = true;
			state[pos] = Managment_card.p[0].id;
			pop(&Managment_card);
			printf("%d please come to %d window\n", state[pos], pos);
		}
	}
	else{
		if(Managment_card.size){
			flag = true;
			state[pos] = Managment_card.p[0].id;
			pop(&Managment_card);
			printf("%d please come to %d window\n", state[pos], pos);
		}
	}
	if(!flag) state[pos] = 0;
}
int main(void){
	accumulation_fund.size = credit_card.size = Managment_card.size = 0;
	int type;
	while(~scanf("%d",&type)){
		P p;
		if(type == 1){
			scanf("%s%d%d",p.name,&p.id,&p.type);
			add(p);
		}
		else if(type == 2){
			int id;
			scanf("%d",&id);
			remove(id);
		}
		else break;
	}
} 

/* TestCase
1 A 1 1
1 B 2 1
1 C 3 1
1 D 4 2
1 E 5 3
1 F 6 3
1 G 7 3
1 H 8 2
1 J 9 2
1 K 10 3
*/
