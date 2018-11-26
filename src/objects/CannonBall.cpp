#include "CannonBall.h"
#include "../ArucoObjectMapper.h"

GLuint CannonBall::ballModelId = 0;

GLuint CannonBall::createOrGetModelId() {
    if( ballModelId != 0 )
        return ballModelId;

    ballModelId = glGenLists(1);

    glNewList(ballModelId, GL_COMPILE);

    glDisable(GL_TEXTURE_2D);

    glColor3f(0.0f, 0.0f, 1.0f);

    glutSolidSphere(0.01, 20, 20);

    glEndList();

    return ballModelId;
}

void CannonBall::process(unsigned int deltaTime) {
    life -= deltaTime;

    if( life < 0 ) {
        // explode or something..
        return;
    }

    setPosition(getPosition() + direction * (speed * deltaTime));
}