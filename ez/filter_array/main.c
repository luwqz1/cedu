/*
    2. Easy task: Create function filter and demonstrate with any example.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum bool {
    false,
    true,
} bool;

typedef struct FilteredArray {
    int *array;
    size_t size;
} FilteredArray;


bool is_positive_number(int number) {
    return number >= 0;
}

FilteredArray filter(bool (*func)(int), int *arr, size_t size) {
    size_t count = 0;
    FilteredArray result;
    for (int i = 0; i < size; i++)
        if (func(arr[i]))
            count++;

    if (!count) {
        result.array = NULL;
        result.size = 0;
        return result;
    }
    
    int *new_arr = (int *)malloc(count * sizeof(int));
    for (int i = 0, j = 0; i < size; i++)
        if (func(arr[i])) {
            new_arr[j] = arr[i];
            j++;
        }
    result.array = new_arr;
    result.size = count;
    return result;
}

void fill_arr_random_numbers(int *arr, size_t size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = -100 + rand() % 200; // [-100, 100]
}

void repr_arr(int *arr, size_t size) {
    if (arr == NULL) {
        printf("{}\n");
        return;
    }
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("}\n");
}

int main(void) {
    int size_arr, *arr;
    printf("Input size of array: ");
    scanf("%d", &size_arr);
    arr = calloc(size_arr, sizeof(int));
    fill_arr_random_numbers(arr, size_arr);
    printf("Generated array: "); repr_arr(arr, size_arr);
    FilteredArray filtered_arr = filter(is_positive_number, arr, size_arr);
    printf("Filtered array (only positive numbers): ");
    repr_arr(filtered_arr.array, filtered_arr.size);
    free(arr);
    free(filtered_arr.array);
    return 0;
}
