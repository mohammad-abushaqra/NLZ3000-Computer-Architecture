/*
 * 20241502057_nlz_fast.c
 * CE201 Project 1: NLZ3000
 * Optimized NLZ implementation using the GCC leading-zero-count builtin.
 */
#include <stdio.h>
#include <stdint.h>
#include <time.h>

static inline int nlz(uint64_t x)
{
    if (x == 0)
        return 64;
    return __builtin_clzll(x);
}

/*
 * Keep main() identical to the project starter program.
 */
int main(void)
{
    struct timespec start, end;
    uint64_t sum = 0;

    timespec_get(&start, TIME_UTC);
    for (uint64_t i = 0; i <= 1000000000; i++)
        sum += nlz(i);
    timespec_get(&end, TIME_UTC);

    double seconds = (end.tv_sec - start.tv_sec)
                   + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Sum of leading zeros: %llu\n", (unsigned long long)sum);
    printf("Time: %.4f s\n", seconds);
    return 0;
}
