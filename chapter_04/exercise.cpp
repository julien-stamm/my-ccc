#include <ctime>
#include <cstdio>
#include <iostream>

struct TimerClass {
    TimerClass() :
        timestamp{ std::clock() } {
    }
    ~TimerClass() {
        if (timestamp > 0) {
            std::cout << "Age of the timer: " << (std::clock() - timestamp) << std::endl;
        }
    }

    // Copy constructor
    TimerClass(const TimerClass& other) :
        timestamp{ other.timestamp } {}

    // Copy assignment
    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        return *this;
    }

    // Move constructor
    TimerClass(TimerClass&& other) noexcept :
        timestamp{ other.timestamp } {
            other.timestamp = 0;
        }

    // Move assignment
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        other.timestamp = 0;
        return *this;
    }
private:
    std::clock_t timestamp;
};

int main() {
    TimerClass a{};
    TimerClass b{ a }; // Call copy constructor
    
    TimerClass c{};
    TimerClass d{};
    d = c; // Call copy assignment

    TimerClass e{};
    TimerClass f{ std::move(e) }; // Call move constructor

    TimerClass g{};
    TimerClass h{};
    h = std::move(g); // Call move assignment

    // e and g destructors don't print messages

    // TODO: Do 4-5 next

    return 0;
}