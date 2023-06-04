#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::MagicalContainer() {}

// helper functions
void MagicalContainer::insertToPrimes(Node *prevPrime, Node *newNode)
{
    if (prevPrime == nullptr)
    {
        newNode->setNextPrime(this->_firstPrime);
        if (this->_firstPrime != nullptr)
            _firstPrime->setPrevPrime(newNode);

        this->_firstPrime = newNode;
    }
    else
    {
        Node *nextPrime = prevPrime->getNextPrime();
        newNode->setNextPrime(nextPrime);
        newNode->setPrevPrime(prevPrime);
        prevPrime->setNextPrime(newNode);
        if (nextPrime != nullptr)
            nextPrime->setPrevPrime(newNode);
    }
}

void MagicalContainer::insertToNumbers(int next, Node *newNode)
{
    // add the number to the first value
    if (next == -1)
        _elements.insert(_elements.begin(), newNode);
    else
        _elements.insert(_elements.begin() + next, newNode);
}

void MagicalContainer::addPrimeNumber(Node *newNode)
{
    Node *prevPrime = nullptr;

    for (auto number : _elements)
    {
        // found the place to insert
        if (number->getData() >= newNode->getData())
        {
            insertToPrimes(number->getPrevPrime(), newNode);
            insertToNumbers(getIndex(number), newNode);
            return;
        }

        // update the last prime
        if (number->getIsPrime())
            prevPrime = number;
    }

    insertToPrimes(prevPrime, newNode);
    insertToNumbers(_elements.size(), newNode);
}
void MagicalContainer::addCompositeNumber(Node *newNode)
{

    for (auto number : _elements)
    {
        if (number->getData() >= number->getData())
        {
            insertToNumbers(getIndex(number), newNode);
            return;
        }
    }
    insertToNumbers(_elements.size(), newNode);
}

void MagicalContainer::removeFromPrimes(Node *deletedNode)
{
    Node *prevPrime = deletedNode->getPrevPrime();
    Node *nextPrime = deletedNode->getNextPrime();

    if (prevPrime != nullptr)
        prevPrime->setNextPrime(nextPrime);

    if (nextPrime != nullptr)
        nextPrime->setPrevPrime(prevPrime);

    if (this->_firstPrime == deletedNode)
        this->_firstPrime = nextPrime;
}

void MagicalContainer::removeFromNumbers(Node *deletedNode)
{
    _elements.erase(_elements.begin() + getIndex(deletedNode));
}

void MagicalContainer::addElement(int number)
{
    // create new Node
    Node *newNode = new Node(number);
    if (newNode->getIsPrime())
        addPrimeNumber(newNode);
    else
        addCompositeNumber(newNode);
}

void MagicalContainer::removeElement(int data)
{
    if (size() == 0)
    {
        throw runtime_error("Can't remove from an empty list");
    }

    for (auto number : _elements)
    {
        if (number->getData() == data)
        {
            // change the pointers
            if (number->getIsPrime())
            {
                removeFromPrimes(number);
            }

            // remove from the list
            removeFromNumbers(number);
            return;
        }
    }
    // didn't found the number
    throw runtime_error("Can't remove a non-exist element");
}

size_t MagicalContainer::size()
{
    return _elements.size();
}

// getters
int MagicalContainer::getIndex(Node *node)
{
    int index = -1;
    for (auto number : _elements)
    {
        index++;
        if (number == node)
            return index;
    }
    return index;
}


Node *MagicalContainer::getFirstPrime() const 
{
    return this->_firstPrime;
}

// 5 related nethods
MagicalContainer::~MagicalContainer()
{
    for (auto number : _elements)
    {
        delete number;
    }

    _elements.clear();
}

MagicalContainer::MagicalContainer(const MagicalContainer &other)
    : _elements(NULL), _firstPrime(nullptr)
{
    for (auto number : _elements)
    {
        this->addElement(number->getData());
    }
}

MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept
    : _elements(other._elements), _firstPrime(other._firstPrime) {}

MagicalContainer &MagicalContainer::operator=(MagicalContainer other)
{

    this->_firstPrime = nullptr;

    for (auto number : _elements)
    {
        this->addElement(number->getData());
    }

    return *this;
}

MagicalContainer &MagicalContainer::operator=(MagicalContainer &&other) noexcept
{
    this->_firstPrime = other._firstPrime;
    this->_elements = other._elements;

    return *this;
}