#include <stdio.h>
#include <stdarg.h>
#include "TestVariadic.h"
#include "ExternalVariadic.h"

struct overflow_bait {
    char message[8];
    int (*ptr_to_vararg_func)(int, ...);
};

int main(int argc, char *argv[]) {
    struct overflow_bait bait;
    bait.ptr_to_vararg_func = (void*)sum_ints;

    printf("Stupid vulnerable vararg test program v1.0\n");

    void* address_taken_funcs[5] = {sum_ints, avg_doubles, avg_longs, print_longs, sum_ints_non_variadic};
    for (int i = 0; i < 5; ++i) {
        if(i == 0) {
            printf("These are functions from the same binary \n");
        }
        if(i == 2) {
            printf("These are functions from EXTERNALLY linked binary \n");
        }
        printf("address_taken_funcs[%d] = %p\n", i, address_taken_funcs[i]);
    }

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

