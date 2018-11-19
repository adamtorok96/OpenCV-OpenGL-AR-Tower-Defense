#include "TowerDefense.h"

void TowerDefense::init() {
    GameModelLoader::load();
    ArucoObjectMapper::load();

    arucoObjectMapper = ArucoObjectMapper::getInstance();
}

void TowerDefense::draw(
        unsigned int deltaTime,
        const vector<int> & ids,
        const vector <Vec3d> & rvecs,
        const vector <Vec3d> & tvecs) {
    for(auto i = 0; i < ids.size(); i++) {
        updateObjectPosition(ids[i], rvecs[i], tvecs[i]);
    }

    for(auto gameObject : arucoObjectMapper->getGameObjects()) {
        gameObject.second->process(deltaTime);
    }

    for(auto gameObject : arucoObjectMapper->getGameModels()) {
        gameObject.second->draw();
    }
}

void TowerDefense::updateObjectPosition(int id, const Vec3d &rvec, const Vec3d &tvec) {
    if( arucoObjectMapper->hasGameObjectId(id) ) {
        cout << "found: " << id << endl;
        arucoObjectMapper->getGameObjectById(id)->setPosition(rvec, tvec);
    }
}