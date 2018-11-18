#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H

#include <fstream>

#include <nlohmann/json.hpp>

#include "GameObjectLoader.h"
#include "GameObject.h"
#include "Tower.h"

using namespace std;
using json = nlohmann::json;

class ArucoModelMapper {
    static ArucoModelMapper * instance;

    map<int, GameObject*> gameObjects;

public:
    static void load();
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
