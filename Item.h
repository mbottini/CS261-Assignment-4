#pragma once

#include <ostream>
#include <set>
#include <string>

using namespace std;

typedef std::set<std::string> stringSet;

class Item
{
    private:
        std::string _title;
        std::string _originator;
        int _quantity;
        stringSet _collaborators;
        stringSet _keywords;


    public:
        Item(const string& title, const string& artist, int quantity);
        Item();
        virtual ~Item();

        // Public getters and setter, accessible by subclasses.
        const std::string& getTitle() const;
        const stringSet& getKeywords() const;

        void addKeyword(const std::string& keyword);
        void addCollaborator(const std::string& collaborator);

        // We can't overload the << operator for dereferencing, so instead we
        // just create a method for printing it this way.
        virtual void print(std::ostream& os) const;

    protected:
        // Protected getters and setter, only accessible through subclass
        // wrappers.

        const std::string& getOriginator() const;
        int getQuantity() const;
        const stringSet& getCollaborators() const;

        std::string setToString(const stringSet& s) const;

};

// You can't store Item* in an ItemSet, because that would disable the automatic
// sorting that set does. Containers in the C++ STL are designed to store
// INSTANCES, not POINTERS to instances.
//
// Instead we store instances of ItemPtr in the ItemSet defined in Library.h.
// Each instance of ItemPtr contains a pointer to an instance of Item. In this way,
// the container can call operator< for ItemPtr (which can then call operator<
// for Item) to determine the order in which to store the items it's given.
//
// When you add a Book instance to an ItemSet, you can do things like this:
//
//		ItemSet		books;					// defined in Library.h
//		Item		*book = new Book(...);
//
//		books.insert(book);
//
// The STL's set class will internally generate an instance of ItemPtr
// which will contain the pointer to the instance of Book.

class ItemPtr
{
private:
	Item	*_ptr;
    int *_referenceCount;

    /* Shared pointer. It keeps track of how many containers use it; inserting
     * it into a container will increase referenceCount by one. Triggering the
     * destructor will decrease referenceCount by one. Once referenceCount is
     * equal to 0, the destructor will free the Item pointer and the
     * referenceCount pointer.
     */

public:
    // Rule of 5: ctor, move, copy, assignment operator, dtor.
    ItemPtr();
	ItemPtr(Item *ptr);
    ItemPtr(ItemPtr&& other);
    ItemPtr(const ItemPtr& other);
    ItemPtr& operator =(const ItemPtr& other);
    ~ItemPtr();

    Item* getPtr() const { return _ptr; };

    int* getReferenceCount() const { return _referenceCount; }

    void incrementReferenceCount();
    void reset();


};

// compare two instances of Item
bool operator<(const Item& i1, const Item& i2);

// compare two instances of ItemPtr
bool operator<(const ItemPtr& ip1, const ItemPtr& ip2);

ostream& operator<<(ostream& out, const Item& i);
ostream& operator<<(ostream& out, const ItemPtr& ip);
ostream& operator<<(ostream& out, const Item* ip);


