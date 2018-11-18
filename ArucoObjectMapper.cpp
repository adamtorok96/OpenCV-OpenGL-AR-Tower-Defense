#include "ArucoObjectMapper.h"

ArucoModelMapper * ArucoModelMapper::instance;

ArucoModelMapper *ArucoModelMapper::getInstance() {
    return instance;
}

void ArucoModelMapper::load() {
    instance = new ArucoModelMapper;

    ifstream ifs("assets/aruco_object_mapping.json");
    json j;

    ifs >> j;

    GameModelLoader * gameObjectLoader = GameModelLoader::getInstance();

    for(const auto &obj : j["mapping"]) {
        if( obj["name"] == "tower" ) {
            instance->gameModels[obj["id"]] = new Tower(gameObjectLoader->getModelByName("tower"));
        }
        else if( obj["name"] == "minion" ) {
            instance->gameModels[obj["id"]] = new Minion(gameObjectLoader->getModelByName("minion"));
        }
    }
}

GameObject *ArucoModelMapper::getGameModelById(int id) {
    return gameModels[id];
}

bool ArucoModelMapper::hasModelById(int id) {
    return gameModels.find(id) != gameModels.end();
}

map<int, GameObject *> &ArucoModelMapper::getGameModels() {
    return gameModels;
}

ArucoModelMapper::ArucoModelMapper() {

}

ArucoModelMapper::~ArucoModelMapper() {

}
