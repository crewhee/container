#include <iostream>
#include "container.h"
#include <map>

int main() {
    std::cout << "Check pick_random distribution (for 5 different elements):" << std::endl;
    container h;
    for (int i = 0; i < 5; i++)
        h.push(i);
    std::map<int, int> hist {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}};

    for (int j = 0; j < 1000; j++)
        hist[h.pick_random()]++;

    for (const auto& [key, value] : hist)
        std::cout << key << ": " << value << std::endl;
    return 0;
}
