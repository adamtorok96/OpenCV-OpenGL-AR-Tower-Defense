#include "ArucoModelMapper.h"

ArucoModelMapper * ArucoModelMapper::instance;

void ArucoModelMapper::load() {
    instance = new ArucoModelMapper;

    ifstream ifs("assets/aruco_model_mapping.json");
    json j;

    ifs >> j;

    GameObjectLoader * gameObjectLoader = GameObjectLoader::getInstance();

    for(const auto &obj : j["mapping"]) {
        if( obj["model"] == "tower" ) {
            instance->gameObjects[obj["id"]] = new Tower(gameObjectLoader->getModelByName("tower"));
        }
    }
}
