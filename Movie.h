#pragma once

#include "Item.h"

class Movie : public Item
{
public:
    Movie(const std::string& title, const std::string& director, int nScenes);
    ~Movie();

    void print(std::ostream& os) const;
    const std::string& getDirector() const;
    int getScenes() const;
    const stringSet& getActors() const;
    void addActor(const std::string& actor);
};

