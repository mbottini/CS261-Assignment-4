#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"

Item::Item(const string& title, const string& artist)
{
	// your code here
}

Item::Item()
{
	// your code here
}

Item::~Item()
{
	// your code here
}

bool operator<(const Item& i1, const Item& i2)
{
	// your code here
	return false;
}

bool operator<(const ItemPtr& ip1, const ItemPtr& ip2)
{
	// your code here
	return false;
}

ostream& operator<<(ostream& out, const Item* const item)
{
	// your code here
	return out;
}
