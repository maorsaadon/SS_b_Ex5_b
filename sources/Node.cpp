#include "Node.hpp"
using namespace ariel;

// Node constructor
Node::Node(int data): _data(data), _nextPrime(maxValue), _prevPrime(maxValue)
{
    this->_isPrime = this->isPrime(); // Check if the data is prime
}

// Helper function to check if the data is prime
bool Node::isPrime()
{
    if (this->_data < 2)
        return false;
    for (int i = 2; i * i <= this->_data; i++)
    {
        if (this->_data % i == 0)
            return false;
    }
    return true;
}

// Getter functions
int Node::getData() const
{
    return this->_data;
}

size_t Node::getNextPrime() const
{
    return this->_nextPrime;
}

size_t Node::getPrevPrime() const
{
    return this->_prevPrime;
}

bool Node::getIsPrime() const
{
    return this->_isPrime;
}

// Setter functions
void Node::setNextPrime(size_t nextPrime)
{
    this->_nextPrime = nextPrime;
}

void Node::setPrevPrime(size_t prevPrime)
{
    this->_prevPrime = prevPrime;
}

// Equality comparison operator
bool Node::operator==(const Node &other)
{
    return (this->_data == other._data);
}
