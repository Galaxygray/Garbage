#include<stdio.h>
#include<stdlib.h>
typedef struct employee{
	int Id;
	char Name[20];
	char postion[20];
}Employee; 

typedef struct linearList{
	Employee* Data;
	int length;	
	int capacity;
}LinearList;
void InitList(LinearList* L){
	L->length = 0;
	L->capacity = 10;
	L->Data = (Employee *)malloc(sizeof(Employee) * 10);
	if(L->Data == NULL){
		exit(1);
	}
} 

void insert(LinearList* L){
	printf("------------Please enter employee id:  Name : postion and you want to insert postion--------------------\n");
	Employee e;
	int pos;
	scanf("%d %s %s %d",&e.Id,e.Name,e.postion,&pos);
	if(pos > L->length + 1){
		printf("---The postion is vaild----\n");
		return ;
	}
	pos--;
	if(L->length + 1> L->capacity){
		Employee* Data = (Employee *)realloc(L->Data,sizeof(Employee) * 2 * L->capacity);
		if(Data == NULL){
			free(L->Data);
			exit(1);
		}
		L->Data = Data;
	}
	for(int i = L->length - 1; i >= pos; i --)
	L->Data[i + 1] = L->Data[i];
	L->Data[pos] = e; 
	L->length ++;
}

int find(LinearList* L, int Id){
	int i;
	for(i = 0; i < L->length; i ++){
		if(L->Data[i].Id == Id){
			return i;
		}
	}
	return -1;
}

void remove(LinearList* L){
	printf("--------------Please enter employee id: --------------\n");
	int Id;
	scanf("%d",&Id);
	int pos = find(L,Id);
	if(pos == -1){
		printf("------------Doesn't exist the employee--------------\n");
		return ;
	}
	for(int i = pos + 1;i < L->length; i ++){
		L->Data[i-1] = L->Data[i];	
	}
	L->length--;
}

void display(LinearList *L){
	if(L->length == 0) printf("-------The List is empty--------\n");
	for(int i = 0; i < L->length ; i++){
		printf("%d :\tEmployee id:\t%d\tName: %s\tpostion: %s\n",i + 1,L->Data[i].Id,L->Data[i].Name,L->Data[i].postion);
	}
}

void destroy(LinearList* L){
		free(L->Data);
}
int main(void){
	LinearList L;
	InitList(&L);
	int select; 
	printf("------Please Enter you selection, 1 is add employee , 2 is remove employee , -1 is end-------\n"); 
	while(~scanf("%d",&select)){
		if(select == 1){
			insert(&L);
			display(&L);
		}
		else if(select == 2){
			remove(&L);
			display(&L); 
		}
		else break;
	}
	destroy(&L);
}


/* TestCase
1
1 A a 1
1
2 B b 2
1
3 C c 3
1
4 D d 4
1
5 E e 1
1
6 F f 3
2
1
2
2
2
3
2
4
2
5
2
6
*/
