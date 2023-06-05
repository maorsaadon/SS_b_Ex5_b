#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::MagicalContainer() : _firstPrime(-1), _lastPrime(-1) {}

// helper functions
void MagicalContainer::updatePrimes()
{
    for (int i = 0; i < _elements.size(); i++)
    {
        
        if (getElement(i)->getIsPrime())
        {
            if(_firstPrime == -1)
                _firstPrime = i;

            if(i > _lastPrime)
                _lastPrime = i;
           
            getElement(i)->setNextPrime(getNextPrimeVector(i));
            getElement(i)->setPrevPrime(getPrevPrimeVector(i));
        }
    }
}

int MagicalContainer::getNextPrimeVector(int index)
{
    for (int i = index + 1; i < _elements.size(); i++)
    {
        if (getElement(i)->getIsPrime())
            return i;
    }
    return -1;
}

int MagicalContainer::getPrevPrimeVector(int index)
{
    for (int i = index - 1; i >= 0; i--)
    {
        if (getElement(i)->getIsPrime())
            return i;
    }
    return -1;
}

void MagicalContainer::insertToNumbers(int next, Node *newNode)
{
    if (next == -1)
        _elements.insert(_elements.begin(), newNode);
    else
        _elements.insert(_elements.begin() + next, newNode);
}

void MagicalContainer::addNumber(Node *newNode)
{

    for (auto element : _elements)
    {
        if (element->getData() >= newNode->getData())
        {
            insertToNumbers(getIndexVector(element), newNode);
            return;
        }
    }
    insertToNumbers(_elements.size(), newNode);
}

void MagicalContainer::removeFromNumbers(Node *deletedNode)
{
    _elements.erase(_elements.begin() + getIndexVector(deletedNode));
    delete deletedNode;
}

void MagicalContainer::addElement(int number)
{
    Node *newNode = new Node(number);
    addNumber(newNode);
    updatePrimes();
}

void MagicalContainer::removeElement(int data)
{
    if (size() == 0)
    {
        throw runtime_error("Can't remove from an empty list");
    }

    for (auto number : _elements)
    {
        int index = getIndexVector(number);
        if (number->getData() == data)
        {
            removeFromNumbers(number);
            this->updatePrimes();
            return;
        }
    }
    throw runtime_error("Can't remove a non-exist element");
}

size_t MagicalContainer::size()
{
    return _elements.size();
}

int MagicalContainer::getIndexVector(Node *node)
{
    int index = -1;
    for (auto element : _elements)
    {
        index++;
        if (element == node)
            return index;
    }
    return index;
}

int MagicalContainer::getFirstPrime() const
{
    return this->_firstPrime;
}

int MagicalContainer::getLastPrime() const
{
    return this->_lastPrime;
}

Node *MagicalContainer::getElement(int index) const
{

    if (index < _elements.size() && index >= 0)
    {
        return _elements.at((size_t)(index));
    }
    return nullptr;
}

// 5 related nethods
MagicalContainer::~MagicalContainer()
{
    for (auto element : _elements)
    {
        delete element;
    }

    _elements.clear();
}

MagicalContainer::MagicalContainer(const MagicalContainer &other) : _elements(other._elements), _firstPrime(-1)
{
    for (auto number : _elements)
        this->addElement(number->getData());
}

MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept
    : _elements(other._elements), _firstPrime(other._firstPrime) {}

MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other)
{

    this->_firstPrime = -1;

    for (auto element : _elements)
        this->addElement(element->getData());

    return *this;
}

MagicalContainer &MagicalContainer::operator=(MagicalContainer &&other) noexcept
{
    this->_firstPrime = other._firstPrime;
    this->_elements = other._elements;

    return *this;
}