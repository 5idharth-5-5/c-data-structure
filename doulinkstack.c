#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert at Front */
void insert_front(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at front.\n");
}

/* Insert at End */
void insert_end(int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    printf("Node inserted at end.\n");
}

/* Insert at Any Position */
void insert_position(int value, int pos)
{
    struct node *newnode, *temp;
    int i;

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insert_front(value);
        return;
    }

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = temp;
    newnode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

/* Delete from Front */
void delete_front()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("%d deleted from front.\n", temp->data);

    free(temp);
}

/* Delete from End */
void delete_end()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL)
        head = NULL;
    else
        temp->prev->next = NULL;

    printf("%d deleted from end.\n", temp->data);

    free(temp);
}

/* Delete from Any Position */
void delete_position(int pos)
{
    struct node *temp;
    int i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        delete_front();
        return;
    }

    temp = head;

    for (i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("%d deleted from position %d.\n",
           temp->data, pos);

    free(temp);
}

/* Display */
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

/* Main Function */
int main()
{
    int choice, value, pos;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Any Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Any Position\n");
        printf("6. Delete from End\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &pos);

                insert_position(value, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 4:
                delete_front();
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);

                delete_position(pos);
                break;

            case 6:
                delete_end();
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

