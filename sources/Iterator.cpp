#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::Iterator::Iterator(MagicalContainer &container, int type, size_t index) : _container(container), _type(type), _index(index){}

int MagicalContainer::Iterator::operator*() const
{
    if (_index >= _container.size())
		throw std::out_of_range("Iterator out of range");

	return (_container._elements.at(_index)->getData());
}
// Equality comparison(operator==)
bool MagicalContainer::Iterator::operator==(const Iterator &other) const
{
    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    return (this->_index == other._index);
}
// Inequality comparison(operator!=)
bool MagicalContainer::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}
//  GT, LT comparison (operator>, operatorn<)
bool MagicalContainer::Iterator::operator>(const Iterator &other) const
{
    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");

    // if (this->_index == 0 && other._index == 0)
    //     return false;
    
    // if (this->_index == 0)
    //     return true;

    // if (other._index == 0)
    //     return false;

    // if (this->getContainer()._elements.at(_index)->getData() > other.getContainer()._elements.at(other._index)->getData())
    //     return true;

    // return false;

    return _index < other._index;
}
bool MagicalContainer::Iterator::operator<(const Iterator &other) const
{

    if (this->_type != other._type)
        throw runtime_error("Can't compare different iterators");

    if (&this->_container != &other._container)
        throw runtime_error("Can't compare iterators from different containers");
    // if (this->_index == 0 && otherIt._index == 0)
    //     return false;

    // return !(*this > otherIt || *this == otherIt);

    return _index > other._index;

}

// getters
size_t MagicalContainer::Iterator::getIndex() const
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
void MagicalContainer::Iterator::setIndex(size_t index)
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