#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

/* Insert at Front */
void insertFront(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Node inserted at front.\n");
}

/* Insert at End */
void insertEnd(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (top == NULL) {
        top = newNode;
    } else {
        temp = top;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

/* Insert at Any Position */
void insertPosition(int value, int pos) {
    struct Node *newNode, *temp;
    int i;

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 0) {
        insertFront(value);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    temp = top;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

/* Delete from Front */
void deleteFront() {
    struct Node *temp;

    if (top == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = top;
    top = top->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Delete from End */
void deleteEnd() {
    struct Node *temp, *prev;

    if (top == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (top->next == NULL) {
        printf("Deleted element: %d\n", top->data);
        free(top);
        top = NULL;
        return;
    }

    temp = top;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Delete from Any Position */
void deletePosition(int pos) {
    struct Node *temp, *prev;
    int i;

    if (top == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    temp = top;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Display */
void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = top;

    printf("Elements: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Main Function */
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n---------------LINKED STACK-------------\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Any Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Any Position\n");
        printf("6. Delete from End\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("\n------------LINKED STACK----------------\n");
      
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertPosition(value, pos);
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
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

