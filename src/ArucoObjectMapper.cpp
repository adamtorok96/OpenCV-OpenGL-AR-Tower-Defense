#include "ArucoObjectMapper.h"

ArucoObjectMapper * ArucoObjectMapper::instance;

ArucoObjectMapper *ArucoObjectMapper::getInstance() {
    return instance;
}

ArucoObjectMapper::~ArucoObjectMapper() {

}

void ArucoObjectMapper::addPositionable(int id, GameObject *gameObject) {
    positionables[id] = gameObject;
}

void ArucoObjectMapper::addProcessable(GameObject *gameObject) {
    processables.push_back(gameObject);
}

void ArucoObjectMapper::addDrawable(GameModel *gameModel) {
    drawables.push_back(gameModel);
}

void ArucoObjectMapper::addPath(int id, Path * path) {
    addPositionable(id, path);
    addProcessable(path);

    if( !pathes.empty() ) {
        pathes[pathes.size() - 1]->setNext(path);
    }

    pathes.push_back(path);
}

void ArucoObjectMapper::addTower(int id, Tower *tower) {
    addPositionable(id, tower);
    addProcessable(tower);
    addDrawable(tower);
}

void ArucoObjectMapper::addMinion(Minion *minion) {
    addProcessable(minion);
    addDrawable(minion);

    minions.push_back(minion);
}

void ArucoObjectMapper::addCannonBall(CannonBall *cannonBall) {
    addProcessable(cannonBall);
    addDrawable(cannonBall);
}

void ArucoObjectMapper::load() {
    instance = new ArucoObjectMapper;

    ifstream ifs("assets/aruco_object_mapping.json");
    json j;

    ifs >> j;

    instance->gameObjectLoader = GameModelLoader::getInstance();

    for(const auto &obj : j["mapping"]) {
        if( obj["name"] == "tower" ) {
            instance->addTower(obj["id"], new Tower(instance->gameObjectLoader->getModelByName("tower")));
        }
        else if( obj["name"]  == "path" ) {
            instance->addPath(obj["id"], instance->getPathes().empty() ? new StartPath : new Path);
        }
    }
}

vector<GameObject *> &ArucoObjectMapper::getProcessables() {
    return processables;
}

vector<GameModel *> &ArucoObjectMapper::getDrawables() {
    return drawables;
}

vector<Path *> &ArucoObjectMapper::getPathes() {
    return pathes;
}

vector<Minion *> &ArucoObjectMapper::getMinions() {
    return minions;
}

void ArucoObjectMapper::spawnMinion(Path *path) {
    Minion *minion = new Minion(gameObjectLoader->getModelByName("minion"));

    minion->setPosition(path);
    minion->setNextPath(path->getNext());

    addMinion(minion);
}

void ArucoObjectMapper::spawnCannonBall(Tower * tower) {
    Minion * minion = getClosestMinion(tower);

    if( minion == nullptr )
        return;

    Vec3d dir = normalize(minion->getPosition() - tower->getPosition());

    auto cannonBall = new CannonBall(dir);

    cannonBall->setPosition(tower); // ->getPosition() + Vec3d(0, 0, 0.5f)

    addCannonBall(cannonBall);
}

void ArucoObjectMapper::updatePositionIfExists(int id, const Vec3d &rvec, const Vec3d &tvec) {
    for(auto positionable : positionables) {
        if( positionable.first == id ) {
            positionable.second->setPosition(rvec, tvec);

            break;
        }
    }
}

Minion *ArucoObjectMapper::getClosestMinion(GameObject *gameObject) {
    ArucoObjectMapper * arucoObjectMapper = ArucoObjectMapper::getInstance();

    if( arucoObjectMapper->getMinions().empty() )
        return nullptr;

    Minion * closest = arucoObjectMapper->getMinions()[0];
    double minDist = arucoObjectMapper->getMinions()[0]->getDistance(*gameObject);

    for(unsigned int i = 1; i < arucoObjectMapper->getMinions().size(); i++) {
        if( arucoObjectMapper->getMinions()[i]->getDistance(*gameObject) < minDist ) {
            closest = arucoObjectMapper->getMinions()[i];
            minDist = arucoObjectMapper->getMinions()[i]->getDistance(*gameObject);
        }
    }

    return closest;
}