#include <cstdio>

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
    auto result = initial;
    for (size_t i{ 0 }; i < length; i++) {
        result = function(result, input[i]);
    }
    return result;
};

int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;
    
    auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0);
    printf("Sum: %d\n", sum);
    
    auto maximum = fold([](auto x, auto y) { return (x > y) ? x : y; }, data, data_len, data[0]);
    printf("Maximum: %d\n", maximum);

    auto minimum = fold([](auto x, auto y) { return (x < y) ? x : y; }, data, data_len, data[0]);
    printf("Minimum: %d\n", minimum);

    auto nb_greater_than_200 = fold([](auto x, auto y) { return (y > 200) ? x + 1 : x; }, data, data_len, 0);
    printf("Number of elements greater than 200: %d\n", nb_greater_than_200);
    
    return 0;
}