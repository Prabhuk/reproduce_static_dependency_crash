//
// Created by Prabhu Rajasekaran on 2/1/17.
//

#include <stdio.h>
#include <stdarg.h>
#include "TestVariadic.h"

int ab_sum_ints(int n, ...) {
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
int ab_avg_doubles(int n, ...) {
    printf("In func: avg_doubles\n");
    double sum = 0;
    va_list list;
    va_start(list, n);

    while (n--)
        sum += va_arg(list, double);

    va_end(list);
    return sum / n;
}
