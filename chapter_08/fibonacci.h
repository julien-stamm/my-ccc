#ifndef FIBONACCI_H
#define FIBONACCI_H

struct FibonacciIterator {
    bool operator!=(int) const;
    FibonacciIterator& operator++();
    int operator*() const { return current; }
private:
    int current{ 1 }, last{ 1 };
};

struct FibonacciRange {
    explicit FibonacciRange(int max) : max{ max } { }
    FibonacciIterator begin() const { return FibonacciIterator{}; }
    int end() const { return max; }
private:
    const int max;
};

#endif