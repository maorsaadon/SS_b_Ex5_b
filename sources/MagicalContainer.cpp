#include "MagicalContainer.hpp"
using namespace ariel;

// Default constructor
MagicalContainer::MagicalContainer() : _firstPrime(maxValue), _lastPrime(maxValue) {}

// Destructor
MagicalContainer::~MagicalContainer()
{
    // Delete all elements in the container
    for (auto element : _elements)
    {
        delete element;
    }

    _elements.clear(); // Clear the container
}

// Copy constructor
MagicalContainer::MagicalContainer(const MagicalContainer &other) : _firstPrime(other._firstPrime), _lastPrime(other._lastPrime)
{
    // Remove all elements from this container
    for (auto element : _elements)
        this->removeElement(element->getData());

    // Add elements from the other container
    for (auto element : other._elements)
        this->addElement(element->getData());
}

// Move constructor
MagicalContainer::MagicalContainer(MagicalContainer &&other) noexcept
    : _elements(other._elements), _firstPrime(other._firstPrime), _lastPrime(other._lastPrime) {}

// Copy assignment operator
MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other)
{
    if (this == &other)
        return *this;

    this->_firstPrime = maxValue;
    this->_lastPrime = maxValue;

    // Remove all elements from this container
    for (auto element : _elements)
        this->removeElement(element->getData());

    // Add elements from the other container
    for (auto element : _elements)
        this->addElement(element->getData());

    return *this;
}

// Move assignment operator
MagicalContainer &MagicalContainer::operator=(MagicalContainer &&other) noexcept
{
    if (this == &other)
        return *this;

    this->_firstPrime = maxValue;
    this->_lastPrime = maxValue;

    // Remove all elements from this container
    for (auto element : _elements)
        this->removeElement(element->getData());

    // Add elements from the other container
    for (auto element : _elements)
        this->addElement(element->getData());

    return *this;
}

// Update the prime indices in the container
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
                // Set the next prime index for the current prime
                getElement(_lastPrime)->setNextPrime(i);
                // Set the previous prime index for the current prime
                getElement(i)->setPrevPrime(_lastPrime);
                // Set the next prime index for the current index as maxValue
                getElement(i)->setNextPrime(maxValue);
                _lastPrime = i; // Update the last prime index
            }
        }
    }
}

// Add an element to the container
void MagicalContainer::addElement(int data)
{
    Node *newNode = new Node(data);
    // Find the correct position to insert the new element using lower_bound
    //https://www.geeksforgeeks.org/lower_bound-in-cpp/
    auto it = lower_bound(_elements.begin(), _elements.end(), newNode, [](const Node *a, const Node *b)
                          { return a->getData() < b->getData(); });

    _elements.insert(it, newNode); // Insert the new element at the correct position
    updatePrimes(); // Update the prime indices
}

// Remove an element from the container
void MagicalContainer::removeElement(int data)
{
    if (size() == 0)
        throw runtime_error("Can't remove from an empty list");

    // Find and remove the element with the given data
    for (size_t i = 0; i < _elements.size(); i++)
    {
        Node *deletedNode = getElement(i);
        if (deletedNode->getData() == data)
        {
            _elements.erase(_elements.begin() + int(i)); // Erase the element from the container
            delete deletedNode; // Delete the element
            this->updatePrimes(); // Update the prime indices
            return;
        }
    }
    throw runtime_error("Can't remove a non-existent element");
}

// Get the size of the container
size_t MagicalContainer::size()
{
    return _elements.size();
}

// Get the index of the first prime element
size_t MagicalContainer::getFirstPrime() const
{
    return this->_firstPrime;
}

// Get the index of the last prime element
size_t MagicalContainer::getLastPrime() const
{
    return this->_lastPrime;
}

// Get the element at the specified index
Node *MagicalContainer::getElement(size_t index) const
{
    if (index < _elements.size())
        return _elements.at(index);
    return nullptr;
}
