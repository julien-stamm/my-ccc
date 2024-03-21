#include "prime_number.h"

bool PrimeNumberIterator::operator!=(int x) const {
    return x >= current;
}

PrimeNumberIterator& PrimeNumberIterator::operator++() {
    int counter;
    do {
        counter = 0;
        current++;
        for (int i = 1; i <= current; i++) {
            if (current % i == 0) {
                counter--;
            }
        }
    } while(counter == 2);

    return *this;
}