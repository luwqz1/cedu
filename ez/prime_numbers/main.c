/* 1. Easy task: Write a program to compute prime numbers in range from 1 to 100 and then take
   prime numbers with prime indexes. Print them to stdout.
*/
#include <stdlib.h>
#include <stdio.h>

typedef enum bool {
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

int main() {
    int start = 1, stop = 100;
    int *rng_ptr = (int *)calloc(stop, sizeof(int));
    create_range(rng_ptr, start, stop); 
    for (int i = 0; i < stop; i++)
        if (is_prime(i) && is_prime(rng_ptr[i]))
            printf("%d: %d\n", i, rng_ptr[i]);
    free(rng_ptr);
    return 0;
}
