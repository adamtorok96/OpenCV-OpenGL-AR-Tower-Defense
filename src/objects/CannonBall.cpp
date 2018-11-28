#include "CannonBall.h"
#include "../ArucoObjectMapper.h"

GLuint CannonBall::createModel() {
    GLuint ballModelId = glGenLists(1);

    glNewList(ballModelId, GL_COMPILE);

    glDisable(GL_TEXTURE_2D);

    glColor3f(0.0f, 0.0f, 1.0f);

    glutSolidSphere(0.005, 20, 20);

    glEndList();

    return ballModelId;
}

void CannonBall::process(unsigned int deltaTime) {
    if( destroyed )
        return;

    life -= deltaTime;

    ArucoObjectMapper * arucoObjectMapper = ArucoObjectMapper::getInstance();

    if( life < 0 ) {
        arucoObjectMapper->destroyCannonBall(this);

        return;
    }

    setPosition(getPosition() + direction * (speed * deltaTime));

    Minion * minion = arucoObjectMapper->getClosestMinion(this);

//    if( minion != nullptr )
//        std::cout << "dist from m: " << minion->getDistance(*this) << std::endl;

    if( minion != nullptr && minion->getDistance(*this) <=  0.005f ) {
        minion->hit(damage);
    }
}