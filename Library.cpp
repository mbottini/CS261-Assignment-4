#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include <cstdarg>					// support macros for vararg
#include <iostream>
#include "Library.h"

// general functions

void Library::addKeywordsForItem(const Item* const item, int nKeywords, ...)
{
	// the code in this function demonstrates how to handle a vararg in C++

	va_list		keywords;
	char		*keyword;

	va_start(keywords, nKeywords);
	for (int i = 0; i < nKeywords; i++) {
		keyword = va_arg(keywords, char*);
		// do something with each keyword
		}
	va_end(keywords);
}

const ItemSet* Library::itemsForKeyword(const string& keyword) const
{
	// your code here
	return NULL;
}

// book-related functions

const Item* Library::addBook(const string& title, const string& author, const int nPages)
{
	// your code here
	return NULL;
}

const ItemSet* Library::booksByAuthor(const string& author) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::books() const
{
	// your code here
	return NULL;
}

// music-related functions

const Item* Library::addMusicAlbum(const string& title, const string& band, const int nSongs)
{
	// your code here
	return NULL;
}

void Library::addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...)
{
	// your code here
}

const ItemSet* Library::musicByBand(const string& band) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::musicByMusician(const string& musician) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::musicAlbums() const
{
	// your code here
	return NULL;
}

// movie-related functions

const Item* Library::addMovie(const string& title, const string& director, const int nScenes)
{
	// your code here
	return NULL;
}

void Library::addCastMembers(const Item* const movie, const int nCastMembers, ...)
{
	// your code here
}

const ItemSet* Library::moviesByDirector(const string& director) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::moviesByActor(const string& actor) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::movies() const
{
	// your code here
	return NULL;
}

static void deleteMapContents(StringToItemSetMap& s2ism)
{
	// your code here
}

static void deleteItemSetContents(ItemSet& itemSet)
{
	// your code here
}

Library::~Library()
{
	// your code here
}
