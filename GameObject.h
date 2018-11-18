#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H

#include <cmath>

#include "Detector.h"

using namespace std;
using namespace cv;

class GameObject {

protected:
    Mat modelViewMatrix;
    Vec3d rvec, tvec;

public:
    void setPosition(const Detector * detector, const Vec3d & rvec, const Vec3d & tvec);
    double getDistance(const GameObject & gameObject);

    virtual void process() = 0;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
