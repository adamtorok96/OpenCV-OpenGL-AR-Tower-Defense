#include "Tower.h"
#include "../ArucoObjectMapper.h"

void Tower::process(unsigned int deltaTime) {
    if( !initialized )
        return;

    if( rand() % 50 == 0 ) {
        ArucoObjectMapper::getInstance()->spawnCannonBall(this);
    }
}
