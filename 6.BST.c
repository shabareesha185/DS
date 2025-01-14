#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val <= root->val)
    {
        root->left = insert(root->left, val);
    }
    if (val >= root->val)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void main()
{
    Node *root = NULL;
    int opp;
    int val;
    do
    {
        printf("1 for insertion,\n2 for inorder,\n3 for pre,\n 4 for post,\n5 for exit.\nEnter the operation: ");
        scanf("%d", &opp);

        switch (opp)
        {
        case 1:
            printf("Enter the val: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("Iorder: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            freeTree(root);
            break;
        default:
            printf("Inavlid opperation");
            break;
        }
    } while (opp != 5);
}