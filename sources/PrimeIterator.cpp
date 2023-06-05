#include "MagicalContainer.hpp"
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, int index) : Iterator(container, Prime, index){}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : Iterator(container, Prime, container._firstPrime){
    if(container.size() == 0) setIndex(container.size());
    if(container._firstPrime == -1 && container._lastPrime == -1) setIndex(container.size());
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator const &other)
    : Iterator(other.getContainer(), Prime, other.getIndex()) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
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

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
{
    if (&this->getContainer() == &other.getContainer())
        this->setIndex(other.getIndex());

    return *this;
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (getIndex() >= getContainer().size())
        throw runtime_error("out of range");

    int next = this->getContainer().getElement(getIndex())->getNextPrime();
    if(next == -1) this->setIndex(getContainer().size());
    else this->setIndex(next);
    return *this;
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
    return PrimeIterator(this->getContainer(), this->getContainer().getFirstPrime());
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{
    return PrimeIterator(this->getContainer(), this->getContainer().size());
}