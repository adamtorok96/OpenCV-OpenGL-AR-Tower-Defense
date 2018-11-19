#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_TOWERDEFENSE_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_TOWERDEFENSE_H

#include "ArucoObjectMapper.h"

class TowerDefense {
    ArucoObjectMapper * arucoObjectMapper;

    long health, points;

    void updateObjectPosition(int id, const Vec3d & rvec, const Vec3d & tvec);
public:
    TowerDefense() : points{0}, health{1000} {}
    ~TowerDefense();

    void init();
    void draw(unsigned int deltaTime, const vector<int> & ids, const vector <Vec3d> & rvecs, const vector <Vec3d> & tvecs);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_TOWERDEFENSE_H
