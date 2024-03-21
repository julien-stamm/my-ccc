#ifndef PRIME_NUMBER_H
#define PRIME_NUMBER_H

struct PrimeNumberIterator {
    bool operator!=(int) const;
    PrimeNumberIterator& operator++();
    int operator*() const { return current; }
private:
    int current{ 2 };
};

struct PrimeNumberRange {
    explicit PrimeNumberRange(int max) : max{ max } { }
    PrimeNumberIterator begin() const { return PrimeNumberIterator{}; }
    int end() const { return max; }
private:
    const int max;
};

#endif