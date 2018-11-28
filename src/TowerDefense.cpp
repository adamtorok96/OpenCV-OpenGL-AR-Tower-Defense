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

    arucoObjectMapper->beginDraw();

    for(auto i = 0; i < ids.size(); i++) {
        updateObjectPosition(ids[i], rvecs[i], tvecs[i]);
    }

    for(auto gameObject : arucoObjectMapper->getProcessables()) {
        gameObject->process(deltaTime);
    }

    for(auto gameModel : arucoObjectMapper->getDrawables()) {
        gameModel->draw();
    }

    arucoObjectMapper->endDraw();
}

void TowerDefense::updateObjectPosition(int id, const Vec3d &rvec, const Vec3d &tvec) {
    arucoObjectMapper->updatePositionIfExists(id, rvec, tvec);
}

TowerDefense::~TowerDefense() {
    delete arucoObjectMapper;
}
