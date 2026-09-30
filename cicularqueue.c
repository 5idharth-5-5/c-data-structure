#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* Enqueue operation */
void enqueue()
{
    int value;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (front == NULL)
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("%d inserted into queue.\n", value);
}

/* Dequeue operation */
void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    if (front == rear)
    {
        printf("%d deleted from queue.\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("%d deleted from queue.\n", front->data);

        front = front->next;
        rear->next = front;

        free(temp);
    }
}

/* Search operation */
void search()
{
    int value, position = 1;
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    temp = front;

    do
    {
        if (temp->data == value)
        {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != front);

    printf("%d not found in queue.\n", value);
}

/* Display operation */
void display()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    temp = front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while (temp != front);

    printf("\n");
}

/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== CIRCULAR QUEUE =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
