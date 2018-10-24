#include <tuple>
#include "Detector.h"

Detector::Detector(unsigned int dictionaryId) {
    dictionary = aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME(dictionaryId));
    detectorParams = aruco::DetectorParameters::create();
}

Detector& Detector::setCameraParameter(Mat &camMatrix, Mat &distCoeffs) {
    this->camMatrix = camMatrix;
    this->distCoeffs = distCoeffs;

    return *this;
}

Detector& Detector::setMarkerLength(float length) {
    this->markerLength = length;

    return *this;
}

tuple<vector<int>, vector<Vec3d>, vector<Vec3d>> Detector::detect(Mat &frame) {
    vector<int> ids;
    vector<vector<Point2f>> corners;
    vector<Vec3d> rvecs, tvecs;

    aruco::detectMarkers(frame, dictionary, corners, ids, detectorParams);

    if( !ids.empty() )
        aruco::estimatePoseSingleMarkers(corners, markerLength, camMatrix, distCoeffs, rvecs, tvecs);

    return make_tuple(ids, rvecs, tvecs);
}

Mat Detector::getModelViewMatrix(Vec3d &rvec, Vec3d &tvec) {
    Mat rotation = Mat::zeros(4, 4, CV_64FC1);
    Mat viewMatrix = Mat::zeros(4, 4, CV_64FC1);

    Rodrigues(rvec, rotation);

    for(unsigned int row = 0; row < 3; ++row) {

        for(unsigned int col = 0; col < 3; ++col) {
            viewMatrix.at<double>(row, col) = rotation.at<double>(row, col);
        }

        viewMatrix.at<double>(row, 3) = tvec[row];
    }

    viewMatrix.at<double>(3, 3) = 1.0f;

    Mat cvToGl = Mat::eye(4, 4, CV_64FC1); // zeros

    //cvToGl.at<double>(0, 0) = 1.0f;
    cvToGl.at<double>(1, 1) = -1.0f;
    cvToGl.at<double>(2, 2) = -1.0f;
    //cvToGl.at<double>(3, 3) = 1.0f;

    return (cvToGl * viewMatrix).t();
}

Mat Detector::vec3dToMat(Vec3d &vec) {
    cv::Mat mat(3,1, CV_64FC1);

    mat.at<double>(0,0) = vec[0];
    mat.at<double>(1,0) = vec[1];
    mat.at<double>(2,0) = vec[2];

    return mat;
}


