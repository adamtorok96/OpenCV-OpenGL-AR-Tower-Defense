#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H

#include "GameModel.h"

class Minion : public GameModel {
public:
    explicit Minion(GLuint id) : GameModel{id} {}

    void process(unsigned int deltaTime) override;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_MINION_H
