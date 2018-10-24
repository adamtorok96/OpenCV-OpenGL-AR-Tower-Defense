#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_FRAMEHANDLER_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_FRAMEHANDLER_H

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/opengl.hpp>

#include "Detector.h"

using namespace std;
using namespace cv;

class FrameHandler {
    const char * WINDOW_NAME = "FrameHandler";

    const GLdouble zNear = 0.1f;
    const GLdouble zFar = 100.0f;

    static void staticDraw(void * data);

    VideoCapture videoCapture;
    Detector * detector;

    unsigned int width, height;

    GLdouble fovy, aspect;

    struct DrawData
    {
        ogl::Arrays arrays;
        ogl::Texture2D texture2D;
        ogl::Buffer buffer;
    } * backgroundData;

    void initOpenGL(int * argc, char * argv[]);
    void initBackground();

    void draw();
    void drawBackground(Mat & frame);
    void drawObjects(Mat & frame);
    void drawObject(int id, Vec3d & rvec, Vec3d & tvec);
public:
    FrameHandler();
    ~FrameHandler();

    void openCamera(int id);
    void readCameraParameters(const string & filename);
    void init(int * argc, char * argv[]);
    void run();
};


#endif
