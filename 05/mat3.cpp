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
                newMatrixData[3 * j + i] += at(i, k) * srcMatrix.at(k, j);
    }
    return mat3(newMatrixData);
}

vec3 mat3::operator *(const vec3& srcVector) const {
    vec3 vec = vec3();
    vec.x = at(0, 0) * srcVector.x + at(0, 1) * srcVector.y + at(0, 2) * srcVector.z;
    vec.y = at(1, 0) * srcVector.x + at(1, 1) * srcVector.y + at(1, 2) * srcVector.z;
    vec.z = at(2, 0) * srcVector.x + at(2, 1) * srcVector.y + at(2, 2) * srcVector.z;
    return vec;
}

mat3 mat3::operator +(const mat3& srcMatrix) const {
    float newMatrixData[9];
    for (int i = 0; i < 9; i++)
        newMatrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
    return mat3(newMatrixData);
}

//get element by (row, column)
float& mat3::at(int i, int j) {
    return matrixData[3 * j + i];
}

const float& mat3::at(int i, int j) const {
    return matrixData[3 * j + i];
}

float mat3::determinant() const {
    float det = 0.f;
    det += at(0, 0) * (at(1, 1) * at(2, 2) - at(1, 2) * at(2, 1));
    det -= at(0, 1) * (at(1, 0) * at(2, 2) - at(2, 0) * at(1, 2));
    det += at(0, 2) * (at(1, 0) * at(2, 1) - at(1, 1) * at(2, 0));
    return det;
}

mat3 mat3::inverse() const {
    mat3 result = mat3();
    float matrixDet = determinant();
    if (std::abs(matrixDet) > std::numeric_limits<float>::epsilon()) {
        float invDet = 1.0f / matrixDet;
        result.matrixData[0] = (matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7]);
        result.matrixData[1] = (matrixData[2] * matrixData[7] - matrixData[1] * matrixData[8]);
        result.matrixData[2] = (matrixData[1] * matrixData[5] - matrixData[2] * matrixData[4]);
        result.matrixData[3] = (matrixData[5] * matrixData[6] - matrixData[3] * matrixData[8]);
        result.matrixData[4] = (matrixData[0] * matrixData[8] - matrixData[2] * matrixData[6]);
        result.matrixData[5] = (matrixData[2] * matrixData[3] - matrixData[0] * matrixData[5]);
        result.matrixData[6] = (matrixData[3] * matrixData[7] - matrixData[4] * matrixData[6]);
        result.matrixData[7] = (matrixData[1] * matrixData[6] - matrixData[0] * matrixData[7]);
        result.matrixData[8] = (matrixData[0] * matrixData[4] - matrixData[1] * matrixData[3]);
        result = result * invDet;
    }
    return result;
}


mat3 mat3::transpose() const {
    float newMatrixData[9];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            newMatrixData[i + 3 * j] = matrixData[i * 3 + j];
    return mat3(newMatrixData);
}
}
