#include "Minion.h"

void Minion::process(unsigned int deltaTime) {
    if( nextPath != nullptr ) {
//        std::cout << "distance: " << getDistance(*nextPath) << endl;

        Vec3d dir = normalize(nextPath->getPosition() - getPosition());

        setPosition(getPosition() + dir * (speed * deltaTime));

        if( getDistance(*nextPath) <= 0.0005f ) {
            std::cout << "Next: " << nextPath->getNext() << endl;
            nextPath = nextPath->getNext();
        }
    }
}

void Minion::setNextPath(Path *path) {
    nextPath = path;
}