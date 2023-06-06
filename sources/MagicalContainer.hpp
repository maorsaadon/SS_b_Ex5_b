#pragma once
#include "Node.hpp"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
#include <iterator>

constexpr size_t Ascending = 1;
constexpr size_t SideCross = 2;
constexpr size_t Prime = 3;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<Node *> _elements;
        size_t _firstPrime;
        size_t _lastPrime;

        void updatePrimes();

    public:
        MagicalContainer();
        ~MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        MagicalContainer(MagicalContainer &&other) noexcept;
        MagicalContainer &operator=(const MagicalContainer &other);
        MagicalContainer &operator=(MagicalContainer &&other) noexcept;
        void addElement(int data);
        void removeElement(int data);
        size_t size();

        size_t getFirstPrime() const;
        size_t getLastPrime() const;
        Node *getElement(size_t index) const;

        class Iterator;
        class AscendingIterator;
        class PrimeIterator;
        class SideCrossIterator;
    };

    class MagicalContainer::Iterator
    {
    public:
        MagicalContainer &_container;
        size_t _type;
        size_t _index;
        size_t _counter;

        Iterator(MagicalContainer &container, size_t type, size_t index);
        Iterator(MagicalContainer &container, size_t type, size_t index, size_t counter);
        virtual int operator*() const;
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        bool operator<(const Iterator &other) const;
        bool operator>(const Iterator &other) const;

        virtual ~Iterator() = default;
        Iterator(const Iterator &other);
        Iterator(Iterator &&other) noexcept;
        Iterator &operator=(const Iterator &other);
        Iterator &operator=(Iterator &&other) noexcept;

        virtual Iterator &operator++() = 0;
    };

    class MagicalContainer::AscendingIterator : public Iterator
    {
    private:
        AscendingIterator(MagicalContainer &container, size_t index);

    public:
        AscendingIterator(MagicalContainer &container);

        ~AscendingIterator() override = default;
        AscendingIterator(const AscendingIterator &other);
        AscendingIterator(AscendingIterator &&other) noexcept = default;
        AscendingIterator &operator=(const AscendingIterator &other);
        AscendingIterator &operator=(AscendingIterator &&other) noexcept;

        AscendingIterator &operator++() override;

        AscendingIterator begin() const;
        AscendingIterator end() const;
    };

    class MagicalContainer::PrimeIterator : public Iterator
    {
    private:
        PrimeIterator(MagicalContainer &container, size_t index);

    public:
        PrimeIterator(MagicalContainer &container);

        ~PrimeIterator() override = default;
        PrimeIterator(PrimeIterator const &other);
        PrimeIterator(PrimeIterator &&other) noexcept = default;
        PrimeIterator &operator=(const PrimeIterator &other);
        PrimeIterator &operator=(PrimeIterator &&other) noexcept;

        PrimeIterator &operator++() override;
        PrimeIterator begin() const;
        PrimeIterator end() const;
    };

    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        size_t _first;
        size_t _last;
        bool _direct;
        SideCrossIterator(MagicalContainer &container, size_t index);
        SideCrossIterator(MagicalContainer &container, size_t index, size_t counter);

    public:
        SideCrossIterator(MagicalContainer &container);

        ~SideCrossIterator() override = default;
        SideCrossIterator(SideCrossIterator const &other);
        SideCrossIterator(SideCrossIterator &&other) noexcept = default;
        SideCrossIterator &operator=(const SideCrossIterator &other);
        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

        int operator*() const override;
        SideCrossIterator &operator++() override;
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
    };
}