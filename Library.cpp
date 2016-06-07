#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include <cstdarg>					// support macros for vararg
#include "Library.h"

// general functions

void Library::addKeywordsForItem(const Item* const item, int nKeywords, ...)
{
	va_list		keywords;
	char		*keyword;

    ItemPtr foundItem = titleMap[item->getTitle()];

	va_start(keywords, nKeywords);
	for (int i = 0; i < nKeywords; i++) {
		keyword = va_arg(keywords, char*);
		foundItem->addKeyword(keyword);
        mapAdd(keywordMap, keyword, foundItem);
	}
	va_end(keywords);
}

const ItemSet* Library::itemsForKeyword(const string& keyword) const
{
	return getItemSet(keywordMap, keyword);
}

// book-related functions

const Item* Library::addBook(const string& title, const string& author, const int nPages)
{
    if(mapContains(titleMap, title)) {
        return NULL;
    }
    
    ItemPtr newItemPtr = new Book(title, author, nPages);

    // The below adds the ItemPtr to BookSet, bookAuthorMap, and titleMap. This
    // is the primary repetition in my code - every addItem method has some
    // repetition along these lines. I could have created a function that tried
    // to automate this away, but it would have required me to make
    // getOriginator a public method.

    bookSet.insert(newItemPtr);
    mapAdd(bookAuthorMap, author, newItemPtr);
    titleMap.emplace(title, newItemPtr);

    return newItemPtr.getPtr();
}

const ItemSet* Library::booksByAuthor(const string& author) const
{
	return getItemSet(bookAuthorMap, author);
}

const ItemSet* Library::books() const
{
	return &bookSet;
}

// music-related functions

const Item* Library::addMusicAlbum(const string& title, const string& band, const int nSongs)
{
    if(mapContains(titleMap, title)) {
        return NULL;
    }

    ItemPtr newItemPtr = new MusicAlbum(title, band, nSongs);
    
    albumSet.insert(newItemPtr);
    mapAdd(albumBandMap, band, newItemPtr);
    titleMap.emplace(title, newItemPtr);

    return newItemPtr.getPtr();
}

void Library::addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...)
{
	va_list		members;
	char		*member;

    ItemPtr foundItem = titleMap[musicAlbum->getTitle()];

	va_start(members, nBandMembers);
	for (int i = 0; i < nBandMembers; i++) {
		member = va_arg(members, char*);
		foundItem->addCollaborator(member);
        mapAdd(albumMusicianMap, member, foundItem);
	}
	va_end(members);
}

const ItemSet* Library::musicByBand(const string& band) const
{
    return getItemSet(albumBandMap, band);
}

const ItemSet* Library::musicByMusician(const string& musician) const
{
	return getItemSet(albumMusicianMap, musician);
}

const ItemSet* Library::musicAlbums() const
{
	return &albumSet;
}

// movie-related functions

const Item* Library::addMovie(const string& title, const string& director, const int nScenes)
{
    if(mapContains(titleMap, title)) {
        return NULL;
    }

    ItemPtr newItemPtr = new Movie(title, director, nScenes);
    
    movieSet.insert(newItemPtr);
    mapAdd(movieDirectorMap, director, newItemPtr);
    titleMap.emplace(title, newItemPtr);

    return newItemPtr.getPtr();
}

void Library::addCastMembers(const Item* const movie, const int nCastMembers, ...)
{
	va_list		actors;
	char		*actor;

    ItemPtr foundItem = titleMap[movie->getTitle()];

	va_start(actors, nCastMembers);
	for (int i = 0; i < nCastMembers; i++) {
		actor = va_arg(actors, char*);
		foundItem->addCollaborator(actor);
        mapAdd(movieActorMap, actor, foundItem);
	}
	va_end(actors);

}

const ItemSet* Library::moviesByDirector(const string& director) const
{
    return getItemSet(movieDirectorMap, director);
}

const ItemSet* Library::moviesByActor(const string& actor) const
{
    return getItemSet(movieActorMap, actor);
}

const ItemSet* Library::movies() const
{
    return &movieSet;
}

static void deleteMapContents(StringToItemSetMap& s2ism)
{
    // Because each SetMap is a dynamically allocated pointer, we have to delete
    // them.
    for(auto i = s2ism.begin(); i != s2ism.end(); ++i) {
        delete i->second; // i is a pointer to key-value pairs of the map.
    }

    return;
}

static void deleteItemSetContents(ItemSet& itemSet)
{
    return; // None needed thanks to ItemPtr destructor.
}

Library::~Library()
{
    deleteMapContents(bookAuthorMap);
    deleteMapContents(albumBandMap);
    deleteMapContents(albumMusicianMap);
    deleteMapContents(movieDirectorMap);
    deleteMapContents(movieActorMap);
    deleteMapContents(keywordMap);
    return;
}

void Library::mapAdd(StringToItemSetMap& mp, const std::string& word, 
                const ItemPtr& itemPtr) {
    if(!(mapContains(mp, word))) {
        mp.emplace(word, new ItemSet);
    }

    mp[word]->insert(itemPtr);
    return;
}

bool mapContains(const ItemPtrMap& mp, const std::string& query) {
    auto it = mp.find(query);
    return it != mp.end();
}

bool mapContains(const StringToItemSetMap& mp, const std::string& query) {
    auto it = mp.find(query);
    return it != mp.end();
}

const ItemSet* getItemSet(const StringToItemSetMap& mp, const string& query) {
    if(mapContains(mp, query)) {
        return mp.at(query);
    }

    else {
        return NULL;
    }
}
