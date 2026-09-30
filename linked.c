#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;
    printf("\nYour Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *newNode = NULL;
    int choice = 1;
    int value;

    printf("--- Creating a Linked List from User Input ---\n");

    while (choice == 1) {
        printf("Enter an integer value: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {

            tail->next = newNode;
            tail = newNode; 
        }

        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }

    printList(head);

    freeList(head);
    printf("Memory successfully cleared. Goodbye!\n");

    return 0;
}

