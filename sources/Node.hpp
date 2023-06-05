#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    class Node
    {
    private:
        int _data;
        int _nextPrime;
        int _prevPrime;
        bool _isPrime;

        // helper functions
        bool checkIsPrime();

    public:
        // constructors
        Node(int data);

        // getters
        int getData();
        int getNextPrime();
        int getPrevPrime();
        bool getIsPrime();

        // setters
        void setNextPrime(int nextPrime);
        void setPrevPrime(int prevPrime);

        bool operator==(const Node &other);
    };
}