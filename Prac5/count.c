#include <stdio.h>
#include <stdlib.h>

int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int arrCopy(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
    return 0;
}

int countingSort(int arr[], int size) {
    int max = maxElement(arr, size);

    // Create count array and initialize as 0
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store count (Frequency) of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // prefix sum of count array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    int ans[size];

    // To make it stable we are running the loop from size-1 to 0
    for (int i = size - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // transfer the sorted elements back to original array
    arrCopy(ans, arr, size);

    return 0;
}

int main(){
    FILE *fp = freopen("input.txt", "r", stdin);
    int size;
    scanf("%d", &size);
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}