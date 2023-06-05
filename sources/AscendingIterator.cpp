#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : Iterator(container, Ascending, 0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, int index)
    : Iterator(container, Ascending, index) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
    : Iterator(other.getContainer(), Ascending, other.getIndex()) {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this->getType() != other.getType())
        throw runtime_error("Can't assign different iterators");

    if (this != &other)
    {
        if (&this->getContainer() != &other.getContainer())
            throw runtime_error("Can't assign iterators from different containers");

        this->setIndex(other.getIndex());
    }
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
{
    if (&this->getContainer() == &other.getContainer())
        this->setIndex(other.getIndex());

    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (getIndex() >= getContainer().size())
        throw std::runtime_error("Iterator out of range");

    this->setIndex(this->getIndex() + 1);
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
    return AscendingIterator(this->getContainer());
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
    return AscendingIterator(this->getContainer(), this->getContainer().size());
}