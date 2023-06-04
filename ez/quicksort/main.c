/*
    3. Easy task: Write a quicksort function that will take parameters: 
    calculate pivot function, array, left, right.
*/
#include <stdio.h>

#define ARRLEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define SWAP(T, x, y) do { T SWAP = x; x = y; y = SWAP; } while (0)

int partition(
    int (*calculate_pivot)(int *, int, int),
    int arr[], int left, int right) {
    int i = left - 1, j = right + 1,
        pivot = calculate_pivot(arr, left, right);

    while (1) {
        i++;
        while (arr[i] < pivot)
            i++;
        j--;
        while (arr[j] > pivot)
            j--;

        if (i >= j)
            return j;
        SWAP(int, arr[i], arr[j]);
    }
}

// select the middle element to be the pivot.
int select_middle_element(int arr[], int left, int right) {
    return arr[(left + right) / 2];
}

void quicksort(
    int (*calculate_pivot)(int *, int, int),
    int arr[], int left, int right) {
    if (left < right) {
        int sp_index = partition(calculate_pivot, arr, left, right);
        quicksort(calculate_pivot, arr, left, sp_index);
        quicksort(calculate_pivot, arr, sp_index + 1, right);
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
    int arr[] = { 2, 100, 803, 3012, 90231, 402324, 5012, 7 };
    size_t size_arr = ARRLEN(arr);
    printf("Array: "); repr_arr(arr, size_arr);
    quicksort(select_middle_element, arr, 0, size_arr - 1);
    printf("Sorted array: "); repr_arr(arr, size_arr);
    return 0;
}
