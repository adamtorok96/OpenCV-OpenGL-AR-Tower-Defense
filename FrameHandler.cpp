#include "FrameHandler.h"

FrameHandler::FrameHandler() {
    detector = new Detector(0);
}

FrameHandler::~FrameHandler() {
    setOpenGlDrawCallback(WINDOW_NAME, nullptr, nullptr);

    destroyAllWindows();

    videoCapture.release();
}

void FrameHandler::openCamera(int id) {
    if( !videoCapture.open(id) )
        throw Exception();

    width = (unsigned int) videoCapture.get(CAP_PROP_FRAME_WIDTH);
    height = (unsigned int) videoCapture.get(CAP_PROP_FRAME_HEIGHT);

    cout << "Window width: " << width << endl;
    cout << "Window height: " << height << endl;
}

void FrameHandler::readCameraParameters(const string &filename) {
    FileStorage fs(filename, FileStorage::READ);

    if( !fs.isOpened() )
        throw Exception();

    Mat camMatrix, distCoeffs;

    fs["camera_matrix"] >> camMatrix;
    fs["distortion_coefficients"] >> distCoeffs;

    camMatrix.at<double>(0, 2) = width / 2.0f;
    camMatrix.at<double>(1, 2) = height / 2.0f;

    detector->setCameraParameter(camMatrix, distCoeffs);
    detector->setMarkerLength(0.035f);

    double fX = camMatrix.at<double>(0, 0);
    double fY = camMatrix.at<double>(1, 1);

    fovy = 2.0f * atan(0.5f * height / fY) * 180.0f / M_PI;
    aspect = (width * fY) / (height * fX);

    cout << "fovy: " << fovy << endl;
    cout << "ascpect: " << aspect << endl;
}

void FrameHandler::init(int *argc, char **argv) {
    initOpenGL(argc, argv);
    initBackground();
}

void FrameHandler::initOpenGL(int * argc, char * argv[]) {
    namedWindow(WINDOW_NAME, WINDOW_OPENGL);
    resizeWindow(WINDOW_NAME, width, height);

//    glDisable(GL_CULL_FACE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    glViewport(0, 0, height, width);

    glutInit(argc, argv);

    setOpenGlDrawCallback(WINDOW_NAME, staticDraw, this);
}

void FrameHandler::initBackground() {
    Mat_<Vec2f> vertex(1, 4);
    Mat_<Vec2f> texCoords(1, 4);
    Mat_<int> indices(1, 6);

    vertex << Vec2f(-1, 1), Vec2f(-1, -1), Vec2f(1, -1), Vec2f(1, 1);
    texCoords << Vec2f(0, 0), Vec2f(0, 1), Vec2f(1, 1), Vec2f(1, 0);
    indices << 0, 1, 2, 2, 3, 0;

    backgroundData = new DrawData;

    backgroundData->arrays.setVertexArray(vertex);
    backgroundData->arrays.setTexCoordArray(texCoords);
    backgroundData->buffer.copyFrom(indices);

    glEnable(GL_TEXTURE_2D);

    backgroundData->texture2D.bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void FrameHandler::run() {
    while( true ) {
        updateWindow(WINDOW_NAME);

        auto key = (char)waitKey(40);

        if( key == 27 )
            break;
    }
}

void FrameHandler::staticDraw(void * data) {
    auto * frameHandler = static_cast<FrameHandler *>(data);

    frameHandler->draw();
}

void FrameHandler::draw() {
    Mat frame;

    videoCapture >> frame;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawBackground(frame);
    drawObjects(frame);
}

void FrameHandler::drawBackground(Mat &frame) {
    backgroundData->texture2D.copyFrom(frame);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        ogl::render(backgroundData->arrays, backgroundData->buffer, ogl::TRIANGLES);
    glPopMatrix();
}

void FrameHandler::drawObjects(Mat &frame) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, aspect, zNear, zFar);

    vector<int> ids;
    vector<Vec3d> rvecs, tvecs;

    tie(ids, rvecs, tvecs) = detector->detect(frame);

    for(unsigned int i = 0; i < ids.size(); i++) {
        drawObject(ids[i], rvecs[i], tvecs[i]);
    }
}

void FrameHandler::drawObject(int id, Vec3d &rvec, Vec3d &tvec) {
    Mat modelViewMatrix = detector->getModelViewMatrix(rvec, tvec);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(&modelViewMatrix.at<double>(0, 0));

    glPushMatrix();
        glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
        glutSolidSphere(0.01f, 20, 20);
    glPopMatrix();
}