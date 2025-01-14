#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*left,*right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node*root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(Node*root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node*root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void main(){
    Node* root = NULL;
    root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(20);
    root->left->left = createNode(30);
    root->left->right = createNode(5);
    printf("Inorder: ");
    inorder(root);
    printf("preorder: ");
    preorder(root);
    printf("postorder: ");
    postorder(root);
}