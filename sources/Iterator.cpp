#include "MagicalContainer.hpp"

using namespace ariel;

// Iterator constructor
MagicalContainer::Iterator::Iterator(MagicalContainer &container, size_t type, size_t index) : _container(container), _type(type), _index(index), _counter(0) {}

// Iterator constructor with counter
MagicalContainer::Iterator::Iterator(MagicalContainer &container, size_t type, size_t index, size_t counter) : _container(container), _type(type), _index(index), _counter(counter) {}

// Copy constructor
MagicalContainer::Iterator::Iterator(const Iterator &other) : _container(other._container), _type(other._type), _index(other._index), _counter(other._counter) {}

// Move constructor
MagicalContainer::Iterator::Iterator(Iterator &&other) noexcept : _container(other._container), _type(other._type), _index(other._index), _counter(other._counter) {}

// Copy assignment operator
MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(const Iterator &other)
{
    if (this == &other)
        return *this;
    
    if (this->_type != other._type)
        throw runtime_error("Can't assign different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't assign iterators from different containers");

    this->_counter = other._counter;
    this->_index = other._index;
    return *this;
}

// Move assignment operator
MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(Iterator &&other) noexcept
{
    if (this == &other)
        return *this;

    if (this->_type == other._type && &this->_container == &other._container)
    {
        this->_counter = other._counter;
        this->_index = other._index;
    }

    return *this;
}

// Dereference operator
int MagicalContainer::Iterator::operator*() const
{
    if (_index >= _container.size())
        throw std::out_of_range("Iterator out of range");

    return (_container.getElement(_index)->getData());
}

// Equality comparison operator
bool MagicalContainer::Iterator::operator==(const Iterator &other) const
{
    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    if (_type == SideCross)
    {
        return (this->_counter == other._counter);     
    }

    return (this->_index == other._index);
}

// Inequality comparison operator
bool MagicalContainer::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}

// Greater than comparison operator
bool MagicalContainer::Iterator::operator>(const Iterator &other) const
{
    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    if (this->_container.getElement(_index) == nullptr && other._container.getElement(other._index) == nullptr)
        return false;

    if (this->_container.getElement(_index) == nullptr)
        return true;

    if (other._container.getElement(_index) == nullptr)
        return false;

    if (_type == SideCross)
        return (this->_counter > other._counter);

    return this->_container.getElement(_index)->getData() > other._container.getElement(other._index)->getData();   
}

// Less than comparison operator
bool MagicalContainer::Iterator::operator<(const Iterator &other) const
{

    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    return !(*this > other || *this == other);
}

