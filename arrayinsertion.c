#include <stdio.h>

int main() {
    int arr[50]; 
    int size, i, pos, value;

   printf("Enter size of an array: ");
    scanf("%d", &size);

   printf("Enter elements:");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);
    printf("Enter the position insert: ");
    scanf("%d", &pos);

    if (pos< 1 || pos > size + 1) {
        printf("Invalid position! Insertion not possible");
    } else {
   
   
        for (i = size -1; i >= pos- 1; i--) {
            arr[i + 1] = arr[i];
        }

        arr[pos - 1] = value;
        size++;

        printf("Resultant array is:");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

