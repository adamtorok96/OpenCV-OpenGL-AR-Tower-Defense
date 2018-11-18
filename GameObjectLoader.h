#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECTLOADER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECTLOADER_H

#include <fstream>

#include <GL/gl.h>

#include <nlohmann/json.hpp>

#include "GameObject.h"

using namespace std;
using json = nlohmann::json;

class GameObjectLoader {

    static GameObjectLoader * instance;

    map<string, GLuint> models;

public:
    static void load();
    static GameObjectLoader * getInstance();

    GLuint getModelByName(const string & name);
};


#endif //OPENCV_OPENGL_AR_TOWERDEFENSE_GAMEOBJECTLOADER_H
