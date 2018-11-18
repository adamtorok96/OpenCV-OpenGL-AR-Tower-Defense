#include "GameObject.h"

void GameObject::setPosition(Detector * detector, const Vec3d &rvec, const Vec3d &tvec) {
    this->rvec = rvec;
    this->tvec = tvec;
    this->modelViewMatrix = detector->getModelViewMatrix(rvec, tvec);
}