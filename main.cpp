// noashalom5@gmail.com
#include "myContainer.hpp"
#include <iostream>

using namespace std;
using namespace mycontainer_ass4;

int main() {
    MyContainer<int> container;

    container.add(7);
    container.add(2);
    container.add(5);
    container.add(9);
    container.add(3);
    container.add(14);
    container.add(3);
    container.add(1);

    cout << "\nOriginal container: " << container << endl;

    cout << "\nRegular Order: ";
    for (auto it = container.regular_begin(); it != container.regular_end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\nReverse Order: ";
    for (auto it = container.reverse_begin(); it != container.reverse_end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\nAscending Order: ";
    for (auto it = container.ascending_begin(); it != container.ascending_end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\nDescending Order: ";
    for (auto it = container.descending_begin(); it != container.descending_end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\nSide-Cross Order: ";
    for (auto it = container.sidecross_begin(); it != container.sidecross_end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\nMiddle-Out Order: ";
    for (auto it = container.middleout_begin(); it != container.middleout_end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}