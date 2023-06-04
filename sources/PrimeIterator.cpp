#include "MagicalContainer.hpp"
using namespace ariel;

// MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : Iterator(container, Prime, container.firstPrime_) {}

// MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, Node *iter) : Iterator(container, Prime, iter) {}

// MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator const &otherPI)
//     : Iterator(otherPI.getContainer(), Prime, otherPI.getIndex()) {}

// MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator otherPI)
// {
//     if (this->getType() != otherPI.getType())
//         throw runtime_error("Can't assign different iterators");

//     if (this != &otherPI)
//     {
//         if (&this->getContainer() != &otherPI.getContainer())
//             throw runtime_error("Can't assign iterators from different containers");

//         this->setIndex(otherPI.getIndex());
//     }
//     return *this;
// }

// MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&otherPI) noexcept
// {
//     if (&this->getContainer() == &otherPI.getContainer())
//         this->setIndex(otherPI.getIndex());

//     return *this;
// }

// MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
// {
//     if (this->getIndex() == nullptr)
//         throw runtime_error("out of range");

//     this->setIndex(this->getIndex()->getNextPrime());
//     return *this;
// }


// MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
// {
//     return PrimeIterator(this->getContainer());
// }

// MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
// {
//     return PrimeIterator(this->getContainer(), this->getContainer().size());
// }