#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H

#include <iostream>

#include <opencv2/core.hpp>

#include <GL/gl.h>

#include <tiny_obj_loader.h>

#include "Detector.h"

using namespace std;
using namespace cv;

class GameObject {
    GLuint modelId;

    Mat modelViewMatrix;
    Vec3d rvec, tvec;

public:
    static GLuint load(const string & filename, Vec3d translate, Vec3d rotate, Vec3d scale);

    GameObject(GLuint modelId);
    ~GameObject();

    void setPosition(Detector * detector, const Vec3d & rvec, const Vec3d & tvec);
    void draw();
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
