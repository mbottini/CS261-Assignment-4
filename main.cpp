#include <iostream>
#include "Item.h"
#include <set>

int main() {
    Item i("bob", "dave", 1);
    ItemPtr ip = new Item("foo", "bar", 25);
    std::cout << ip;
    return 0;
}
