#include <cstdio>
#include <stdexcept>
#include <iostream>
#include <cstring>

class Entry {
public:
    Entry(const std::string value) : value{ value } { }
    bool is_valid() const {
        return value.length() <= 10;
    }
    const std::string get_value() const {
        return value;
    }
    bool save() const {
        return is_valid();
    }
private:
    const std::string value;
};

struct Result {
    Entry entry;
    bool has_been_saved;
};

// -------------------------------------------------------------------------------------------

// 1.
void check_if_entry_is_valid(const Entry& entry) {
    std::string result = entry.is_valid() ? "valid" : "invalid";
    std::cout << "Entry (\"" << entry.get_value() << "\"): " << result << std::endl;
}

// 2.
Result try_saving(const Entry& entry) {
    bool success = entry.save();
    return { entry, success };
};

void save_and_print_result(const Entry& entry) {
    auto [_, success] = try_saving(entry);
    std::string result = success ? "saved" : "not saved";
    std::cout << "Entry (\"" << _.get_value() << "\"): " << result << std::endl;
}

// -------------------------------------------------------------------------------------------

struct SimpleString {
    SimpleString(size_t max_size) :
        max_size{ max_size },
        length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." };
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }
    ~SimpleString() {
        delete[] buffer;
    }
    SimpleString(const SimpleString& other) :
        max_size{ other.max_size },
        buffer{ new char[other.max_size] },
        length{ other.length } {
            std::strncpy(buffer, other.buffer, max_size);
        }
    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }
    bool append_line(const char* x) {
        const auto x_len = strlen(x);
        if (x_len + length + 2 > max_size) return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
private:
    size_t max_size;
    char* buffer;
    size_t length;
};

void foo(SimpleString x) {
    x.append_line("This change is lost.");
}

int main() {
    try {
        // throw std::string{ "Wow!" };
    } catch (const std::exception& e) {
        printf("%s\n", e.what());
    } catch (const std::string e) {
        std::cout << e << std::endl;
    }

    printf("\n\n");

    const Entry entry_1{ "new_value" };
    check_if_entry_is_valid(entry_1);
    save_and_print_result(entry_1);

    const Entry entry_2{ "new_value---------------------" };
    check_if_entry_is_valid(entry_2);
    save_and_print_result(entry_2);

    printf("\n\n");
    printf("\n\n");

    std::cout << "\n-------------------------------------\n";

    SimpleString a{ 20 };
    foo(a); // Invokes copy constructor
    a.print("Still empty\n\n");

    return 0;
}