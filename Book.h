#pragma once

#include "Item.h"

class Book : public Item
{
    public:
        Book(const std::string& title, const std::string& author, int nPages);
	    ~Book();

        const std::string& getAuthor() const;
        int getPages() const;
        void print(std::ostream& out) const;
        
};

