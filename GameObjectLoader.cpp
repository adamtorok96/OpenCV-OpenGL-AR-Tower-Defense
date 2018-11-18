#include "GameObjectLoader.h"

GameObjectLoader * GameObjectLoader::instance;

GameObjectLoader *GameObjectLoader::getInstance() {
    return GameObjectLoader::instance;
}

void GameObjectLoader::load() {
    GameObjectLoader::instance = new GameObjectLoader;

    ifstream ifs("assets/models.json");
    json j;

    ifs >> j;

    for(const auto &model : j["models"]) {
        GameObjectLoader::instance->models[model["name"]] = GameObject::load(
                model["path"],
                Vec3d(model["translate"][0], model["translate"][1], model["translate"][2]),
                Vec3d(model["rotate"][0], model["rotate"][1], model["rotate"][2]),
                Vec3d(model["scale"][0], model["scale"][1], model["scale"][2])
       );
   }
}

GLuint GameObjectLoader::getModelByName(const string &name) {
    return models[name];
}
