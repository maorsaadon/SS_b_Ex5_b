#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::Iterator::Iterator(MagicalContainer &container, int type, int index) : _container(container), _type(type), _index(index) {}

int MagicalContainer::Iterator::operator*() const
{
    if (_index >= _container.size() || _index < 0)
        throw std::out_of_range("Iterator out of range");

    return (_container.getElement(_index)->getData());
}

bool MagicalContainer::Iterator::operator==(const Iterator &other) const
{
    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    return (this->_index == other._index);
}

bool MagicalContainer::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::Iterator::operator>(const Iterator &other) const
{
    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    if (this->getContainer().getElement(_index) == nullptr && other.getContainer().getElement(other._index) == nullptr)
        return false;

    if(this->getContainer().getElement(_index) == nullptr) return true;

    if(other.getContainer().getElement(_index) == nullptr) return false;

    if (this->getContainer().getElement(_index)->getData() > other.getContainer().getElement(other._index)->getData())
        return true;

    return false;
}
bool MagicalContainer::Iterator::operator<(const Iterator &other) const
{

    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

   return !(*this > other || *this == other);
}

// getters
int MagicalContainer::Iterator::getIndex() const
{
    return this->_index;
}

MagicalContainer &MagicalContainer::Iterator::getContainer() const
{
    return this->_container;
}

int MagicalContainer::Iterator::getType() const
{
    return this->_type;
}

// setters
void MagicalContainer::Iterator::setIndex(int index)
{
    this->_index = index;
}

// 5 related nethods
MagicalContainer::Iterator::Iterator(const Iterator &other) : _container(other._container), _type(other._type), _index(other._index) {}
MagicalContainer::Iterator::Iterator(Iterator &&other) noexcept : _container(other._container), _type(other._type), _index(other._index) {}

MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(const Iterator &other)
{
    if (this->_type != other._type)
        throw runtime_error("Can't assign different iterators");
    if (&this->_container != &other._container)
        throw runtime_error("Can't assign iterators from different containers");

    this->_index = other._index;
    return *this;
}
MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(Iterator &&other) noexcept
{
    if (this->_type != other._type)
        return *this;
    if (&this->_container != &other._container)
        return *this;

    this->_index = other._index;
    return *this;
}