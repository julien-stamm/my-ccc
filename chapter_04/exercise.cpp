#include <cstdio>
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <utility>

struct TimerClass {
    TimerClass(const char* name) :
        timestamp{ std::clock() },
        name{ name } {
    }
    ~TimerClass() {
        if (timestamp > 0) {
            std::cout << "Age of the timer \"" << name << "\": " << timer_age() << std::endl;
        } 
    }

    // Copy constructor
    TimerClass(const char* name, const TimerClass& other) :
        name{ name },
        timestamp{ other.timestamp } {
            int a = 0;
        }

    // Move constructor
    TimerClass(TimerClass&& other) noexcept :
        name{ other.name },
        timestamp{ other.timestamp } {
            other.name = nullptr;
            other.timestamp = 0;
        }

    // Copy assignment
    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        return *this;
    }

    // Move assignment
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) return *this;
        name = other.name;
        timestamp = other.timestamp;
        other.name = nullptr;
        other.timestamp = 0;
        return *this;
    }
private:
    std::clock_t timestamp;
    const char* name;

    const int timer_age() {
        return std::clock() - timestamp;
    }
};

int main() {
    TimerClass a{ "a" };
    TimerClass b{ "b", a }; // Call copy constructor
    
    TimerClass c{ "c" };
    TimerClass d{ std::move(c) }; // Call move constructor
    // c is in a move-from state

    TimerClass e{ "e" };
    TimerClass f{ "f" };
    f = e; // Call copy assignment

    TimerClass g{ "g" };
    TimerClass h{ "h" };
    h = std::move(g); // Call move assignment
    // g is in a move-from state

    // d and h will print as 'c' and 'g' on destruction

    {
        TimerClass math_timer{ "Math Timer" };
        std::cout << "-- Calculation starting --\n";
        for (auto i = 0; i < 1000000000; i++) {
            if (i % 100000000 == 0) {
                std::cout << "|";
            }
        }
        std::cout << "\n-- Calculation finished --\n";
    }

    std::cout << "\n-- End of main --\n";
    return 0;
}