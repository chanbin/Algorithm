#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
//	struct Node* prev;
} Node;

Node* new_Node(int n){
	struct Node* d = (struct Node*)malloc(sizeof(struct Node));
	if(d!= NULL){
		d->data = n;
		d->next = NULL;
//		d->prev = NULL;
	}
	return d;
}

void push(struct Node** top, struct Node* node){//주소연산자와 일반변수사용시, 구조체내부(next,prev)까지 역참조가 불가능
	//포인터는 이중삼중가능하지만, 역참조와 주소연산은 한번만가능 
												//EX: &사용, (struct Node* top)인자 사용  
	if(*top != NULL){
		struct Node* ptr = NULL; // 구조체 주소가 들어가는 단일 포인터 
		ptr = *top; // 구조체 주소(ptr)에 역참조 가능한(*top) 주소값 넣기 
		//ptr->prev = data; // 역참조하여 prev수정 
		node->next = ptr; // 단일구조체 주소에 역참조가능한 주소(ptr)저장
		*top = node; // (역참조 가능)'다중' 구조체주소 *top = 구조체 주소(node), node가 top이 됨 
					// ptr = node는 안됨->(역참조 가능)'단일' 구조체주소 = 구조체주소(node)
	}else *top = node; //역참조가능한 주소가 NUll일때, 참조가능한 주소 = 구조체 주소
}

void pop(struct Node** top){
	if(*top != NULL){
		struct Node* ptr = NULL;
		ptr = *top;
		*top = (*top)->next;
		free(ptr);
		//if(*top != NULL) // 마지막(NULL)까지 pop이 진행되면 더이상 prev가((*NULL)->prev) 없다 
		//	(*top)->prev = NULL;
	}
}

void print_stack(struct Node* top){
	if(top != NULL){
		struct Node* ptr = top; // top = top->next구문때문에 가상의 단일구조체인 ptr이 필요 
		while(ptr != NULL){		// top을 그대로 사용하면 top이 뒤로감.
			printf("%d ", ptr->data); // 참조하여 값을 쓰지않고 읽기만
			ptr = ptr->next;		// 주소를 쓰기않고 읽기만  
		}free(ptr);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	struct Node* top = NULL;
	struct Node* d = NULL;
	
	d = new_Node(1); push(&top,d);
	d = new_Node(2); push(&top,d);
	d = new_Node(3); push(&top,d);
	print_stack(top);
	
	pop(&top);
	print_stack(top);
	
	pop(&top);
	print_stack(top);

	pop(&top);
	print_stack(top);
	
	return 0;
}
