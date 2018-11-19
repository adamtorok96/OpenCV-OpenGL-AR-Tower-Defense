#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H

#include <fstream>

#include <nlohmann/json.hpp>

#include "GameModelLoader.h"
#include "objects/GameObject.h"
#include "objects/Tower.h"
#include "objects/Minion.h"

#include "objects/StartPath.h"

using namespace std;
using json = nlohmann::json;

class ArucoObjectMapper {
    static ArucoObjectMapper * instance;

    GameModelLoader * gameObjectLoader;

    map<int, GameObject*> gameObjects;
    map<int, GameModel*> gameModels;

    vector<Path *> pathes;
    vector<Minion *> minions;

    void addGameObject(int id, GameObject * gameObject);
    void addGameModel(int id, GameModel * gameModel);
    void addPath(int id, Path * path);
    void addMinion(int id, Minion * minion);
public:
    static ArucoObjectMapper * getInstance();
    static void load();

    ~ArucoObjectMapper();

    GameObject * getGameObjectById(int id);
    bool hasGameObjectId(int id);

    map<int, GameObject*> & getGameObjects();
    map<int, GameModel*> & getGameModels();
    vector<Path*> & getPathes();
    vector<Minion*> & getMinions();

    void spawnMinion(Path * path);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H