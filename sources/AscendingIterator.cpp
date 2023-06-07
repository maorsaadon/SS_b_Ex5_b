#include "MagicalContainer.hpp"
using namespace ariel;

// AscendingIterator default constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : Iterator(container, Ascending, 0) {}

// AscendingIterator constructor with index
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index)
    : Iterator(container, Ascending, index) {}

// AscendingIterator copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
    : Iterator(other._container, Ascending, other._index) {}

// AscendingIterator copy assignment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this == &other)
        return *this;

    if (this->_type != other._type)
        throw runtime_error("Can't assign different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't assign iterators from different containers");

    this->_index = other._index;
    this->_counter = other._counter;

    return *this;
}

// AscendingIterator move assignment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
{
    if (this == &other)
        return *this;

    if (&this->_container == &other._container){
        this->_index = other._index;
        this->_counter = other._counter;
    }

    return *this;
}

// AscendingIterator pre-increment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (this->_index >= _container.size())
        throw std::runtime_error("Iterator out of range");

    this->_index++;
    this->_counter++;
    return *this;
}

// AscendingIterator begin function
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
    return AscendingIterator(this->_container);
}

// AscendingIterator end function
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
    return AscendingIterator(this->_container, this->_container.size());
}
