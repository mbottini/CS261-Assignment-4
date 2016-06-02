#include <iostream>
#include "Item.h"
#include "Book.h"
#include "MusicAlbum.h"
#include <vector>

int main() {
    std::vector<ItemPtr> ipVec;

    Item *i1 = new Book("foo", "bar", 125);
    Item *i2 = new MusicAlbum("spam", "eggs", 12);

    ipVec.emplace_back(i1);
    ipVec.emplace_back(i2); 

    ipVec[0].getPtr()->print(std::cout);

    return 0;
}
