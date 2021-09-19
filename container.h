//
// Created by Antony Sudov on 19.09.2021.
//
#include <unordered_set>
#include <random>

#ifndef CONTAINER_CONTAINER_H
#define CONTAINER_CONTAINER_H


class container {
public:
    void push(int element);

    void remove(int element);

    int pick_random();

    container();

private:
    std::mt19937_64 gen;
    std::unordered_multiset<int> set;
    std::uniform_int_distribution<size_t> distrib;
};


#endif //CONTAINER_CONTAINER_H
