#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"


Item::Item(const string& title, const string& artist, int quantity)
{
	_title = title;
    _originator = artist;
    _quantity = quantity;
    return;
}

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

std::string Item::setToString(const stringSet& s) const {
    std::string returnString = "";
    for(auto i = s.begin(); i != s.end(); ++i) {
        returnString += *i;
    }

    return returnString;
}


ItemPtr::ItemPtr() {
    _ptr = NULL;
    _referenceCount = NULL;
    return;
}

ItemPtr::ItemPtr(Item *ptr) {
    _ptr = ptr;
    _referenceCount = new int(1);
    return;
}

ItemPtr::ItemPtr(const ItemPtr& other) {
    _ptr = NULL;
    _referenceCount = NULL;
    *this = other;
    return;
}

ItemPtr& ItemPtr::operator =(const ItemPtr& other) {
    reset();
    _ptr = other.getPtr();
    _referenceCount = other.getReferenceCount();
    incrementReferenceCount();
    return *this;
}

ItemPtr::ItemPtr(ItemPtr&& other) {
    _ptr = NULL;
    _referenceCount = NULL;
    _ptr = other.getPtr();
    _referenceCount = other.getReferenceCount();
    incrementReferenceCount();
    other.reset();
    return;
}

void ItemPtr::incrementReferenceCount() {
    *(_referenceCount) += 1;
    return;
}

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

ostream& operator<<(ostream& out, const Item& i)
{
	i.print(out);
	return out;
}

ostream& operator<<(ostream& out, const ItemPtr& ip)
{
    ip.getPtr()->print(out);
    return out;
}


