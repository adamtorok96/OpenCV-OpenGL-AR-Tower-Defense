#include <iostream>
#include "StartPath.h"

void StartPath::process(unsigned int deltaTime) {
    if( !initialized )
        return;

    static unsigned int wait = 10;

    if( rand() % wait == 0 ) {
        std::cout << "rand" << endl;

        ArucoObjectMapper::getInstance()->spawnMinion(this);
        wait = 10000;
    }
}
