#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H

#include "GameModel.h"
#include "Path.h"

class Minion : public GameModel {
    static constexpr GLdouble speed = 0.00002;

    Path * nextPath;

public:
    explicit Minion(GLuint id) : GameModel{id}, nextPath{nullptr} {}

    void process(unsigned int deltaTime) override;

    void setNextPath(Path * path);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H
