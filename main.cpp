#include <iostream>
#include "Item.h"
#include "Book.h"
#include "MusicAlbum.h"
#include "Movie.h"
#include <vector>
#include <string>

int main() {
    std::vector<ItemPtr> ipVec;

    Item *i1 = new Book("foo", "bar", 125);
    Item *i2 = new MusicAlbum("spam", "eggs", 12);
    Item *i3 = new Movie("march", "penguins", 5);

    ipVec.emplace_back(i1);
    ipVec.emplace_back(i2);
    ipVec.emplace_back(i3);

    for(auto i = ipVec.begin(); i != ipVec.end(); ++i) {
        std::cout << *i;
    }

    return 0;
}
