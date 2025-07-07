// noashalom5@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "myContainer.hpp"
#include "doctest.hpp"
#include <sstream>
#include <string>

using namespace std;
using namespace doctest;
using namespace mycontainer_ass4;

TEST_CASE("Add and size functions") {
    MyContainer<int> intContainer;
    CHECK(intContainer.size() == 0);
    intContainer.add(3);
    intContainer.add(8);
    intContainer.add(2);
    CHECK(intContainer.size() == 3);    
}

TEST_CASE("Remove function") {
    MyContainer<int> intContainer;
    intContainer.add(1);
    intContainer.add(2);
    intContainer.add(3);
    intContainer.add(2);
    CHECK(intContainer.size() == 4);
    intContainer.remove(2);
    CHECK(intContainer.size() == 2);
    intContainer.remove(5); // not in container
    CHECK(intContainer.size() == 2); // stay the same size
}

TEST_CASE("Print container") {
    MyContainer<string> stringContainer;
    stringContainer.add("How");
    stringContainer.add("you");
    stringContainer.add("doing");
    stringstream printing;
    printing << stringContainer;
    CHECK(printing.str() == "[ How you doing ]");
}

TEST_CASE("Regular iteration") {
    MyContainer<double> orderContainer;
    orderContainer.add(7.2);
    orderContainer.add(4.9);
    orderContainer.add(1.8);

    vector<double> result;
    for (auto it = orderContainer.regular_begin(); it != orderContainer.regular_end(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == vector<double>({7.2, 4.9, 1.8}));
}

TEST_CASE("Reverse iteration") {
    MyContainer<char> reverseContainer;
    reverseContainer.add('E');
    reverseContainer.add('S');
    reverseContainer.add('R');
    reverseContainer.add('E');
    reverseContainer.add('V');
    reverseContainer.add('E');
    reverseContainer.add('R');

    vector<char> result;
    for (auto it = reverseContainer.reverse_begin(); it != reverseContainer.reverse_end(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == vector<char>({'R', 'E', 'V', 'E', 'R', 'S', 'E'}));
}

TEST_CASE("Ascending order") {
    MyContainer<int> ascendingContainer;
    ascendingContainer.add(7);
    ascendingContainer.add(2);
    ascendingContainer.add(5);
    ascendingContainer.add(13);
    ascendingContainer.add(4);

    vector<int> result;
    for (auto it = ascendingContainer.ascending_begin(); it != ascendingContainer.ascending_end(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == vector<int>({2, 4, 5, 7, 13}));
}

TEST_CASE("Descending order") {
    MyContainer<char> descendingContainer;
    descendingContainer.add('a');
    descendingContainer.add('f');
    descendingContainer.add('x');
    descendingContainer.add('m');

    vector<char> result;
    for (auto it = descendingContainer.descending_begin(); it != descendingContainer.descending_end(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == vector<char>({'x', 'm', 'f', 'a'}));
}

TEST_CASE("SideCross order") {
    MyContainer<double> sideCrossContainer;
    sideCrossContainer.add(1.2);
    sideCrossContainer.add(5.8);
    sideCrossContainer.add(5.4);
    sideCrossContainer.add(3.7);
    sideCrossContainer.add(2.9);
    sideCrossContainer.add(4.1);
    sideCrossContainer.add(8.5);

    vector<double> result;
    for (auto it = sideCrossContainer.sidecross_begin(); it != sideCrossContainer.sidecross_end(); ++it) {
        result.push_back(*it);
    }
    // Sorted: 1.2 2.9 3.7 4.1 5.4 5.8 8.5 → sideCross: 1.2 8.5 2.9 5.8 3.7 5.4 4.1
    CHECK(result == vector<double>({1.2, 8.5, 2.9, 5.8, 3.7, 5.4, 4.1}));
}

TEST_CASE("MiddleOut order") {
    MyContainer<int> middleContainer;
    middleContainer.add(10);
    middleContainer.add(20);
    middleContainer.add(30);
    middleContainer.add(40);
    middleContainer.add(50);

    vector<int> result;
    for (auto it = middleContainer.middleout_begin(); it != middleContainer.middleout_end(); ++it) {
        result.push_back(*it);
    }
    // Order: 10 20 30 40 50 → middle is 30 → 30, 20, 40, 10, 50
    CHECK(result == vector<int>({30, 20, 40, 10, 50}));
}