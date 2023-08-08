#include <stdio.h>
int display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return 0;
    }
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    (*size)++;
    return 1;
}

int deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return 0;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 1;
}

int main() {
    int arr[50];
    int size = 0;
    int choice, element, position;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter element: ");
                scanf("%d", &element);
                insert(arr, &size, position, element);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

