// noashalom5@gmail.com
#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <iostream>
#include <vector>
#include <algorithm>

namespace mycontainer_ass4 {

template<typename T = int>
class MyContainer {
private:
    std::vector<T> items;

public:
    // Add an item to the container
    void add(const T& newItem) {
        items.push_back(newItem);
    }

    // Remove an item from the container (if found)
    void remove(const T& item) {
        auto original_size = items.size();
        // remove - shifts non-matching elements to the front and returns an iterator to the new end.
        auto updated_end = std::remove(items.begin(), items.end(), item);
        // erase - removes the remaining elements from the vector.
        items.erase(updated_end, items.end());
         
        if (items.size() == original_size) {
            std::cout << "This item is not found!" << std::endl;
        }
    }

    // Return the size of the container - the number of items in it
    size_t size() const {
        return items.size();
    }

    // Print the container
    friend std::ostream& operator<<(std::ostream& os, const MyContainer& c) {
        os << "[ ";
        for (const auto& element : c.items) {
            os << element << " ";
        }
        os << "]";
        return os;
    }


    // ******************** Iterators ********************


    // The original order
    class Order {
    private:
        const MyContainer& container;
        size_t index;

    public:
        Order(const MyContainer& c, size_t i = 0) : container(c), index(i) {}

        Order& operator++() {
            ++index;
            return *this;
        }

        Order& operator++(int) {
            Order temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Order& other) const {return index == other.index;}

        bool operator!=(const Order& other) const {return index != other.index;}

        const T& operator*() const {return container.items[index];}

        static Order begin(const MyContainer& c) {return Order(c, 0);}

        static Order end(const MyContainer& c) {return Order(c, c.size());}
    };

    // From last element to first
    class ReverseOrder {
    private:
        const MyContainer& container;
        size_t index;

    public:
        ReverseOrder(const MyContainer& c, size_t i) : container(c), index(i) {}

        ReverseOrder& operator++() {
            --index;
            return *this;
        }

        ReverseOrder& operator++(int) {
            ReverseOrder temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ReverseOrder& other) const {return index == other.index;}

        bool operator!=(const ReverseOrder& other) const {return index != other.index;}

        const T& operator*() const {return container.items[index];}

        // The last index
        static ReverseOrder begin(const MyContainer& c) {return ReverseOrder(c, c.size() - 1);} 

        // Before the container begins
        static ReverseOrder end(const MyContainer& c) {return ReverseOrder(c, (size_t) - 1);} 
    };

    // Ascending order (smallest to largest)
    class AscendingOrder {
    private:
        const MyContainer& container;
        size_t index;
        std::vector<size_t> order_container;

    public:
        AscendingOrder(const MyContainer& c, size_t i = 0) : container(c), index(i) {
            size_t n = container.size();
            order_container.resize(n);
            for (size_t m=0 ; m<n ; ++m)
                order_container[m] = m;
            // Sort the new container from smallest to largest 
            std::sort(order_container.begin(), order_container.end(),
                [&](size_t a, size_t b){ return container.items[a] < container.items[b]; });
        }

        AscendingOrder& operator++() {
            ++index;
            return *this;
        }

        AscendingOrder& operator++(int) {
            AscendingOrder temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const AscendingOrder& other) const {return index == other.index;}

        bool operator!=(const AscendingOrder& other) const {return index != other.index;}

        const T& operator*() const {return container.items[order_container[index]];}

        static AscendingOrder begin(const MyContainer& c) {return AscendingOrder(c, 0);}

        static AscendingOrder end(const MyContainer& c) {return AscendingOrder(c, c.size());}
    };

    // Descending order (largest to smallest)
    class DescendingOrder {
    private:
        const MyContainer& container;
        size_t index;
        std::vector<size_t> order_container;
        
    public:
        DescendingOrder(const MyContainer& c, size_t i = 0) : container(c), index(i) {
            size_t n = container.size();
            order_container.resize(n);
            for (size_t m=0 ; m<n ; ++m)
                order_container[m] = m;
            // Sort the new container from largest to smallest 
            std::sort(order_container.begin(), order_container.end(),
                [&](size_t a, size_t b){ return container.items[a] > container.items[b]; });
        }

        DescendingOrder& operator++() {
            ++index;
            return *this;
        }

        DescendingOrder& operator++(int) {
            DescendingOrder temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const DescendingOrder& other) const {return index == other.index;}

        bool operator!=(const DescendingOrder& other) const {return index != other.index;}

