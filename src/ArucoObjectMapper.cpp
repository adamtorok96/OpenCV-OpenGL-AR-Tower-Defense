#include "ArucoObjectMapper.h"

ArucoObjectMapper * ArucoObjectMapper::instance;

ArucoObjectMapper *ArucoObjectMapper::getInstance() {
    return instance;
}

ArucoObjectMapper::~ArucoObjectMapper() {
    for(auto gameObject : gameObjects) {
        gameObjects.erase(gameObject.first);

        delete gameObject.second;
    }
}

void ArucoObjectMapper::addGameObject(int id, GameObject *gameObject) {
    gameObjects[id] = gameObject;
}

void ArucoObjectMapper::addGameModel(int id, GameModel *gameModel) {
    addGameObject(id, gameModel);

    gameModels[id] = gameModel;
}

void ArucoObjectMapper::addMinion(int id, Minion *minion) {
    minions.push_back(minion);
}

void ArucoObjectMapper::addPath(int id, Path * path) {
    addGameObject(id, path);

    if( !pathes.empty() ) {
        pathes[pathes.size() - 1]->setNext(path);
    }

    pathes.push_back(path);
}

void ArucoObjectMapper::load() {
    instance = new ArucoObjectMapper;

    ifstream ifs("assets/aruco_object_mapping.json");
    json j;

    ifs >> j;

    instance->gameObjectLoader = GameModelLoader::getInstance();

    for(const auto &obj : j["mapping"]) {
        if( obj["name"] == "tower" ) {
            instance->addGameModel(obj["id"], new Tower(instance->gameObjectLoader->getModelByName("tower")));
        }
        else if( obj["name"] == "minion" ) {
            instance->addGameModel(obj["id"], new Minion(instance->gameObjectLoader->getModelByName("minion")));
        }
        else if( obj["name"]  == "path" ) {
            instance->addPath(obj["id"], instance->getPathes().empty() ? new StartPath : new Path);
        }
    }
}

GameObject *ArucoObjectMapper::getGameObjectById(int id) {
    return gameObjects[id];
}

bool ArucoObjectMapper::hasGameObjectId(int id) {
    return gameObjects.find(id) != gameObjects.end();
}

map<int, GameObject *> &ArucoObjectMapper::getGameObjects() {
    return gameObjects;
}

map<int, GameModel *> &ArucoObjectMapper::getGameModels() {
    return gameModels;
}

vector<Path *> &ArucoObjectMapper::getPathes() {
    return pathes;
}

vector<Minion *> &ArucoObjectMapper::getMinions() {
    return minions;
}

void ArucoObjectMapper::spawnMinion(Path *path) {
    Minion * minion = new Minion(gameObjectLoader->getModelByName("minion"));

    minion->setPosition(path);
    minion->setNextPath(path->getNext());

    addGameModel(-1, minion);
    addMinion(4, minion);
}