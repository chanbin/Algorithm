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
		node->next = (*deque)->back; //��üpop��, �ٽ� push�� ���� ���ܷ� 
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
		
		(*deque)->back = (*deque)->back->next;					//front, pop���� 
		if((*deque)->back != NULL) (*deque)->back->prev = NULL;//front��NULL�� �ƴϸ� ���� ���� 
		else (*deque)->front = NULL;							//back, front�� NULL�̸� back�ʱ�ȭ�۾�
	
		(*deque)->count -= 1;									//count
		free(ptr);
	}else printf("-1\n");
}

void pop_front(struct Deque** deque){
	if(*deque != NULL && (*deque)->front != NULL){
		struct Node* ptr = NULL;
		ptr = (*deque)->front;
		
		(*deque)->front = (*deque)->front->prev;				//front, pop���� 
		if((*deque)->front != NULL) (*deque)->front->next = NULL;//front��NULL�� �ƴϸ� ���� ���� 
		else (*deque)->back = NULL;								//back, front�� NULL�̸� back�ʱ�ȭ�۾�
	
		(*deque)->count -= 1;									//count
		free(ptr);
	}else printf("-1\n");
}

void print_deque(struct Deque* deque){
	if(deque != NULL && deque->count > 0){
		struct Node* ptr = deque->back; // deque = deque->next���������� ������ ���ϱ���ü�� ptr�� �ʿ� 
		while(ptr != NULL){		// deque�� �״�� ����ϸ� deque�� �ڷΰ�.
			//printf("data: %d , rear: %x, front: %x, count: %d", ptr->data,queue->rear,queue->front,queue->count); // �����Ͽ� ���� �����ʰ� �б⸸
			printf("%d ",ptr->data);
			ptr = ptr->next;		// �ּҸ� ����ʰ� �б⸸  
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
