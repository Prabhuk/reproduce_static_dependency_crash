//
// Created by Prabhu Rajasekaran on 2/1/17.
//

#include <stdio.h>
#include <stdarg.h>
#include "ExternalVariadic.h"



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

// prints a list of n longs
void print_longs(int n, ...) {
    printf("In func: print_longs\n");
    va_list list;
    va_start(list, n);

    while (n--)
        printf("%ld\n", va_arg(list, long));

    va_end(list);
}

// prints sum of four integers n, a, b, c
void sum_ints_non_variadic(int n, int a, int b, int c) {
    printf("%d\n", (n+a+b+c));
}
