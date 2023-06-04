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
        vector<Node*> _elements;
        Node *_firstPrime;

        void addPrimeNumber(Node *newNode);
        void addCompositeNumber(Node *newNode);
        void insertToPrimes(Node* prevPrime, Node *newNode);
        void insertToNumbers(int next, Node *newNode);
        void removeFromPrimes(Node *deletedNode);
        void removeFromNumbers(Node *deletedNode);

    public:
        
        MagicalContainer();

        class Iterator;
        class AscendingIterator;
        class PrimeIterator;
        class SideCrossIterator;
        
        int getIndex(Node* node);
        Node *getFirstPrime() const;

        size_t size();
        void addElement(int number);
        void removeElement(int number);

        ~MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        MagicalContainer(MagicalContainer &&other) noexcept;
        MagicalContainer &operator=(MagicalContainer other);
        MagicalContainer &operator=(MagicalContainer &&other) noexcept;
    };

 
    class MagicalContainer::Iterator
    {
    private:
        MagicalContainer &_container;
        int _type;
        size_t _index;

    public:
   
        Iterator(MagicalContainer &container, int type, size_t index);
        virtual int operator*() const;
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        bool operator<(const Iterator &other) const;
        virtual bool operator>(const Iterator &other) const;

        size_t getIndex() const;
        MagicalContainer &getContainer() const;
        int getType() const;

        void setIndex(size_t index);

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
        AscendingIterator &operator=(AscendingIterator &other);
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
        PrimeIterator &operator=(PrimeIterator &other);
        PrimeIterator &operator=(PrimeIterator &&other) noexcept;

        
        PrimeIterator &operator++() override;
        PrimeIterator begin() const;
        PrimeIterator end() const;
    };

    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        Node *lastIt_;
        size_t counter_;
        SideCrossIterator(MagicalContainer &container, size_t index);

    public:
        SideCrossIterator(MagicalContainer &container);

        ~SideCrossIterator() override = default;
        SideCrossIterator(SideCrossIterator const &other);
        SideCrossIterator(SideCrossIterator &&other) noexcept = default;
        SideCrossIterator &operator=(SideCrossIterator &other);
        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

       
        virtual bool operator>(const SideCrossIterator &other) const;
        int operator*() const override;
        SideCrossIterator &operator++() override;
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
    };
}