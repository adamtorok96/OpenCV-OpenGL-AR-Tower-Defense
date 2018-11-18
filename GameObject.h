#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H

#include "Detector.h"

using namespace std;
using namespace cv;

class GameObject {

protected:
    Mat modelViewMatrix;
    Vec3d rvec, tvec;

public:
    void setPosition(Detector * detector, const Vec3d & rvec, const Vec3d & tvec);

    virtual void process() = 0;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
