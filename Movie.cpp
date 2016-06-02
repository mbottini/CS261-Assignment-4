#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Movie.h"

Movie::Movie(const std::string& title, const std::string& director, int nScenes)
        : Item(title, director, nScenes) {
    return;
}

Movie::~Movie(void)
{
    return;
}

void Movie::print(std::ostream& os) const {
    os << "-Movie-\n"
       << "director   " << getDirector() << "\n"
       << "# scenes:  " << getScenes() << "\n"
       << "cast:      " << setToString(getActors()) << "\n"
       << "title:     " << getTitle() << "\n"
       << "keywords:  " << setToString(getKeywords()) << "\n";
    return;
}

const std::string& Movie::getDirector() const {
    return getOriginator();
}

int Movie::getScenes() const {
    return getQuantity();
}

const stringSet& Movie::getActors() const {
    return getCollaborators();
}

void Movie::addActor(const std::string& actor) {
    addCollaborator(actor);
    return;
}
