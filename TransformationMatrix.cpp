#include "TransformationMatrix.h"

Matrix TransformationMatrix::scaleFigure(const double &scale) {
    Matrix matrix;

    matrix(1,1) = scale;
    matrix(2,2) = scale;
    matrix(3,3) = scale;
    matrix(4,4) = 1;

    return matrix;
}

Matrix TransformationMatrix::rotateX(const double &angle) {
    Matrix matrix;

    matrix(1,1) = 1;
    matrix(2,2) = cos(angle);
    matrix(2,3) = sin(angle);
    matrix(3,2) = -sin(angle);
    matrix(3,3) = cos(angle);
    matrix(4,4) = 1;

    return matrix;
}

Matrix TransformationMatrix::rotateY(const double &angle) {
    Matrix matrix;

    matrix(1,1) = cos(angle);
    matrix(1,3) = -sin(angle);
    matrix(2,2) = 1;
    matrix(3,1) = sin(angle);
    matrix(3,3) = cos(angle);
    matrix(4,4) = 1;

    return matrix;
}

Matrix TransformationMatrix::rotateZ(const double &angle) {
    Matrix matrix;

    matrix(1,1) = cos(angle);
    matrix(1,2) = sin(angle);
    matrix(2,1) = -sin(angle);
    matrix(2,2) = cos(angle);
    matrix(3,3) = 1;
    matrix(4,4) = 1;

    return matrix;
}

Matrix TransformationMatrix::translateFigure(const Vector3D &vector) {
    Matrix matrix;

    matrix(1,1) = 1;
    matrix(2,2) = 1;
    matrix(3,3) = 1;
    matrix(4,4) = 1;

    matrix(4,1) = vector.x;
    matrix(4,2) = vector.y;
    matrix(4,3) = vector.z;

    return matrix;
}

Matrix TransformationMatrix::eyePointTransformation(const Vector3D &eyepoint) {
    double r = eyepoint.length();
    double theta = std::atan2(eyepoint.y, eyepoint.x);
    double phi = std::acos(eyepoint.z / r);

    Matrix matrix;
    matrix(1,1) = -sin(theta);
    matrix(1,2) = -cos(theta) * cos(phi);
    matrix(1,3) = cos(theta) * sin(phi);

    matrix(2,1) = cos(theta);
    matrix(2,2) = -sin(theta) * cos(phi);
    matrix(2,3) = sin(theta) * sin(phi);

    matrix(3,2) = sin(phi);
    matrix(3,3) = cos(phi);

    matrix(4,3) = -r;
    matrix(4,4) = 1;


    return matrix;
}

Matrix
TransformationMatrix::linedrawing3DTransformation(const double &scale, const double &angleX, const double &angleY,
                                                  const double &angleZ, const Vector3D &vector, Vector3D eye) {

    Matrix matrix = TransformationMatrix::scaleFigure(scale) * TransformationMatrix::rotateX(angleX)
            * TransformationMatrix::rotateY(angleY) * TransformationMatrix::rotateZ(angleZ)
            * TransformationMatrix::translateFigure(vector) * TransformationMatrix::eyePointTransformation(eye);
    return matrix;
}


