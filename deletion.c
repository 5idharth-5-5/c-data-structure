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

    printf("Enter the value to delete : ");
    scanf("%d", &value);
    printf("Enter the position delete: ");
    scanf("%d", &pos);

    if (pos< 1 || pos > size) {
        printf("Invalid position! Insertion not possible");
    } else 
    {
    	for(i= pos- 1;i < size- 1;i++){
		arr[i] =arr[i+1];
		}
		
	size--;
	
printf("Array after deletion : \n");
	for(i=0 ; i<size ; i++){
	printf("%d ", arr[i]);
}
printf("\n");
}
return 0;
}








