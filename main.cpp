#include <iostream>

#include "FrameHandler.h"

int main(int argc, char * argv[]) {

    FrameHandler frameHandler;
    frameHandler.openCamera(0);
    frameHandler.readCameraParameters("cam2.calib");
    frameHandler.init(&argc, argv);
    frameHandler.run();

    return 0;
}