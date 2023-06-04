// #include "MagicalContainer.hpp"
// using namespace ariel;


// MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
//     : Iterator(container, SideCross, container.first_), lastIt_(container.last_), counter_(0) {}

// MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container, Node *iter)
//     : Iterator(container, SideCross, iter), lastIt_(container.last_), counter_(container.size_) {}


// MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator const &otherSCI)
//     : Iterator(otherSCI.getContainer(), SideCross, otherSCI.getIndex()),
//       lastIt_(otherSCI.lastIt_), counter_(otherSCI.counter_) {}

// MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator otherSCI)
// {
//     if (this->getType() != otherSCI.getType())
//         throw runtime_error("Can't assign different iterators");

//     if (this != &otherSCI)
//     {
//         if (&this->getContainer() != &otherSCI.getContainer())
//             throw runtime_error("Can't assign iterators from different containers");

//         this->setIndex(otherSCI.getIndex());
//         this->counter_ = otherSCI.counter_;
//         this->lastIt_ = otherSCI.lastIt_;
//     }
//     return *this;
// }

// MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&otherSCI) noexcept
// {
//     if (&this->getContainer() == &otherSCI.getContainer())
//         this->setIndex(otherSCI.getIndex());

//     return *this;
// }

// bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &otherIt) const
// {
//     if (this->getType() != otherIt.getType())
//         throw runtime_error("Can't compare different iterators");

//     if (&this->getContainer() != &otherIt.getContainer())
//         throw runtime_error("Can't compare iterators from different containers");

//     if (this->counter_ > otherIt.counter_)
//         return true;

//     return false;
// }

// int MagicalContainer::SideCrossIterator::operator*() const
// {
//     if (this->getIndex() == nullptr)
//     {
//         throw runtime_error("Can't use dereference operator for nullptr operator");
//     }
//     if (this->counter_ % 2 == 0)
//         return this->getIndex()->getData();
//     else
//         return this->lastIt_->getData();
// }

// MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
// {
//     if (this->getIndex() == nullptr)
//         throw runtime_error("out of range");

//     if (this->counter_ == this->getContainer().size_ - 1)
//     {
//         this->setIndex(nullptr);
//         this->lastIt_ = nullptr;
//         return *this;
//     }

//     if (this->counter_ % 2 == 0)
//         this->setIndex(this->getIndex()->getNext());
//     else
//         this->lastIt_ = this->lastIt_->getPrev();
//     this->counter_++;
//     return *this;
// }

// MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
// {
//     return SideCrossIterator(this->getContainer());
// }

// MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
// {
//     return SideCrossIterator(this->getContainer(), this->getContainer().size());
// }