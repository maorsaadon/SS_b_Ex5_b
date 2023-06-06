#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::MagicalContainer() : _firstPrime(maxValue), _lastPrime(maxValue) {}

MagicalContainer::~MagicalContainer()
{
    for (auto element : _elements)
    {
        delete element;
    }

    _elements.clear();
}

MagicalContainer::MagicalContainer(const MagicalContainer &other) : _firstPrime(other._firstPrime), _lastPrime(other._lastPrime)
{
    for (auto element : _elements)
        this->removeElement(element->getData());
    for (auto element : other._elements)
        this->addElement(element->getData());
}

MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept
    : _elements(other._elements), _firstPrime(other._firstPrime), _lastPrime(other._lastPrime) {}

MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other)
{
    if (this == &other)
        return *this;

    this->_firstPrime = maxValue;
    this->_lastPrime = maxValue;
    for (auto element : _elements)
        this->removeElement(element->getData());
    for (auto element : _elements)
        this->addElement(element->getData());

    return *this;
}

MagicalContainer &MagicalContainer::operator=(MagicalContainer &&other) noexcept
{
    if (this == &other)
        return *this;

    this->_firstPrime = maxValue;
    this->_lastPrime = maxValue;
    for (auto element : _elements)
        this->removeElement(element->getData());
    for (auto element : _elements)
        this->addElement(element->getData());

    return *this;
}

void MagicalContainer::updatePrimes()
{
    for (size_t i = 0; i < _elements.size(); i++)
    {
        if (getElement(i)->getIsPrime())
        {
            if (_firstPrime == maxValue && _lastPrime == maxValue)
            {
                _firstPrime = i;
                _lastPrime = i;
            }
            else
            {
                getElement(_lastPrime)->setNextPrime(i);
                getElement(i)->setPrevPrime(_lastPrime);
                getElement(i)->setNextPrime(maxValue);
                _lastPrime = i;
            }
        }
    }
}

void MagicalContainer::addElement(int data)
{
    Node *newNode = new Node(data);
    auto it = lower_bound(_elements.begin(), _elements.end(), newNode, [](const Node *a, const Node *b)
                          { return a->getData() < b->getData(); });

    _elements.insert(it, newNode);
    updatePrimes();
}

void MagicalContainer::removeElement(int data)
{
    if (size() == 0)
        throw runtime_error("Can't remove from an empty list");

    for (size_t i = 0; i < _elements.size(); i++)
    {
        Node *deletedNode = getElement(i);
        if (deletedNode->getData() == data)
        {
            _elements.erase(_elements.begin() + int(i));
            delete deletedNode;
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

size_t MagicalContainer::getFirstPrime() const
{
    return this->_firstPrime;
}

size_t MagicalContainer::getLastPrime() const
{
    return this->_lastPrime;
}

Node *MagicalContainer::getElement(size_t index) const
{

    if (index < _elements.size())
        return _elements.at(index);
    return nullptr;
}
