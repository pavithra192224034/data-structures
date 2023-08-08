#include <stdio.h>
int bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }    
    return -1; 
}
int main() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");    
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1) {
        printf("Number %d found at index %d\n", target, result);
    } else {
        printf("Number %d not found in the array\n", target);
    }
    return 0;
}
