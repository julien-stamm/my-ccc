#include <cstdio>

struct Message {
    Message() {}
    Message(const char* message_str)
        : value { message_str } {
    }
    const char* to_string() const {
        return this->value;
    }
private:
    const char* value;
};

struct CommandExecutor {
    CommandExecutor(const Message& message_obj)
        : message { message_obj } {
    }
    void execute() const {
        printf("%s\n", this->message.to_string());
    }
private:
    const Message message;
};

int main() {
    printf("Hello World!\n");

    int my_variable{ 10 };
    int* my_ptr = &my_variable;
    printf("Address of my_variable: %p\n", &my_variable);
    printf("Value of my_ptr (x): %p\n", my_ptr);

    printf("Value of my_variable through my_ptr: %d\n", *my_ptr);

    *my_ptr *= 10;

    printf("Value of my_variable: %d\n", my_variable);

    printf("\n\n###########################################\n\n");

    Message my_message{ "Hello!" };
    CommandExecutor executor{ my_message };
    auto& executor_ptr{ executor };
    executor_ptr.execute();

    printf("\n\n\n\n\n\n\n");
    return 0;
}
