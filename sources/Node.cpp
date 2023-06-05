#include "Node.hpp"
using namespace ariel;

// constructor
Node::Node(int data): _data(data), _nextPrime(-1), _prevPrime(-1)
{
    this->_isPrime = this->checkIsPrime();
}

// helper function
bool Node::checkIsPrime()
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

// getters
int Node::getData()
{
    return this->_data;
}

int Node::getNextPrime()
{
    return this->_nextPrime;
}

int Node::getPrevPrime()
{
    return this->_prevPrime;
}

bool Node::getIsPrime()
{
    return this->_isPrime;
}

// setters
void Node::setNextPrime(int nextPrime)
{
    this->_nextPrime = nextPrime;
}

void Node::setPrevPrime(int prevPrime)
{
    this->_prevPrime = prevPrime;
}

bool Node::operator==(const Node &other)
{
    return (this->_data == other._data);
}