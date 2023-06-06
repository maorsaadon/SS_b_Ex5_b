#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index)
    : Iterator(container, SideCross, index), _first(0), _last(0), _direct(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index, size_t counter)
    : Iterator(container, SideCross, index, counter), _first(0), _last(0), _direct(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    : Iterator(container, SideCross, 0), _first(0), _last(0), _direct(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator const &other)
    : Iterator(other._container, SideCross, other._index, other._counter), _first(other._first), _last(other._last), _direct(other._direct) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this == &other)
        return *this;

    if (this->_type != other._type)
        throw runtime_error("Can't assign different iterators");

   
    if (&this->_container != &other._container)
        throw runtime_error("Can't assign iterators from different containers");

    this->_index = other._index;
    this->_first = other._first;
    this->_last = other._last;
    this->_counter = other._counter;
    this->_direct = other._direct;
    
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
{
    if (&this->_container == &other._container)
    {
        this->_index = other._index;
        this->_first = other._first;
        this->_last = other._last;
        this->_counter = other._counter;
        this->_direct = other._direct;
    }

    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const
{

    if (_counter >= _container.size())
    {
        throw runtime_error("Can't use dereference operator for nullptr operator");
    }
    if (_direct)
        return _container.getElement(_first)->getData();
    else
        return _container.getElement(_container.size() - _last-1)->getData();
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{

    if (_counter >= _container.size())
        throw runtime_error("out of range");

    if (_direct)
    {
        _first++;
        _direct = false;
    }

    else
    {
        _last++;
        _direct = true;
    }

    this->_counter++;

    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
{
    return SideCrossIterator(this->_container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
    return SideCrossIterator(this->_container, this->_container.size(), this->_container.size());
}