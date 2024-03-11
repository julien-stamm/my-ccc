#include <cstdio>

void read_from(const char* string, const size_t size, const int index) {
    if (index <= 0 || index > size) {
        printf("Error reading at index %d\n", index);
        return;
    }
    printf("Character at index %d is %c\n", index, string[index]);
}

void write_to(char* string, const size_t size, const int index, const char new_value) {
    if (index <= 0 || index > size) {
        printf("Error writing at index %d\n", index);
        return;
    }
    string[index] = new_value;
    printf("Character %c added at index %d\n", new_value, index);
}

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char *upper_ptr = upper;

    size_t lower_size = sizeof(lower) / sizeof(lower[0]);
    size_t upper_size = sizeof(upper) / sizeof(upper[0]);

    write_to(lower, lower_size, 3, 'd');
    write_to(upper_ptr, upper_size, 3, 'D');
    
    printf("lower: %s\nupper: %s\n\n", lower, upper);
    
    read_from(lower, lower_size, 3);
    read_from(upper_ptr, upper_size, 3);
        
    printf("\n\n");

    write_to(lower, lower_size, 7, 'g');
    write_to(upper_ptr, upper_size, -999, 'f');

    read_from(lower, lower_size, 3000);
    read_from(upper_ptr, upper_size, -10);

    printf("\n\n");
}
