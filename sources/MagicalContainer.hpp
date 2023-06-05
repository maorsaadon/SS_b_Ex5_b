#pragma once
#include "Node.hpp"
#include <vector>

constexpr int Ascending = 1;
constexpr int SideCross = 2;
constexpr int Prime = 3;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<Node *> _elements;
        int _firstPrime;
        int _lastPrime;
       
        void updatePrimes();
        int getNextPrimeVector(int index);
        int getPrevPrimeVector(int index);
        void addNumber(Node *newNode);
        void insertToNumbers(int next, Node *newNode);
        void removeFromPrimes(Node *deletedNode);
        void removeFromNumbers(Node *deletedNode);

    public:
        MagicalContainer();

        class Iterator;
        class AscendingIterator;
        class PrimeIterator;
        class SideCrossIterator;

        int getIndexVector(Node *node); 
        int getFirstPrime() const;
        int getLastPrime() const;
        Node *getElement(int index) const;

        size_t size();
        void addElement(int number);
        void removeElement(int number);

        void printElements(){
            
            cout << "firstPrime: " << _firstPrime << " lastPrime: " << _lastPrime << endl;
            for(auto element : _elements)
                cout << "number: " << element->getData() << " prime: " << element->getIsPrime() << " nextPrime: " << element->getNextPrime() << " prevPrime: " << element->getPrevPrime() << endl;
        }

        ~MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        MagicalContainer(MagicalContainer &&other) noexcept;
        MagicalContainer &operator=(const MagicalContainer &other);
        MagicalContainer &operator=(MagicalContainer &&other) noexcept;
    };

    class MagicalContainer::Iterator
    {
    private:
        MagicalContainer &_container;
        int _type;
        int _index;

    public:
        Iterator(MagicalContainer &container, int type, int index);
        virtual int operator*() const;
        virtual bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        bool operator<(const Iterator &other) const;
        virtual bool operator>(const Iterator &other) const;

        int getIndex() const;
        MagicalContainer &getContainer() const;
        int getType() const;

        void setIndex(int index);

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
        AscendingIterator(MagicalContainer &container, int index);

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
        PrimeIterator(MagicalContainer &container, int index);

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
        size_t _counter;
        SideCrossIterator(MagicalContainer &container, int index);
        SideCrossIterator(MagicalContainer &container, int index, int counter);

    public:
        SideCrossIterator(MagicalContainer &container);

        ~SideCrossIterator() override = default;
        SideCrossIterator(SideCrossIterator const &other);
        SideCrossIterator(SideCrossIterator &&other) noexcept = default;
        SideCrossIterator &operator=(const SideCrossIterator &other);
        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

        bool operator==(const SideCrossIterator &other) const;
        bool operator>(const SideCrossIterator &other) const;
        int operator*() const override;
        SideCrossIterator &operator++() override;
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
    };
}