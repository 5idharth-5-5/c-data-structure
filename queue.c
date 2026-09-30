#include <stdio.h>

int main()
{
    int queue[5], front = -1, rear = -1;
    int choice, item, i;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(rear == 4)
                    printf("Queue is Full");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &item);

                    if(front == -1)
                        front = 0;

                    rear++;
                    queue[rear] = item;

                    printf("Inserted");
                }
                break;

            case 2:
                if(front == -1 || front > rear)
                    printf("Queue is Empty");
                else
                {
                    printf("Deleted = %d", queue[front]);
                    front++;
                }
                break;

            case 3:
                if(front == -1 || front > rear)
                    printf("Queue is Empty");
                else
                {
                    printf("Queue: ");
                    for(i = front; i <= rear; i++)
                        printf("%d ", queue[i]);
                }
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    } while(choice != 4);

    return 0;
}

