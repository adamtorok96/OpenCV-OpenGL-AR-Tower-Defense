#include "ArucoObjectMapper.h"

ArucoModelMapper * ArucoModelMapper::instance;

ArucoModelMapper *ArucoModelMapper::getInstance() {
    return instance;
}

ArucoModelMapper::ArucoModelMapper() {

}

ArucoModelMapper::~ArucoModelMapper() {

}

void ArucoModelMapper::addGameObject(int id, GameObject *gameObject) {
    gameObjects[id] = gameObject;
}

void ArucoModelMapper::addGameModel(int id, GameModel *gameModel) {
    addGameObject(id, gameModel);

    gameModels[id] = gameModel;
}

void ArucoModelMapper::addPath(int id, Path * path) {
    addGameObject(id, path);

    if( !pathes.empty() ) {
        pathes[pathes.size() - 1]->setNext(path);
    }

    pathes.push_back(path);
}


void ArucoModelMapper::load() {
    instance = new ArucoModelMapper;

    ifstream ifs("assets/aruco_object_mapping.json");
    json j;

    ifs >> j;

    GameModelLoader * gameObjectLoader = GameModelLoader::getInstance();

    for(const auto &obj : j["mapping"]) {
        if( obj["name"] == "tower" ) {
            instance->addGameModel(obj["id"], new Tower(gameObjectLoader->getModelByName("tower")));
        }
        else if( obj["name"] == "minion" ) {
            instance->addGameModel(obj["id"], new Minion(gameObjectLoader->getModelByName("minion")));
        }
        else if( obj["name"]  == "path" ) {
            instance->addPath(obj["id"], instance->getPathes().empty() ? new StartPath : new Path);
        }
    }
}

GameObject *ArucoModelMapper::getGameObjectById(int id) {
    return gameObjects[id];
}

bool ArucoModelMapper::hasGameObjectId(int id) {
    return gameObjects.find(id) != gameObjects.end();
}

map<int, GameObject *> &ArucoModelMapper::getGameObjects() {
    return gameObjects;
}

map<int, GameModel *> &ArucoModelMapper::getGameModels() {
    return gameModels;
}

vector<Path *> &ArucoModelMapper::getPathes() {
    return pathes;
}
