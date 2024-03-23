#include <cstdio>

int main(int argc, char** argv) {
    for (size_t i{ 0 }; i < argc; i++) {
        size_t j{ 0 };
        while (const auto c = argv[i][j]) { j++; }
        printf("%zu: %4zu  ", i, j);
        for (size_t jj{ 0 }; jj < j; jj++) {
            printf("=");
        }
        printf("\n");
    }
    return 0;
}