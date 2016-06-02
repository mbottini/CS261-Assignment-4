#pragma once

#include "Item.h"

class MusicAlbum : public Item
{
public:
    MusicAlbum(const std::string& title, const std::string& band, int nSongs);
	~MusicAlbum();

    const std::string& getBand() const;
    int getSongs() const;
    const stringSet& getBandMembers() const;

    void addBandMember(const std::string& member);

    void print(std::ostream& os) const;
};

