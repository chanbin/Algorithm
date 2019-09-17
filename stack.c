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

void push(struct Node** top, struct Node* node){//�ּҿ����ڿ� �Ϲݺ�������, ����ü����(next,prev)���� �������� �Ұ���
	//�����ʹ� ���߻��߰���������, �������� �ּҿ����� �ѹ������� 
												//EX: &���, (struct Node* top)���� ���  
	if(*top != NULL){
		struct Node* ptr = NULL; // ����ü �ּҰ� ���� ���� ������ 
		ptr = *top; // ����ü �ּ�(ptr)�� ������ ������(*top) �ּҰ� �ֱ� 
		//ptr->prev = data; // �������Ͽ� prev���� 
		node->next = ptr; // ���ϱ���ü �ּҿ� ������������ �ּ�(ptr)����
		*top = node; // (������ ����)'����' ����ü�ּ� *top = ����ü �ּ�(node), node�� top�� �� 
					// ptr = node�� �ȵ�->(������ ����)'����' ����ü�ּ� = ����ü�ּ�(node)
	}else *top = node; //������������ �ּҰ� NUll�϶�, ���������� �ּ� = ����ü �ּ�
}

void pop(struct Node** top){
	if(*top != NULL){
		struct Node* ptr = NULL;
		ptr = *top;
		*top = (*top)->next;
		free(ptr);
		//if(*top != NULL) // ������(NULL)���� pop�� ����Ǹ� ���̻� prev��((*NULL)->prev) ���� 
		//	(*top)->prev = NULL;
	}
}

void print_stack(struct Node* top){
	if(top != NULL){
		struct Node* ptr = top; // top = top->next���������� ������ ���ϱ���ü�� ptr�� �ʿ� 
		while(ptr != NULL){		// top�� �״�� ����ϸ� top�� �ڷΰ�.
			printf("%d ", ptr->data); // �����Ͽ� ���� �����ʰ� �б⸸
			ptr = ptr->next;		// �ּҸ� ����ʰ� �б⸸  
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
