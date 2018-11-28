#include "Minion.h"
#include "../ArucoObjectMapper.h"

void Minion::process(unsigned int deltaTime) {
    if( destroyed )
        return;

    if( nextPath != nullptr ) {
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

void Minion::hit(long damage) {
    life -= damage;

    std::cout << "damaged: " << life << " " << damage << std::endl;

    if( life < 0 ) {
        std::cout << "life: " << life << std::endl;
        ArucoObjectMapper::getInstance()->destroyMinion(this);
    }
}
