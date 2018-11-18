#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H

#include <fstream>

#include <nlohmann/json.hpp>

#include "GameModelLoader.h"
#include "GameObject.h"
#include "Tower.h"
#include "Minion.h"

using namespace std;
using json = nlohmann::json;

class ArucoModelMapper {
    static ArucoModelMapper * instance;

    map<int, GameObject*> gameModels;

    ArucoModelMapper();
    ~ArucoModelMapper();

public:
    static ArucoModelMapper * getInstance();
    static void load();

    GameModel * getGameModelById(int id);
    bool hasModelById(int id);

    map<int, GameObject*> & getGameModels();
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
