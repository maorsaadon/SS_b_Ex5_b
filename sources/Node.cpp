#include "Node.hpp"
using namespace ariel;

// constructor
Node::Node(int data)
    : _data(data), _nextPrime(nullptr), _prevPrime(nullptr)
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

Node* Node::getNextPrime()
{
    return this->_nextPrime;
}
Node* Node::getPrevPrime()
{
    return this->_prevPrime;
}

bool Node::getIsPrime()
{
    return this->_isPrime;
}

// setters
void Node::setNextPrime(Node* nextPrime)
{
    this->_nextPrime = nextPrime;
}

void Node::setPrevPrime(Node* prevPrime)
{
    this->_prevPrime = prevPrime;
}

bool Node::operator==(const Node &other)
{
    return (this->_data == other._data);
}