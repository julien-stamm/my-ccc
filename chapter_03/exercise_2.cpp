#include <cstdio>

int main() {
    struct Element {
        Element* next{};
        Element* previous{};
        char prefix[2];
        short operating_number;

        void insert_after(Element* new_element) {
            if (next != 0x0) {
                next->previous = new_element;
                new_element->next = next;
            }
            new_element->previous = this;
            next = new_element;
        }

        void insert_before(Element* new_element) {
            if (previous != 0x0) {
                previous->next = new_element;
                new_element->previous = previous;
            }
            new_element->next = this;
            previous = new_element;
        }
    };

    Element trooper1, trooper2, trooper3, trooper4;
    trooper1.prefix[0] = 'A';
    trooper1.prefix[1] = 'B';
    trooper1.operating_number = 1;
    trooper1.insert_after(&trooper2);
    
    trooper2.prefix[0] = 'C';
    trooper2.prefix[1] = 'D';
    trooper2.operating_number = 2;
    trooper2.insert_after(&trooper4);
    
    trooper4.prefix[0] = 'G';
    trooper4.prefix[1] = 'H';
    trooper4.operating_number = 4;
    trooper4.insert_before(&trooper3);

    trooper3.prefix[0] = 'E';
    trooper3.prefix[1] = 'F';
    trooper3.operating_number = 3;

    for (Element *cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("stormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number
        );
    }

    printf("\n\n");

    for (Element *cursor = &trooper4; cursor; cursor = cursor->previous) {
        printf("stormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number
        );
    }

    printf("\n\n");
}
