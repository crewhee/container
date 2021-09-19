//
// Created by Antony Sudov on 19.09.2021.
//

#include "container.h"
#include <cstdlib>
#include <iostream>
#include <ctime>


container::container() {
    this->gen = std::mt19937_64(time(0));
    this->set = std::unordered_multiset<int>();
    this->distrib = std::uniform_int_distribution<size_t>{0, 0};
}

void container::push(int element) {
    this->set.insert(element);
}

void container::remove(int element) {
    if (this->set.empty()) {
        std::cout << "Container is already empty";
        return;
    }
    auto it = this->set.find(element);
    if (it == this->set.end()) {
        std::cout << "No such element in container";
        return;
    }
    else
        this->set.erase(it);
}

int container::pick_random() {
    if (this->distrib.b() != this->set.size() - 1)
        this->distrib.param(std::uniform_int_distribution<size_t>::param_type(0, this->set.size() - 1));
    size_t pos = this->distrib(this->gen);
    auto it = this->set.begin();
    std::advance(it, pos);
    return *(it);
}
