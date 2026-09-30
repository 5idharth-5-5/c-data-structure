#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high, int order) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    while (i <= mid && j <= high) {
        if (order == 1) {   // Increasing order
            if (a[i] <= a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
        else {               // Decreasing order
            if (a[i] >= a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high, int order) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid, order);
        mergeSort(a, mid + 1, high, order);

        merge(a, low, mid, high, order);
    }
}

void display(int a[], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    int a[100], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (1) {
        printf("\n========== MERGE SORT ==========\n");
        printf("1. Increasing Order\n");
        printf("2. Decreasing Order\n");
        printf("3. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                mergeSort(a, 0, n - 1, 1);

                printf("Elements in increasing order:\n");
                display(a, n);
                break;

            case 2:
                mergeSort(a, 0, n - 1, 2);

                printf("Elements in decreasing order:\n");
                display(a, n);
                break;

            case 3:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


