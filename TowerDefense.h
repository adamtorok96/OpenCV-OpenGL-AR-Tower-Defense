#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_TOWERDEFENSE_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_TOWERDEFENSE_H


#include "ArucoObjectMapper.h"

class TowerDefense {
    ArucoModelMapper * arucoModelMapper;

    void updateObjectPosition(const Detector * detector, int id, const Vec3d & rvec, const Vec3d & tvec);
public:
    ~TowerDefense();

    void init();
    void draw(const Detector * detector, const vector<int> & ids, const vector <Vec3d> & rvecs, const vector <Vec3d> & tvecs);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_TOWERDEFENSE_H
