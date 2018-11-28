#include "GameObject.h"

GameObject & GameObject::setPosition(const Vec3d & tvec){
    this->tvec = tvec;
    this->modelViewMatrix = Detector::getInstance()->getModelViewMatrix(rvec, tvec);

    return *this;
}

GameObject & GameObject::setPosition(const Vec3d &rvec, const Vec3d &tvec) {
    this->rvec = rvec;
    this->tvec = tvec;
    this->modelViewMatrix = Detector::getInstance()->getModelViewMatrix(rvec, tvec);

    if( !initialized )
        initialized = true;

    return *this;
}

GameObject & GameObject::setPosition(GameObject * gameObject) {
    rvec = gameObject->rvec;
    tvec = gameObject->tvec;
    modelViewMatrix = gameObject->modelViewMatrix;

    if( !initialized )
        initialized = true;

    return *this;
}

GameObject &GameObject::move(const Vec3d & dir) {
    tvec += dir;

    return *this;
}

Vec3d GameObject::getPosition() const {
    return tvec;
}

double GameObject::getDistance(const GameObject &gameObject) const {
    Vec3d vec = getPosition() - gameObject.getPosition();

    return sqrt(
            vec[0] * vec[0] +
            vec[1] * vec[1] +
            vec[2] * vec[2]
    );
}

bool GameObject::isDestroyed() {
    return destroyed;
}

void GameObject::destroy() {
    destroyed = true;
}
