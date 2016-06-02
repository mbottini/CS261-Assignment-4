#include <iostream>
#include "Item.h"
#include "Book.h"
#include <set>

int main() {
    ItemPtr ip = new Book("foo", "bar", 25);
    std::cout << ip;
    return 0;
}
