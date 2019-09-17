#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct Deque{
	unsigned int count;
	struct Node* front;
	struct Node* back;
} Deque;

Node* new_Node(int n){
	struct Node* d = NULL;
	d = (struct Node*)malloc(sizeof(struct Node));
	if(d!= NULL){
		d->data = n;
		d->next = NULL;
		d->prev = NULL;
	}
	return d;
}

void push_back(struct Deque** deque, struct Node* node){
	if(*deque != NULL){
		if((*deque)->back != NULL) (*deque)->back->prev = node; 
		node->next = (*deque)->back; //전체pop후, 다시 push할 때는 예외로 
	}else {
		*deque = (struct Deque*)malloc(sizeof(struct Deque));
		(*deque)->count = 0;(*deque)->front = NULL;(*deque)->back = NULL;
	}
	
	if((*deque)->front == NULL) (*deque)->front = node;	
	(*deque)->back = node;
	(*deque)->count += 1;
}

void push_front(struct Deque** deque, struct Node* node){
	if(*deque != NULL){
		if((*deque)->front != NULL) (*deque)->front->next = node; 
		node->prev = (*deque)->front;
	}else {
		*deque = (struct Deque*)malloc(sizeof(struct Deque));
		(*deque)->count = 0;(*deque)->front = NULL;(*deque)->back = NULL;
	}
	
	if((*deque)->back == NULL) (*deque)->back = node;	
	(*deque)->front = node;
	(*deque)->count += 1;
}

void pop_back(struct Deque** deque){
	if(*deque != NULL && (*deque)->back != NULL){
		struct Node* ptr = NULL;
		ptr = (*deque)->back;
		
		(*deque)->back = (*deque)->back->next;					//front, pop수행 
		if((*deque)->back != NULL) (*deque)->back->prev = NULL;//front가NULL이 아니면 끝을 맺음 
		else (*deque)->front = NULL;							//back, front가 NULL이면 back초기화작업
	
		(*deque)->count -= 1;									//count
		free(ptr);
	}else printf("-1\n");
}

void pop_front(struct Deque** deque){
	if(*deque != NULL && (*deque)->front != NULL){
		struct Node* ptr = NULL;
		ptr = (*deque)->front;
		
		(*deque)->front = (*deque)->front->prev;				//front, pop수행 
		if((*deque)->front != NULL) (*deque)->front->next = NULL;//front가NULL이 아니면 끝을 맺음 
		else (*deque)->back = NULL;								//back, front가 NULL이면 back초기화작업
	
		(*deque)->count -= 1;									//count
		free(ptr);
	}else printf("-1\n");
}

void print_deque(struct Deque* deque){
	if(deque != NULL && deque->count > 0){
		struct Node* ptr = deque->back; // deque = deque->next구문때문에 가상의 단일구조체인 ptr이 필요 
		while(ptr != NULL){		// deque을 그대로 사용하면 deque이 뒤로감.
			//printf("data: %d , rear: %x, front: %x, count: %d", ptr->data,queue->rear,queue->front,queue->count); // 참조하여 값을 쓰지않고 읽기만
			printf("%d ",ptr->data);
			ptr = ptr->next;		// 주소를 쓰기않고 읽기만  
		}free(ptr);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	struct Deque* deque = NULL;
	struct Node* d = NULL;

	d = new_Node(1); push_front(&deque,d);
	d = new_Node(2); push_back(&deque,d);
	d = new_Node(3); push_front(&deque,d);
	print_deque(deque);

	pop_front(&deque);
	print_deque(deque);
	
	pop_back(&deque);
	print_deque(deque);
	
	pop_front(&deque);
	print_deque(deque);

	return 0;
}
