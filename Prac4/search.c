#include <stdio.h>
#include <stdlib.h>

int count_linear_search = 0;
int count_binary_search = 0;

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        count_binary_search++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index mid
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        count_linear_search++;
        if (arr[i] == target) {
            return i; // Target found at index i
        }
    }
    return -1; // Target not found
}

int main() {
    FILE *fp;
    fp = fopen("arr_sorted.txt", "r");
    int size = 0;
    int target = 0;

    fscanf(fp, "%d", &size);
    fscanf(fp, "%d", &target);
    
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", &array[i]);
    }
    fclose(fp);
    // Linear Search
    int result = linear_search(array, size, target);
    if (result != -1) {
        printf("Linear Search: Element found at index %d\n", result);
    } else {
        printf("Linear Search: Element not found\n");
    }
    printf("Size of Array used for Binary Search: %d\n", size);
    printf("Number of Steps in Linear Search: %d\n", count_linear_search);
    free(array);

    // Binary Search
    fp = fopen("arr_sorted.txt", "r");

    fscanf(fp, "%d", &size);
    fscanf(fp, "%d", &target);
    
    array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", &array[i]);
    }
    fclose(fp);
    result = binary_search(array, size, target);
    if (result != -1) {
        printf("\nBinary Search: Element found at index %d\n", result);
    } else {
        printf("\nBinary Search: Element not found\n");
    }
    printf("Size of Array used for Binary Search: %d\n", size);
    printf("Number of Steps in Binary Search: %d\n", count_binary_search);
    free(array);
    return 0;
}