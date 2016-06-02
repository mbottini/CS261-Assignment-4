#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "MusicAlbum.h"

MusicAlbum::MusicAlbum(const std::string& title, const std::string& band,
    int nSongs) : Item(title, band, nSongs) {
    return;
}

MusicAlbum::~MusicAlbum()
{
    return;
}

const std::string& MusicAlbum::getBand() const {
    return getOriginator();
}

int MusicAlbum::getSongs() const {
    return getQuantity();
}

const stringSet& MusicAlbum::getBandMembers() const {
    return getCollaborators();
}

void MusicAlbum::addBandMember(const std::string& member) {
    addCollaborator(member);
    return;
}

void MusicAlbum::print(std::ostream& os) const {
    os << "-Music Album-\n"
       << "origin:    " << getBand() << "\n"
       << "# songs:   " << getSongs() << "\n"
       << "members:   " << setToString(getBandMembers()) << "\n"
       << "title:     " << getTitle() << "\n"
       << "keywords:  " << setToString(getKeywords()) << "\n";
    return;
}
