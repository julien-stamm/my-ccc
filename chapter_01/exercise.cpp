#include <cstdio>

int absolute_value(int original_value) {
    if (original_value >= 0) {
        return original_value;
    } else {
        return original_value * -1;
    }
}

int sum(int a, int b) {
    return a + b;
}

int main() {
    int numb1 = -19;
    int a = 4;
    int b = 6;
    printf("The absolute value of %d is %d.\n", numb1, absolute_value(numb1));
    printf("%d + %d = %d\n", a, b, sum(a, b));
    return 0;
}