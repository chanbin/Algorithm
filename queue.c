#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct Queue{
	unsigned int count;
	struct Node* front;
	struct Node* rear;
}Queue;

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

void push(struct Queue** queue, struct Node* node){
	if(*queue != NULL){
		if((*queue)->rear != NULL) (*queue)->rear->prev = node; 
		node->next = (*queue)->rear; //전체pop후, 다시 push할 때는 예외로 
	}else {
		*queue = (struct Queue*)malloc(sizeof(struct Queue));
		(*queue)->count = 0;(*queue)->front = NULL;(*queue)->rear = NULL;
	}
	
	if((*queue)->front == NULL) (*queue)->front = node;	
	(*queue)->rear = node;
	(*queue)->count += 1;
}

void pop(struct Queue** queue){
	if(*queue != NULL && (*queue)->front != NULL){
		struct Node* ptr = NULL;
		ptr = (*queue)->front;
		
		//printf("front1: %x ,",(*queue)->front);
		(*queue)->front = (*queue)->front->prev;				//front, pop수행 
		if((*queue)->front != NULL) (*queue)->front->next = NULL;//front가NULL이 아니면 끝을 맺음 
		else (*queue)->rear = NULL;							//rear, front가 NULL이면 초기화작업
		//printf("front2: %x \n",(*queue)->front);	
		(*queue)->count -= 1;								//count
		
		free(ptr);
	}else printf("-1\n");
}

void print_queue(struct Queue* queue){
	if(queue != NULL && queue->count > 0){
		struct Node* ptr = queue->rear; // queue = queue->next구문때문에 가상의 단일구조체인 ptr이 필요 
		while(ptr != NULL){		// queue을 그대로 사용하면 queue이 뒤로감.
			//printf("data: %d , rear: %x, front: %x, count: %d", ptr->data,queue->rear,queue->front,queue->count); // 참조하여 값을 쓰지않고 읽기만
			printf("%d ",ptr->data);
			ptr = ptr->next;		// 주소를 쓰기않고 읽기만  
		}free(ptr);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	struct Queue* queue = NULL;
	struct Node* d = NULL;

	d = new_Node(1); push(&queue,d);
	d = new_Node(2); push(&queue,d);
	d = new_Node(3); push(&queue,d);
	print_queue(queue);

	pop(&queue);
	print_queue(queue);
	
	pop(&queue);
	print_queue(queue);
	
	pop(&queue);
	print_queue(queue);
	
	return 0;
}
