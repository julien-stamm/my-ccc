#include <cstdio>
#include <string>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Calculator(Operation operation) {
        _operation = operation;
    }

    std::string calculate(int a, int b) {
        std::string result{ "" };
        switch (_operation)
        {
        case Operation::Add:
            result = std::to_string(a + b);
            break;
        case Operation::Subtract:
            result = std::to_string(a - b);
            break;
        case Operation::Multiply:
            result = std::to_string(a * b);
            break;
        case Operation::Divide:
            result = std::to_string(a / (float) b);
            break;
        }
        return result;
    }

private:
    Operation _operation;
};

int main() {
    Calculator calculator_1{ Operation::Add };
    printf("%s", calculator_1.calculate(4, 6).c_str());
    printf("\n==========================\n");

    Calculator calculator_2{ Operation::Subtract };
    printf("%s", calculator_2.calculate(4, 6).c_str());
    printf("\n==========================\n");

    Calculator calculator_3{ Operation::Multiply };
    printf("%s", calculator_3.calculate(4, 6).c_str());
    printf("\n==========================\n");
    
    Calculator calculator_4{ Operation::Divide };
    printf("%s", calculator_4.calculate(4, 6).c_str());
    printf("\n==========================\n");
    return 0;
}