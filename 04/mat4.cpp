#include "mat4.h"
#include "mat3.h"
#include <cmath>

namespace egc {
mat4& mat4::operator =(const mat4& srcMatrix) {
    for (int i = 0; i < 16; i++)
        matrixData[i] = srcMatrix.matrixData[i];
    return *this;
}

mat4 mat4::operator *(float scalarValue) const {
    float newMatrixData[16];
    for (int i = 0; i < 16; i++)
        newMatrixData[i] = scalarValue * matrixData[i];
    return mat4(newMatrixData);
}

mat4 mat4::operator *(const mat4& srcMatrix) const {
    float newMatrixData[16] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                newMatrixData[4 * j + i] += at(i, k) * srcMatrix.at(k, j);
    return mat4(newMatrixData);
}

vec4 mat4::operator *(const vec4& srcVector) const {
    vec4 vec = vec4();
    vec.x = at(0, 0) * srcVector.x + at(0, 1) * srcVector.y + at(0, 2) * srcVector.z + at(0, 3) * srcVector.w;
    vec.y = at(1, 0) * srcVector.x + at(1, 1) * srcVector.y + at(1, 2) * srcVector.z + at(1, 3) * srcVector.w;
    vec.z = at(2, 0) * srcVector.x + at(2, 1) * srcVector.y + at(2, 2) * srcVector.z + at(2, 3) * srcVector.w;
    vec.w = at(3, 0) * srcVector.x + at(3, 1) * srcVector.y + at(3, 2) * srcVector.z + at(3, 3) * srcVector.w;
    return vec;
}

mat4 mat4::operator +(const mat4& srcMatrix) const {
    float newMatrixData[16];
    for (int i = 0; i < 16; i++)
        newMatrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
    return mat4(newMatrixData);
}

//get element by (row, column)
float& mat4::at(int i, int j) {
    return matrixData[4 * j + i];
}

const float& mat4::at(int i, int j) const {                                                     // 00 01 02 03
    return matrixData[4 * j + i];                                                               // 10 11 12 13
}                                                                                               // 20 21 22 23
//                                                                                              // 30 31 32 33
float mat4::determinant() const {
    float det = 0.0f;
    float m1Data[9] = {at(1, 1), at(1, 2), at(1, 3), at(2, 1), at(2, 2), at(2, 3), at(3, 1), at(3, 2), at(3, 3)};
    float m2Data[9] = {at(1, 0), at(1, 2), at(1, 3), at(2, 0), at(2, 2), at(2, 3), at(3, 0), at(3, 2), at(3, 3)};
    float m3Data[9] = {at(1, 0), at(1, 1), at(1, 3), at(2, 0), at(2, 1), at(2, 3), at(3, 0), at(3, 1), at(3, 3)};
    float m4Data[9] = {at(1, 0), at(1, 1), at(1, 2), at(2, 0), at(2, 1), at(2, 2), at(3, 0), at(3, 1), at(3, 2)};
    mat3 m1 = mat3(m1Data);
    mat3 m2 = mat3(m2Data);
    mat3 m3 = mat3(m3Data);
    mat3 m4 = mat3(m4Data);
    det += at(0, 0) * m1.determinant();
    det -= at(0, 1) * m2.determinant();
    det += at(0, 2) * m3.determinant();
    det -= at(0, 3) * m4.determinant();
    return det;
}

mat4 mat4::inverse() const {
    mat4 result = mat4();
    (*this).transpose();
    float matrixDet = determinant();
    if (std::abs(matrixDet) > std::numeric_limits<float>::epsilon()) {
        float invDet = 1.0f / matrixDet;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                float newMatrixData[9];
                int n = 0;
                for (int k = 0; k < 4; k++)
                    for (int l = 0; l < 4; l++) {
                        if (k != j && l != i)
                            newMatrixData[n++] = at(l, k);
                    }
                result.matrixData[4 * j + i] = mat3(newMatrixData).determinant();
            }
        }
        result = result * invDet;
    }
    return result;
}

mat4 mat4::transpose() const {
    float newMatrixData[16];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            newMatrixData[i + 4 * j] = matrixData[i * 4 + j];
    return mat4(newMatrixData);
}

}