#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_CANNONBALL_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_CANNONBALL_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "GameModel.h"
#include "Minion.h"

class CannonBall : public GameModel {
    static constexpr double speed = 0.00005;

    static GLuint createModel();

    Vec3d direction;

    long life, damage;
public:
    explicit CannonBall(const Vec3d & direction) : GameModel(createModel()),
        direction{direction},
        life{rand() % 100000 + 1000},
        damage{rand() % 100 + 10} {};

    void process(unsigned int deltaTime) override;
};

#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_CANNONBALL_H