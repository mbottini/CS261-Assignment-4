#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"

// Typedef: std::set<std::string> = stringSet.


// Standard constructor.
Item::Item(const string& title, const string& artist, int quantity)
{
	_title = title;
    _originator = artist;
    _quantity = quantity;
    return;
}

// Default constructor. Should never happen, but you never know.
Item::Item()
{
	_title = "";
    _originator = "";
    _quantity = 0;
    return;
}

Item::~Item()
{	
    return; // None needed, as there isn't any pointer nonsense going on.
}

const std::string& Item::getTitle() const {
    return _title;
}

const stringSet& Item::getKeywords() const {
    return _keywords;
}

void Item::addKeyword(const std::string& keyword) {
    _keywords.insert(keyword);
    return;
}

// Should never print. This is a way to make sure that ItemPtrs are properly
// dereferencing.
void Item::print(std::ostream& os) const {
    os << "-Item-\n"
       << "origin:    " << _originator << "\n"
       << "quant:     " << _quantity << "\n"
       << "collab:    " << setToString(_collaborators) << "\n"
       << "title:     " << _title << "\n"
       << "keywords:  " << setToString(_keywords) << "\n";
    return;
}

const std::string& Item::getOriginator() const {
    return _originator;
}

int Item::getQuantity() const {
    return _quantity;
}

const stringSet& Item::getCollaborators() const {
    return _collaborators;
}

void Item::addCollaborator(const std::string& collaborator) {
    _collaborators.insert(collaborator);
}

// Takes stringSet and turns it into a comma-delimited string.
std::string Item::setToString(const stringSet& s) const {
    std::string returnString = "";
    for(auto i = s.begin(); i != s.end(); ++i) {
        returnString += *i;
        if(std::next(i) != s.end()) {
            returnString += ", ";
        }
    }

    return returnString;
}

// Default constructor.
ItemPtr::ItemPtr() {
    _ptr = NULL;
    _referenceCount = NULL;
    return;
}

// Constructor with pointer to Item.
// referenceCount becomes 1 because one ItemPtr is referring to it.
ItemPtr::ItemPtr(Item *ptr) {
    _ptr = ptr;
    _referenceCount = new int(1);
    return;
}

// Copy constructor. _ptr and _referenceCount are set to NULL to take advantage
// of the fact that delete doesn't do anything with null pointers. We can then
// use the assignment operator to avoid code duplication.
ItemPtr::ItemPtr(const ItemPtr& other) {
    _ptr = NULL;
    _referenceCount = NULL;
    *this = other;
    return;
}

// Reset to make sure that the current pointer (if any) in *this is properly
// treated.
// After that, we copy the pointers over and then increment the referenceCount.
// Note that these pointers are *shared*, which means that when I increment the
// referenceCount in one, it happens to the other as well.
ItemPtr& ItemPtr::operator =(const ItemPtr& other) {
    reset();
    _ptr = other.getPtr();
    _referenceCount = other.getReferenceCount();
    incrementReferenceCount();
    return *this;
}

// Move constructor, which sadly can't be duplicated with the above two.
ItemPtr::ItemPtr(ItemPtr&& other) {
    _ptr = NULL;
    _referenceCount = NULL;
    _ptr = other.getPtr();
    _referenceCount = other.getReferenceCount();
    incrementReferenceCount();
    other.reset();
    return;
}

// ItemPtr& ItemPtr::operator =(ItemPtr&& other)
// Move assignment operator doesn't seem to be needed for the STL container
// libraries.

void ItemPtr::incrementReferenceCount() {
    *(_referenceCount) += 1;
    return;
}

// The core of the shared pointer. When we reset an ItemPtr, we relinquish its
// hold on the *Item. We decrease the referenceCount by 1, and then set the
// pointer and referenceCount equal to NULL. If this ItemPtr is the very last
// instance to have control of the *Item, _referenceCount will be equal to 0,
// and we can definitively say that the pointer (and referenceCount) can be
// deleted.
void ItemPtr::reset() {
    if(_referenceCount) {
        *(_referenceCount) -= 1;
        if(*(_referenceCount) == 0) {
            delete _ptr;
            delete _referenceCount;
        }
        _ptr = NULL;
        _referenceCount = NULL;
    }
    return;
}

// The destructor just calls reset() for the above reason.
ItemPtr::~ItemPtr() {
    reset();
    return;
}

bool operator<(const Item& i1, const Item& i2)
{
    return i1.getTitle() < i2.getTitle();
}

bool operator<(const ItemPtr& ip1, const ItemPtr& ip2)
{
    return ip1.getPtr()->getTitle() < ip2.getPtr()->getTitle();    
}

// We call print(out) because virtual operator overloading is frustrating when
// dealing with the dereferencing. It's easier just to make another function.
ostream& operator<<(ostream& out, const ItemPtr& ip)
{
    ip.getPtr()->print(out);
    return out;
}

ostream& operator<<(ostream& out, const Item* ip) {
    if(ip) {
        ip->print(out);
    }

    else {
        out << "Null pointer reference.\n";
    }

    return out;
}
