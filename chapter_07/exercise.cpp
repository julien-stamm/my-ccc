#include <cstdio>

struct UnsignedBigInteger {
    UnsignedBigInteger(auto value) {
        int a = 0;
    }

    // UnsignedBigInteger operator+(__uint8_t* value) const {
    //     UnsignedBigInteger result{ }
    //     return result;
    // }

    // UnsignedBigInteger operator-(__uint8_t* value) const {

    // }

    // const __uint8_t[] value;
};

int main() {
    UnsignedBigInteger ubi{ 100000000000000000 };
    // unsigned long long temp = 1;

    return 0;
}

// Create an UnsignedBigInteger class that can handle numbers bigger than a long.
// You can use a byte array as the internal representation (for example, uint8_t[] or char[]).
// Implement operator overloads for operator+ and operator-.
// Perform runtime checks for overflow.
// For the intrepid, also implement operator*, operator/, and operator%.
// Make sure that your operator overloads work for both int types and UnsignedBigInteger types.
// Implement an operator int type conversion. Perform a runtime check if narrowing would occur