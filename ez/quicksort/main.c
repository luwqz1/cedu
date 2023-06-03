#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end], i = start - 1;
 
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

void quicksort(int (*func)(int *, int, int), int arr[], int start, int end) {
    if (start < end) {
        int pi = func(arr, start, end);
        quicksort(func, arr, start, pi - 1);
        quicksort(func, arr, pi + 1, end);
    }
}

void repr_arr(int arr[], size_t size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("}\n");
}

int main(void) {
    int arr[] = { 100, 803, 3012, 90231, 402324, 5012, 7, 1};
    size_t size_arr = sizeof(arr) / sizeof(arr[0]);
    printf("Array: "); repr_arr(arr, size_arr);
    quicksort(partition, arr, 0, size_arr - 1);
    printf("Sorted array: "); repr_arr(arr, size_arr);
    return 0;
}
