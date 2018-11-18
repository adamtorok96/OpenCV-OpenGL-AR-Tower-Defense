#include "TowerDefense.h"

void TowerDefense::init() {
    GameModelLoader::load();
    ArucoModelMapper::load();

    arucoModelMapper = ArucoModelMapper::getInstance();
}

void TowerDefense::draw(
        const Detector * detector,
        unsigned int deltaTime,
        const vector<int> & ids,
        const vector <Vec3d> & rvecs,
        const vector <Vec3d> & tvecs) {
    for(auto i = 0; i < ids.size(); i++) {
        updateObjectPosition(detector, ids[i], rvecs[i], tvecs[i]);
    }

    for(auto gameObject : arucoModelMapper->getGameObjects()) {
        gameObject.second->process(deltaTime);
    }

    for(auto gameObject : arucoModelMapper->getGameModels()) {
        gameObject.second->draw();
    }
}

void TowerDefense::updateObjectPosition(const Detector * detector, int id, const Vec3d &rvec, const Vec3d &tvec) {
    if( arucoModelMapper->hasGameObjectId(id) ) {
        arucoModelMapper->getGameObjectById(id)->setPosition(detector, rvec, tvec);
    }
}
