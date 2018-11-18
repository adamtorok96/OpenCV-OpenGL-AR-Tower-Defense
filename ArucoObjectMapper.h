#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H

#include <fstream>

#include <nlohmann/json.hpp>

#include "GameModelLoader.h"
#include "GameObject.h"
#include "Tower.h"
#include "Minion.h"

#include "StartPath.h"

using namespace std;
using json = nlohmann::json;

class ArucoModelMapper {
    static ArucoModelMapper * instance;

    map<int, GameObject*> gameObjects;
    map<int, GameModel*> gameModels;
    vector<Path *> pathes;

    ArucoModelMapper();
    ~ArucoModelMapper();

    void addGameObject(int id, GameObject * gameObject);
    void addGameModel(int id, GameModel * gameModel);
    void addPath(int id, Path * path);
public:
    static ArucoModelMapper * getInstance();
    static void load();

    GameObject * getGameObjectById(int id);
    bool hasGameObjectId(int id);

    map<int, GameObject*> & getGameObjects();
    map<int, GameModel*> & getGameModels();
    vector<Path*> & getPathes();
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
