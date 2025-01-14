#include <stdio.h>

char queue[5];
int front = 0, rear = -1, size = 0;

int isEmpty()
{
    return size == 0;
}

int isFull()
{
    return size == 5;
}

void insert()
{
    if (isFull())
    {
        printf("OverFlow\n");
        return;
    }
    printf("Enter the data: ");
    char c;
    scanf(" %c", &c);
    rear = (rear + 1) % 5;
    queue[rear] = c;
    size++;
    printf("Inserted %c\n", queue[rear]);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("UnderFlow\n");
        return;
    }
    printf("deleted: %c", queue[front]);
    front = (front + 1) % 5;
    size--;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", queue[(front + i) % 5]);
    }
    printf("\n");
}

void main()
{

    int opp;
    do
    {
        printf("1 for Insertion,\n2 for deletion,\n3 for display,\n$ to exit.\n");
        printf("Enter the operation no.: ");
        scanf("%d", &opp);
        switch (opp)
        {
        case 1:
            insert();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (opp != 4);
}