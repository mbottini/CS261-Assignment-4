#include <iostream>
#include "Item.h"
#include "Book.h"
#include "MusicAlbum.h"
#include "Movie.h"
#include <string>
#include <vector>

int main() {
    std::vector<ItemPtr> ipVector1;
    std::vector<ItemPtr> ipVector2;

    ipVector1.emplace_back(new Book("spam", "eggs", 251));
    ipVector2.emplace_back(new MusicAlbum("foo", "bar", 12));

    for(auto i = ipVector1.begin(); i != ipVector1.end(); ++i) {
        std::cout << *i;
    }

    for(auto i = ipVector2.begin(); i != ipVector2.end(); ++i) {
        std::cout << *i;
    }
    

    return 0;
}
