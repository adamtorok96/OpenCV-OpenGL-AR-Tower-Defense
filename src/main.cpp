#include <iostream>

#include "FrameHandler.h"

int main(int argc, char * argv[]) {

    srand (static_cast<unsigned int>(time(nullptr)));

    FrameHandler frameHandler;
    frameHandler.openCamera(0);
    frameHandler.readCameraParameters("assets/cam2.calib");
    frameHandler.init(&argc, argv);
    frameHandler.run();

    return 0;
}