#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* Insert at Front */
void insertFront(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    /* If queue is empty */
    if (front == NULL)
    {
        front = rear = newNode;
        newNode->next = front;
    }
    else
    {
        newNode->next = front;
        rear->next = newNode;
        front = newNode;
    }

    printf("%d inserted at front.\n", value);
}

/* Insert at End */
void insertEnd(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    /* If queue is empty */
    if (front == NULL)
    {
        front = rear = newNode;
        newNode->next = front;
    }
    else
    {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted at end.\n", value);
}

/* Insert at Any Position */
void insertPosition(int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    if (position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        insertFront(value);
        return;
    }

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    temp = front;

    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if (temp == front)
        {
            printf("Invalid position!\n");
            return;
        }
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == rear)
    {
        rear = newNode;
    }

    printf("%d inserted at position %d.\n", value, position);
}

/* Delete from Front */
void deleteFront()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    temp = front;

    /* Only one node */
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    printf("%d deleted from front.\n", temp->data);
    free(temp);
}

/* Delete from End */
void deleteEnd()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    /* Only one node */
    if (front == rear)
    {
        printf("%d deleted from end.\n", rear->data);
        free(rear);
        front = rear = NULL;
        return;
    }

    temp = front;

    while (temp->next != rear)
    {
        temp = temp->next;
    }

    printf("%d deleted from end.\n", rear->data);

    temp->next = front;
    free(rear);
    rear = temp;
}

/* Delete from Any Position */
void deletePosition(int position)
{
    struct Node *temp, *del;
    int i;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    if (position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        deleteFront();
        return;
    }

    temp = front;

    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if (temp == front)
        {
            printf("Invalid position!\n");
            return;
        }
    }

    del = temp->next;

    /* Position does not exist */
    if (del == front)
    {
        printf("Invalid position!\n");
        return;
    }

    temp->next = del->next;

    if (del == rear)
    {
        rear = temp;
    }

    printf("%d deleted from position %d.\n", del->data, position);

    free(del);
}

/* Traversal */
void traversal()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    temp = front;

    printf("Queue elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != front);

    printf("\n");
}

/* Display */
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("\n----- Circular Linked Queue -----\n");

    printf("Front = %d\n", front->data);
    printf("Rear  = %d\n", rear->data);

    traversal();

    printf("---------------------------------\n");
}

/* Main Function */
int main()
{
    int choice;
    int value;
    int position;

    while (1)
    {
        printf("\n========== MENU ==========\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Any Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Any Position\n");
        printf("6. Delete from End\n");
        printf("7. Traversal\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(value, position);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &position);

                deletePosition(position);
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                traversal();
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

