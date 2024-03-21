#include <cstdio>
#include "fibonacci.h"
#include "prime_number.h"

int main() {
    for (const auto i : FibonacciRange{ 5000 }) {
        printf("%d ", i);
    }
    printf("\n\n");

    for (const auto i : PrimeNumberRange{ 5000 }) {
        printf("%d ", i);
    }
    printf("\n\n");
}