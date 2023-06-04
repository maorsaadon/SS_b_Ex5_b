#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    class Node
    {
    private:
        int _data;
        Node* _nextPrime;
        Node* _prevPrime;
        bool _isPrime;

        // helper functions
        bool checkIsPrime();

    public:
        // constructors
        Node(int data);

        // getters
        int getData();
        Node* getNextPrime();
        Node* getPrevPrime();
        bool getIsPrime();

        // setters
        void setNextPrime(Node* nextPrime);
        void setPrevPrime(Node* prevPrime);

        bool operator==(const Node &other);
    };
}