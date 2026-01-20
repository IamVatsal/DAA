#include <stdio.h>
#include <stdlib.h>

int count_steps_bubble = 0;
int count_steps_insertion = 0;
int count_steps_selection = 0;
int count_steps_quick = 0;
int count_steps_merge = 0;


// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


//  1) BUBBLE SORT
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            count_steps_bubble++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


//  2) INSERTION SORT
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            count_steps_insertion++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        count_steps_insertion++;
    }
}


//  3) SELECTION SORT
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            count_steps_selection++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


// 4) QUICK SORT
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        count_steps_quick++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 5) MERGE SORT
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        count_steps_merge++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        count_steps_merge++;
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        count_steps_merge++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        count_steps_merge++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        count_steps_merge++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main() {
    int n = 0;

    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = array[i];
    }

    printf("Original Array: ");
    printArray(arr, n);

    // Bubble Sort
    int* a1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a1[i] = array[i];
    }
    bubbleSort(a1, n);
    printf("\nBubble Sort: ");
    printArray(a1, n);
    printf("Number of Steps: %d\n", count_steps_bubble);

    // Insertion Sort
    int* a2 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a2[i] = array[i];
    }
    insertionSort(a2, n);
    printf("Insertion Sort: ");
    printArray(a2, n);
    printf("Number of Steps: %d\n", count_steps_insertion);

    // Selection Sort
    int* a3 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a3[i] = array[i];
    }
    selectionSort(a3, n);
    printf("Selection Sort: ");
    printArray(a3, n);
    printf("Number of Steps: %d\n", count_steps_selection);

    // Quick Sort
    int* a4 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a4[i] = array[i];
    }
    quickSort(a4, 0, n - 1);
    printf("Quick Sort: ");
    printArray(a4, n);
    printf("Number of Steps: %d\n", count_steps_quick);

    // Merge Sort
    int* a5 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a5[i] = array[i];
    }
    mergeSort(a5, 0, n - 1);
    printf("Merge Sort: ");
    printArray(a5, n);
    printf("Number of Steps: %d\n", count_steps_merge);


    return 0;
}
