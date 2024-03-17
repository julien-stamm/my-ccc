#include <cstdio>
#include <iostream>

int main() {
    const int& immutable_value{ 3 };
    int& mutable_value{ const_cast<int&>(immutable_value) };
    mutable_value++;
    std::cout << mutable_value << std::endl;

    std::cout << "-------------------------------------------" << std::endl;

    short number_to_cast{ 420 };
    auto result = static_cast<int>(number_to_cast);

    // TODO: Finish reading chapter and do exercises
}