        const T& operator*() const {return container.items[order_container[index]];}

        static DescendingOrder begin(const MyContainer& c) {return DescendingOrder(c, 0);}

        static DescendingOrder end(const MyContainer& c) {return DescendingOrder(c, c.size());}
    };

    // Side-cross order: smallest, largest, 2nd smallest, 2nd largest, ...
    class SideCrossOrder {
    private:
        const MyContainer& container;
        size_t index;
        std::vector<size_t> order_container;
        
    public:
        SideCrossOrder(const MyContainer& c, size_t i = 0) : container(c), index(i) {
            size_t n = container.size();
            order_container.resize(n);
            for (size_t m = 0; m < n; ++m)
                order_container[m] = m;

            std::sort(order_container.begin(), order_container.end(),
                      [&](size_t a, size_t b){ return container.items[a] < container.items[b]; });

            // Create side-cross pattern
            std::vector<size_t> sidecross;
            size_t left = 0, right = n - 1;
            bool take_left = true;
            while (left <= right) {
                if (take_left) {
                    sidecross.push_back(order_container[left++]);
                } else {
                    sidecross.push_back(order_container[right--]);
                }
                take_left = !take_left;
            }
            order_container = std::move(sidecross);
        }

        SideCrossOrder& operator++() {
            ++index;
            return *this;
        }

        SideCrossOrder operator++(int) {
            SideCrossOrder temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const SideCrossOrder& other) const {return index == other.index;}

        bool operator!=(const SideCrossOrder& other) const {return index != other.index;}

        const T& operator*() const {return container.items[order_container[index]];}

        static SideCrossOrder begin(const MyContainer& c) {return SideCrossOrder(c, 0);}

        static SideCrossOrder end(const MyContainer& c) {return SideCrossOrder(c, c.size());}
    };

    // Starting from the middle, then left, right, left, right...
    class MiddleOutOrder {
    private:
        const MyContainer& container;
        size_t index;
        std::vector<size_t> order_container;

    public:
        MiddleOutOrder(const MyContainer& c, size_t i = 0) : container(c), index(i) {
            size_t n = container.size();
            if (n == 0) return;
            order_container.reserve(n);
            size_t mid = n / 2; // round up to middle index if the number of elements is even

            order_container.push_back(mid);

            int left = (int)mid - 1;
            int right = (int)mid + 1;

            bool take_left = true;
            while (order_container.size() < n) {
                if (take_left && left >= 0) {
                    order_container.push_back(left--);
                }
                else if (!take_left && (size_t)right < n) {
                    order_container.push_back(right++);
                }
                take_left = !take_left;
            }
        }

        MiddleOutOrder& operator++() {
            ++index;
            return *this;
        }

        MiddleOutOrder& operator++(int) {
            MiddleOutOrder temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const MiddleOutOrder& other) const {return index == other.index;}

        bool operator!=(const MiddleOutOrder& other) const {return index != other.index;}

        const T& operator*() const {return container.items[order_container[index]];}

        static MiddleOutOrder begin(const MyContainer& c) {return MiddleOutOrder(c, 0);}

        static MiddleOutOrder end(const MyContainer& c) {return MiddleOutOrder(c, c.size());}
    };

    // Begin/end for iterating in original order
    Order regular_begin() const { return Order::begin(*this); }
    Order regular_end() const { return Order::end(*this); }

    // Begin/end for reverse iteration
    ReverseOrder reverse_begin() const { return ReverseOrder::begin(*this); }
    ReverseOrder reverse_end() const { return ReverseOrder::end(*this); }

    // Begin/end for ascending order iteration
    AscendingOrder ascending_begin() const { return AscendingOrder::begin(*this); }
    AscendingOrder ascending_end() const { return AscendingOrder::end(*this); }

    // Begin/end for descending order iteration
    DescendingOrder descending_begin() const { return DescendingOrder::begin(*this); }
    DescendingOrder descending_end() const { return DescendingOrder::end(*this); }

    // Begin/end for side-cross order (min, max, min+1, max-1, ...)
    SideCrossOrder sidecross_begin() const { return SideCrossOrder::begin(*this); }
    SideCrossOrder sidecross_end() const { return SideCrossOrder::end(*this); }

    // Begin/end for middle-out order (middle, left, right, ...)
    MiddleOutOrder middleout_begin() const { return MiddleOutOrder::begin(*this); }
    MiddleOutOrder middleout_end() const { return MiddleOutOrder::end(*this); }

};

}

#endif