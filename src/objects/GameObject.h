#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H

#include <cmath>

#include "../Detector.h"

using namespace std;
using namespace cv;

class GameObject {

protected:
    Mat modelViewMatrix;
    Vec3d rvec, tvec;

    bool initialized;

public:
    GameObject() : initialized{false} {};

    void setPosition(const Vec3d & tvec);
    void setPosition(const Vec3d & rvec, const Vec3d & tvec);
    void setPosition(GameObject * gameObject);

    Vec3d getPosition() const;

    double getDistance(const GameObject & gameObject) const;

    virtual void process(unsigned int deltaTime) = 0;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
