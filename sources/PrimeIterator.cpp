#include "MagicalContainer.hpp"
using namespace ariel;

// PrimeIterator constructor with index
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t index) : Iterator(container, Prime, index){}

// PrimeIterator default constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : Iterator(container, Prime, container._firstPrime){
    // If the container is empty, set the index to the end
    if(container.size() == 0) this->_index = container.size();
    // If there are no prime elements, set the index to the end
    if(container._firstPrime == maxValue && container._lastPrime == maxValue) this->_index = container.size();
}

// PrimeIterator copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator const &other)
    : Iterator(other._container, Prime, other._index) {}

// PrimeIterator copy assignment operator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
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

// PrimeIterator move assignment operator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
{
    if (this == &other)
        return *this;

    if (&this->_container == &other._container){
        this->_index = other._index;
        this->_counter = other._counter;
    }
        
    return *this;
}

// PrimeIterator pre-increment operator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (_index >= _container.size())
        throw runtime_error("out of range");

    // Get the index of the next prime element
    size_t next = this->_container.getElement(_index)->getNextPrime();
    // If there is no next prime, set the index to the end
    if(next == maxValue) _index = _container.size();
    else _index = next;
    return *this;
}

// PrimeIterator begin function
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
    return PrimeIterator(this->_container, this->_container.getFirstPrime());
}

// PrimeIterator end function
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{
    return PrimeIterator(this->_container, this->_container.size());
}
