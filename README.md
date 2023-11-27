# The C programming language education

Arseny gives me **easy**, **middle** and **hard** tasks and im trying to solve them.

For example task `cedu/ez/prime_numbers/main.c`:

```c
#include <stdlib.h>
#include <stdio.h>


typedef enum Bool {
    false,
    true,
} bool;


bool is_prime(int n) {
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return true;
    return false;
}


void create_range(int *rng_ptr, int start, int stop) {
    for (int i = start; i < stop + 1; i++)
        rng_ptr[i - 1] = i;
}


int main(void) {
    int start = 1, stop = 100;
    int *rng_ptr = (int *)calloc(stop, sizeof(int));
    create_range(rng_ptr, start, stop); 
    for (int i = 0; i < stop; i++)
        if (is_prime(i) && is_prime(rng_ptr[i]))
            printf("%d: %d\n", i, rng_ptr[i]);
    free(rng_ptr);
    return 0;
}
```
