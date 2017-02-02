#include <stdio.h>
#include <stdarg.h>
//#include "TestVariadic.h"
#include "ExternalVariadic.h"

int sum_ints(int n, ...) {
    printf("In func: sum_int\n");
    int sum = 0;
    va_list list;
    va_start(list, n);

    while (n--)
        sum += va_arg(list, int);

    va_end(list);
    return sum;
}

// calculates the average of n doubles
int avg_doubles(int n, ...) {
    printf("In func: avg_doubles\n");
    double sum = 0;
    va_list list;
    va_start(list, n);

    while (n--)
        sum += va_arg(list, double);

    va_end(list);
    return sum / n;
}

struct overflow_bait {
    char message[8];
    int (*ptr_to_vararg_func)(int, ...);
};

int main(int argc, char** argv) {
    struct overflow_bait bait;
    bait.ptr_to_vararg_func = (void*)sum_ints;

    printf("Stupid vulnerable vararg test program v1.0\n");

    void* address_taken_funcs[4] = {sum_ints, avg_doubles, print_longs, sum_ints_non_variadic};
    for (int i = 0; i < 4; ++i)
        printf("address_taken_funcs[%d] = %p\n", i, address_taken_funcs[i]);

    printf("Hit any key when ready!\n");
    int c = getchar();

    FILE* fp = fopen("./exploit", "rb");

    if (!fp) {
        printf("Could not find payload\n");
        return -1;
    }

    size_t bytes_read = fread(bait.message, 1, sizeof(struct overflow_bait), fp);

    /*
    if (bytes_read != sizeof(struct overflow_bait)) {
        printf("Malformed exploit (expected %ld bytes - read %ld bytes)!\n",
               sizeof(struct overflow_bait), bytes_read);
        return -1;
    }
    */

    fclose(fp);

    int result = bait.ptr_to_vararg_func(3,1,2,3);

    printf(">>> IF YOU CAN SEE THIS LINE, CFI DIDN'T STOP THE EXPLOIT!!!\n");

    printf("Result: %s - %d\n", bait.message, result);

    return 0;
}

