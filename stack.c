#include <stdio.h>

int main()
{
    int stack[5];
    int top = -1;
    int choice, value, i;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (top == 4)
                {
                    printf("Stack is full\n");
                }
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &value);

                    top++;
                    stack[top] = value;

                    printf("Element pushed\n");
                }
                break;

            case 2:
                if (top == -1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Popped element = %d\n", stack[top]);
                    top--;
                }
                break;

            case 3:
                if (top == -1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Stack elements are:\n");

                    for (i = top; i >= 0; i--)
                    {
                        printf("%d\n", stack[i]);
                    }
                }
                break;

            case 4:
                printf("Exit\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

