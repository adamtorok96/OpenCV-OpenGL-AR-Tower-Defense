#include "GameModelLoader.h"

GameModelLoader * GameModelLoader::instance;

GameModelLoader *GameModelLoader::getInstance() {
    return GameModelLoader::instance;
}

void GameModelLoader::load() {
    GameModelLoader::instance = new GameModelLoader;

    ifstream ifs("assets/models.json");
    json j;

    ifs >> j;

    for(const auto &model : j["models"]) {
        Vec3d * color = nullptr;

        if( model["color"] != nullptr )
            color = new Vec3d(model["color"][0], model["color"][1], model["color"][2]);

        GameModelLoader::instance->models[model["name"]] = GameModel::load(
                model["path"],
                Vec3d(model["translate"][0], model["translate"][1], model["translate"][2]),
                Vec3d(model["rotate"][0], model["rotate"][1], model["rotate"][2]),
                Vec3d(model["scale"][0], model["scale"][1], model["scale"][2]),
                color
       );
   }
}

GLuint GameModelLoader::getModelByName(const string &name) {
    return models[name];
}
