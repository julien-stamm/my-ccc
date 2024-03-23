#include <cstdio>

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, size_t length) {
    for (size_t i{ 0 }; i < length; i++) {
        if (function(input[i]) == false) {
            return false;
        }
    }
    return true;
}

int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;
    auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);
    if (all_gt100) printf("All elements greater than 100.\n"); // Doesn't get printed
    
    auto all_gt10 = all([](auto x) { return x > 10; }, data, data_len);
    if (all_gt10) printf("All elements greater than 10.\n"); // Gets printed
    return 0;
}