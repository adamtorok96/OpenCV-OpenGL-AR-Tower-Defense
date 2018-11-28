#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEMODEL_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEMODEL_H

#include <iostream>

#include <opencv2/core.hpp>

#include <GL/gl.h>

#include <tiny_obj_loader.h>

#include "GameObject.h"


class GameModel : public GameObject {
    GLuint modelId;

public:
    static GLuint load(const string & filename, Vec3d translate, Vec3d rotate, Vec3d scale, Vec3d * color);

    explicit GameModel(GLuint modelId);
//    ~GameModel();

    virtual void draw();
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEMODEL_H
