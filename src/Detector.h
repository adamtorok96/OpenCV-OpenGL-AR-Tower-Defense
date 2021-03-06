#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_DETECTOR_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_DETECTOR_H

#include <tuple>

#include <opencv2/core.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>

using namespace std;
using namespace cv;
using namespace aruco;

class Detector {
    static Detector * instance;

    Ptr<DetectorParameters> detectorParams;
    Ptr<Dictionary> dictionary;

    Mat camMatrix, distCoeffs;
    float markerLength;

    Mat vec3dToMat(const Vec3d & vec);

    explicit Detector(unsigned int dictionaryId = DICT_4X4_50);
public:
    static Detector * getInstance();

    Detector& setCameraParameter(const Mat & camMatrix, const Mat & distCoeffs);
    Detector& setMarkerLength(float length);

    tuple<vector<int>, vector<Vec3d>, vector<Vec3d>> detect(const Mat & frame);
    void drawDetectedMarkers(const Mat & frame);

    Mat getModelViewMatrix(const Vec3d & rvec, const Vec3d & tvec) const;
};

#endif