#pragma once
#include <iostream>
#include <numeric>
#include <limits>

constexpr size_t maxValue = std::numeric_limits<size_t>::max();

using namespace std;


namespace ariel
{
    class Node
    {
    private:
        int _data;
        size_t _nextPrime;
        size_t _prevPrime;
        bool _isPrime;

        // helper functions
        bool isPrime();

    public:
        // constructors
        Node(int data);

        // getters
        int getData() const;
        size_t getNextPrime() const;
        size_t getPrevPrime() const;
        bool getIsPrime() const;

        // setters
        void setNextPrime(size_t nextPrime);
        void setPrevPrime(size_t prevPrime);

        bool operator==(const Node &other);
    };
}