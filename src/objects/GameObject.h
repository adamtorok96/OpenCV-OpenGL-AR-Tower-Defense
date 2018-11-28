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

    bool initialized, destroyed;

public:
    GameObject() : initialized{false}, destroyed{false} {};
//    virtual ~GameObject();

    GameObject & setPosition(const Vec3d & tvec);
    GameObject & setPosition(const Vec3d & rvec, const Vec3d & tvec);
    GameObject & setPosition(GameObject * gameObject);

    GameObject & move(const Vec3d & dir);

    Vec3d getPosition() const;

    double getDistance(const GameObject & gameObject) const;

    void destroy();
    bool isDestroyed();

    virtual void process(unsigned int deltaTime) = 0;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECT_H
