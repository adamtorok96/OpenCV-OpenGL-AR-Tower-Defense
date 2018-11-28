#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H

#include "GameModel.h"
#include "Path.h"

class Minion : public GameModel {
    static constexpr GLdouble speed = 0.00002;

    Path * nextPath;

    long life;
public:
    explicit Minion(GLuint id) : GameModel{id}, nextPath{nullptr}, life{50 + rand() % 50} {}

    void process(unsigned int deltaTime) override;

    void setNextPath(Path * path);

    void hit(long damage);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H
