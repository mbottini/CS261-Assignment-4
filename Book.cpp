#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Book.h"

Book::Book(std::string title, std::string author, int nPages) :
    Item(title, author, nPages) {
    return;
}


Book::~Book() {
    return;
}

const std::string& Book::getAuthor() const {
    return getOriginator();
}

int Book::getPages() const {
    return getQuantity();
}

void Book::print(std::ostream& os) const {
    os << "-Book-\n"
       << "author:    " << getAuthor() << "\n"
       << "# pages:   " << getPages() << "\n"
       << "title:     " << getTitle() << "\n"
       << "keywords:  " << setToString(getKeywords()) << "\n";
    return;
}

