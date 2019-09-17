#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    char data;
} Node;

/* ��� ���� */
Node* new_Node(char newData)
{
    // ��带 ���� �޸� �Ҵ�
    Node* newNode = (Node*) malloc(sizeof(Node));
  
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
  
    return newNode;
}
  
/* ��� �ı� */
void DestroyNode(Node* node)
{
    free(node);
}
  
/* Ʈ�� �ı�(���� ��ȸ Ȱ��) */
void DestroyTree(Node* root)
{
    if(root == NULL)
        return;
  
    DestroyTree(root->left);
    DestroyTree(root->right);
    DestroyNode(root);
}
  
/* ���� ��ȸ */
void PreOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;
  
    // ��� ���
    printf(" %c", node->data);
    PreOrderPrintTree(node->left);
    PreOrderPrintTree(node->right);
}
  
/* ���� ��ȸ */
void InOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;
  
    // ��� ���
    InOrderPrintTree(node->left);
    printf(" %c", node->data);
    InOrderPrintTree(node->right);
}
  
/* ���� ��ȸ */
void PostOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;
  
    // ��� ���
    PostOrderPrintTree(node->left);
    PostOrderPrintTree(node->right);
    printf(" %c", node->data);
}

int main(int argc, char *argv[]){
    // ��� ����
    Node* A = CreateNode('A');
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');
    Node* F = CreateNode('F');
    Node* G = CreateNode('G');
  
    // Ʈ���� ��� �߰�
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
    // Ʈ�� ���
    printf("PreOrder...\n");
    PreOrderPrintTree(A);
    printf("\n\n");
  
    printf("InOrder...\n");
    InOrderPrintTree(A);
    printf("\n\n");
  
    printf("PostOrder...\n");
    PostOrderPrintTree(A);
    printf("\n");
  
    // �Ҹ�
    DestroyTree(A);
    
    return 0;
}
