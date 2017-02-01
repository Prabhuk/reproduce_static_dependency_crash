#include <iostream>


#include "Unuseful.h"

int sum(int n, ...);
int sum2(int n, ...);

int (*functionPtr)(int n, ...);

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    Unuseful u;
    u.printSomething();
    if(argc > 1) {
        functionPtr = &sum;
    } else {
        functionPtr = &sum2;
    }
    functionPtr(2, 1, 1);
    std::cout << std::endl;
    return 0;
}

int sum(int n, ...) {
    va_list ap;
    va_start(ap, n);
    int sum = 0;
    for (auto i =0; i<n; i++) {
        sum = sum + va_arg(ap, int);

    }
    std::cout << sum << std::endl;
    return sum;
}

int sum2(int n, ...) {
    va_list ap;
    va_start(ap, n);
    int sum = 0;
    for (auto i =0; i<n; i++) {
        int arg = va_arg(ap, int);
        sum = sum + arg + (arg * 2);

    }
    std::cout << sum << std::endl;
    return sum;
}
