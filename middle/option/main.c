#include <stdio.h>
#include <stdlib.h>

typedef struct { void* value; } Option;
const Option None = { NULL };


Option Some(void* value) {
    Option option = { value };
    return option;
}


Option map(Option option, void* (*func)(void*)) {
    if (option.has_value != NULL)
        return Some(func(option.value));
    return None;
}


void *unwrap(Option option) {
    if (option.has_value != NULL) return option.value;
    fprintf(stderr, "Cannot unwrap None.\n");
    exit(EXIT_FAILURE);
}


int main() {
    Option some_value = Some("Hello, bro!");
    char *str = (char *)unwrap(some_value); 
    printf("Some value: %s\n", str);
    return 0;
}
