#include "Path.h"

void Path::process() {

}

void Path::setNext(Path *next) {
    this->next = next;
}

Path *Path::getNext() {
    return next;
}

bool Path::hasNext() {
    return next != nullptr;
}