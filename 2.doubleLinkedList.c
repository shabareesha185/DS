#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    newNode->prev = ptr;
    ptr->next = newNode;
    return head;
}

Node *createList(Node *head) {
    int data;
    while (1) {
        printf("Enter the data to create list (0 to exit): ");
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        head = insertAtEnd(head, data);
    }
    return head;
}

Node *deleteNode(Node *head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    Node *ptr = head;
    while (ptr != NULL && ptr->data != data) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Data not found.\n");
        return head;
    }
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        head = ptr->next; // Deleting the head node
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Node with data %d deleted.\n", data);
    return head;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *ptr = head;
    printf("List elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int opp, data;
    while (1) {
        printf("\nEnter the operation:\n");
        printf("1 to create\n2 for insertion\n3 for deletion\n4 to display\n0 to exit\n");
        scanf("%d", &opp);

        switch (opp) {
            case 1:
                head = createList(head);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 0:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid operation.\n");
        }
    }
}
