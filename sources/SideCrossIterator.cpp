#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, int index)
    : Iterator(container, SideCross, index), _first(0), _last(0), _counter(0), _direct(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, int index, int counter)
    : Iterator(container, SideCross, index), _first(0), _last(0), _counter(container.size()), _direct(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    : Iterator(container, SideCross, 0), _first(0), _last(0), _counter(0), _direct(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator const &other)
    : Iterator(other.getContainer(), SideCross, other.getIndex()), _first(other._first), _last(other._last), _counter(other._counter), _direct(other._direct) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this->getType() != other.getType())
        throw runtime_error("Can't assign different iterators");

    if (this != &other)
    {
        if (&this->getContainer() != &other.getContainer())
            throw runtime_error("Can't assign iterators from different containers");

        this->setIndex(other.getIndex());
        this->_first = other._first;
        this->_last = other._last;
        this->_counter = other._counter;
        this->_direct = other._direct;
    }
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
{
    if (&this->getContainer() == &other.getContainer())
    {
        this->setIndex(other.getIndex());
        this->_first = other._first;
        this->_last = other._last;
        this->_counter = other._counter;
        this->_direct = other._direct;
    }

    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if (this->getType() != other.getType())
        throw runtime_error("Can't compare different iterators");

    if (&this->getContainer() != &other.getContainer())
        throw runtime_error("Can't compare iterators from different containers");

    return this->_counter == other._counter;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if (this->getType() != other.getType())
        throw runtime_error("Can't compare different iterators");

    if (&this->getContainer() != &other.getContainer())
        throw runtime_error("Can't compare iterators from different containers");

    if (this->_counter > other._counter)
        return true;

    return false;
}

int MagicalContainer::SideCrossIterator::operator*() const
{

    if (_counter >= getContainer().size())
    {
        throw runtime_error("Can't use dereference operator for nullptr operator");
    }
    if (_direct)
        return getContainer().getElement(_first)->getData();
    else
        return getContainer().getElement(getContainer().size() - _last-1)->getData();
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{

    if (_counter >= getContainer().size())
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
    return SideCrossIterator(this->getContainer());
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
    return SideCrossIterator(this->getContainer(), this->getContainer().size(), this->getContainer().size());
}