#include "mat3.h"
#include <cmath>

namespace egc {
mat3& mat3::operator =(const mat3& srcMatrix) {
    for (int i = 0; i < 9; i++)
        matrixData[i] = srcMatrix.matrixData[i];
    return *this;
}

mat3 mat3::operator *(float scalarValue) const {
    float newMatrixData[9];
    for (int i = 0; i < 9; i++)
        newMatrixData[i] = scalarValue * matrixData[i];
    return mat3(newMatrixData);

}

mat3 mat3::operator *(const mat3& srcMatrix) const {
    float newMatrixData[9] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                newMatrixData[at(i, j)] += matrixData[at(i, k)] * srcMatrix[at(k, j)];
    }
}

vec3 mat3::operator *(const vec3& srcVector) const {
    vec3 vec = vec3();
    vec.x = matrixData[at(0,0)] * srcVector.x + matrixData[at(0,1)] * srcVector.y + matrixData[at(0,2)]*srcVector.z;
    vec.y = matrixData[at(1,0)] * srcVector.x + matrixData[at(1,1)] * srcVector.y + matrixData[at(1,2)]*srcVector.z;
    vec.z = matrixData[at(2,0)] * srcVector.x + matrixData[at(2,1)] * srcVector.y + matrixData[at(2,2)]*srcVector.z;
}

mat3 mat3::operator +(const mat3& srcMatrix) const {
    float newMatrixData[9];
    for (int i = 0; i < 9; i++)
        newMatrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
    return mat3(newMatrixData);
}

//get element by (row, column)
float& at(int i, int j) {
    return matrixData[3 * j + i];
}

const float& at(int i, int j) const {
    return matrixData[3 * j + i];
}

float determinant() const {
    float det = 0.f;
    det += at(0, 0) * (at(1, 1) * at(2, 2) - at(1, 2) * at(2, 1));
    det -= at(0, 1) * (at(1, 0) * at(2, 2) - at(2, 0) * at(1, 2));
    det += at(0, 2) * (at(2, 0) * at(2, 1) - at(1, 1) * at(2, 0));
}

mat3 inverse() const {
    float matrixDet = determinant();
    mat3 result = mat3();
    if () {
        mat3 adjoint = mat3();
        float invDet = 1.0f / matrixDet;
    }
}

mat3 transpose() const {
    // float newMatrixData[9];
    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 3; j++)
    //         newMatrixData[at(i, j)] = matrixData[at(j, i)];
}

}