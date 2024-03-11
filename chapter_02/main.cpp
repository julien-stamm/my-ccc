#include <cstdio>

union Variant {
    int integer;
    char string[10];
    char character;
    float float_number;
};

int main() {
    char my_variable[10];
    size_t my_size = sizeof(my_variable);
    printf("%zd\n", my_size);
    for (size_t i = 0; i > 2; i++) {
        printf(".\n");
    }
    printf("==========================\n");
    
    int my_list[] = { 2, 4, 566 };

    for (auto element : my_list) {
        printf("%d\n", element);
    }
    printf("==========================\n");
    Variant variant;
    
    variant.integer = 10;
    printf("%d\n", variant.integer);
    printf("%f\n", variant.float_number);

    variant.character = 'A';
    printf("%c\n", variant.character);
    printf("%s\n", variant.string);

    printf("\n==========================\n");
    return 0;
}