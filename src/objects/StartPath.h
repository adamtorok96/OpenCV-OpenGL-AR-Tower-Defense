#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_STARTPATH_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_STARTPATH_H

#include "Path.h"
#include "../ArucoObjectMapper.h"

class StartPath : public Path {
public:
    StartPath() : Path{} {}

    void process(unsigned int deltaTime) override;
};

#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_STARTPATH_H