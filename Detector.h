#ifndef OPENCV_OPENGL_AR_TOWERDEFENSE_DETECTOR_H
#define OPENCV_OPENGL_AR_TOWERDEFENSE_DETECTOR_H

#include <opencv2/core.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>

using namespace std;
using namespace cv;
using namespace aruco;

class Detector {
    Ptr<DetectorParameters> detectorParams;
    Ptr<Dictionary> dictionary;

    Mat camMatrix, distCoeffs;
    float markerLength;

    Mat vec3dToMat(Vec3d & vec);

public:
    explicit Detector(unsigned int dictionaryId = DICT_4X4_50);

    Detector& setCameraParameter(Mat & camMatrix, Mat & distCoeffs);
    Detector& setMarkerLength(float length);

    tuple<vector<int>, vector<Vec3d>, vector<Vec3d>> detect(Mat & frame);
    Mat getModelViewMatrix(Vec3d & rvec, Vec3d & tvec);
};


#endif
