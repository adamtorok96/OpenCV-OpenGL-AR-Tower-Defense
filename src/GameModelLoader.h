#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECTLOADER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECTLOADER_H

#include <fstream>

#include <GL/gl.h>

#include <nlohmann/json.hpp>

#include "objects/GameModel.h"

using namespace std;
using json = nlohmann::json;

class GameModelLoader {

    static GameModelLoader * instance;

    map<string, GLuint> models;

public:
    static void load();
    static GameModelLoader * getInstance();

    GLuint getModelByName(const string & name);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECTLOADER_H
