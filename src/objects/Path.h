#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_PATH_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_PATH_H

#include "GameObject.h"

class Path : public GameObject {
    Path * next;

public:
    Path() : next{nullptr} {};

    void setNext(Path * next);
    Path * getNext();
    bool hasNext();

    void process(unsigned int deltaTime) override;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_PATH_H
