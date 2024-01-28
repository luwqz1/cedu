#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *ptr;
    int n;
    int capacity;
} List;


void append(List *list, int element) {
    if (list->n >= list->capacity) {
        int new_capacity = list->capacity * 2;
        int *new_ptr = (int *)realloc(list->ptr, new_capacity * sizeof(int));
        
        if (new_ptr == NULL) return;
        else {
            list->ptr = new_ptr;
            list->capacity = new_capacity;
        }
    }
    
    list->ptr[list->n] = element;
    list->n++;
}


List* init_list(int capacity) {
    List *ptr_list = (List*)malloc(sizeof(List));
    ptr_list->ptr = (int*)malloc(sizeof(int) * ptr_list->capacity);
    ptr_list->capacity = capacity;
    ptr_list->n = 0;
    return ptr_list;
}


void free_list(List *list) {
    free(list->ptr);
    free(list);
}


void repr_list(List *list) {
    printf("[");
    for (int i = 0; i < list->n; i++) {
        if (i + 1 < list->n) printf("%d, ", list->ptr[i]);
        else printf("%d", list->ptr[i]);
    }
    printf("]\n");
}


int main() {
    List *list = init_list(3);
    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);

    repr_list(list);
    
    free_list(list);
    return 0;
}
