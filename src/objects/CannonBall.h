#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_CANNONBALL_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_CANNONBALL_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "GameModel.h"
#include "Minion.h"

class CannonBall : public GameModel {
    static constexpr double speed = 0.00003;

    static GLuint ballModelId;
    static GLuint createOrGetModelId();

    Vec3d direction;

    long life;
public:
    explicit CannonBall(const Vec3d & direction) : GameModel(createOrGetModelId()), direction{direction}, life{rand() % 100000 + 1000} {};

    void process(unsigned int deltaTime) override;
};

#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_CANNONBALL_H