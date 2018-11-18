#include "GameObject.h"

void GameObject::setPosition(const Detector * detector, const Vec3d &rvec, const Vec3d &tvec) {
    this->rvec = rvec;
    this->tvec = tvec;
    this->modelViewMatrix = detector->getModelViewMatrix(rvec, tvec);
}

double GameObject::getDistance(const GameObject &gameObject) {
    return sqrt(
            (tvec[0] - gameObject.tvec[0]) * (tvec[0] - gameObject.tvec[0]) +
            (tvec[1] - gameObject.tvec[1]) * (tvec[1] - gameObject.tvec[1]) +
            (tvec[2] - gameObject.tvec[2]) * (tvec[2] - gameObject.tvec[2])
    );
}