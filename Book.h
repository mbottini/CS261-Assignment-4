#pragma once

#include "Item.h"

class Book : public Item
{
    public:
        Book(std::string title, std::string author, int nPages);
	    ~Book();

        const std::string& getAuthor() const;
        int getPages() const;
        void print(std::ostream& out) const;
        
};

