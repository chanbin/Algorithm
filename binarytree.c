#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    char data;
} Node;

/* 노드 생성 */
Node* new_Node(char newData)
{
    // 노드를 위한 메모리 할당
    Node* newNode = (Node*) malloc(sizeof(Node));
  
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
  
    return newNode;
}
  
/* 노드 파괴 */
void DestroyNode(Node* node)
{
    free(node);
}
  
/* 트리 파괴(후위 순회 활용) */
void DestroyTree(Node* root)
{
    if(root == NULL)
        return;
  
    DestroyTree(root->left);
    DestroyTree(root->right);
    DestroyNode(root);
}
  
/* 전위 순회 */
void PreOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;
  
    // 노드 출력
    printf(" %c", node->data);
    PreOrderPrintTree(node->left);
    PreOrderPrintTree(node->right);
}
  
/* 중위 순회 */
void InOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;
  
    // 노드 출력
    InOrderPrintTree(node->left);
    printf(" %c", node->data);
    InOrderPrintTree(node->right);
}
  
/* 후위 순회 */
void PostOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;
  
    // 노드 출력
    PostOrderPrintTree(node->left);
    PostOrderPrintTree(node->right);
    printf(" %c", node->data);
}

int main(int argc, char *argv[]){
    // 노드 생성
    Node* A = CreateNode('A');
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');
    Node* F = CreateNode('F');
    Node* G = CreateNode('G');
  
    // 트리에 노드 추가
    A->left = B;
    B->left = C;
    B->right = D;
  
    A->right = E;
    E->left = F;
    E->right = G;
    
    /*
       A
     B   E
    C D F G
    */
    // 트리 출력
    printf("PreOrder...\n");
    PreOrderPrintTree(A);
    printf("\n\n");
  
    printf("InOrder...\n");
    InOrderPrintTree(A);
    printf("\n\n");
  
    printf("PostOrder...\n");
    PostOrderPrintTree(A);
    printf("\n");
  
    // 소멸
    DestroyTree(A);
    
    return 0;
}
