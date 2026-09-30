#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

/* Push operation */
void push() {
    int value;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

/* Pop operation */
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;

    free(temp);
}

/* Search operation */
void search() {
    int value, position = 1;
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d from top.\n",
                   value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("%d not found in stack.\n", value);
}

/* Display operation */
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (Top to Bottom):\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/* Main function */
int main() {
    int choice;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
