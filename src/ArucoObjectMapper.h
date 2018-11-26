#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H

#include <fstream>

#include <nlohmann/json.hpp>

#include "GameModelLoader.h"
#include "objects/GameObject.h"
#include "objects/Tower.h"
#include "objects/Minion.h"
#include "objects/CannonBall.h"
#include "objects/StartPath.h"

using namespace std;
using json = nlohmann::json;

class ArucoObjectMapper {
    static ArucoObjectMapper * instance;

    GameModelLoader * gameObjectLoader;

    map<int, GameObject*> positionables;

    vector<GameObject*> processables;
    vector<GameModel*> drawables;

    vector<Path *> pathes;
    vector<Minion *> minions;

    void addPositionable(int id, GameObject * gameObject);
    void addProcessable(GameObject * gameObject);
    void addDrawable(GameModel * gameModel);

    void addPath(int id, Path * path);
    void addTower(int id, Tower * tower);
    void addMinion(Minion * minion);
    void addCannonBall(CannonBall * cannonBall);

    Minion * getClosestMinion(GameObject * gameObject);
public:
    static ArucoObjectMapper * getInstance();
    static void load();

    ~ArucoObjectMapper();

    void updatePositionIfExists(int id, const Vec3d & rvec, const Vec3d & tvec);

    vector<GameObject*> & getProcessables();
    vector<GameModel*> & getDrawables();

    vector<Path*> & getPathes();
    vector<Minion*> & getMinions();

    void spawnMinion(Path * path);
    void spawnCannonBall(Tower * tower);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_ARUCOMODELMAPPER_H