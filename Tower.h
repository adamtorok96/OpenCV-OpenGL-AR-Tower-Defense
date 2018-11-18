#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_TOWER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_TOWER_H


#include "GameModel.h"

class Tower : public GameModel {
public:
    explicit Tower(GLuint model) : GameModel(model) {}

    void process() override;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_TOWER_H
