#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_ENDPATH_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_ENDPATH_H


#include "Path.h"

class EndPath : public Path {
public:
    Path *getNext() override;
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_ENDPATH_H
