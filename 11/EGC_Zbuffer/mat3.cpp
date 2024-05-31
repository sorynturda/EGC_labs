#include "mat3.h"

namespace egc {

  
    egc::mat3& egc::mat3::operator=(const mat3& srcMatrix) {

        if (this == &srcMatrix) {
            return *this;
        }


        for (int i = 0; i < 9; i++) {
            matrixData[i] = srcMatrix.matrixData[i];
        }

        return *this;
    }

    egc::mat3 egc::mat3::operator*(float scalarValue) const {
        mat3 result;
        for (int i = 0; i < 9; i++) {
            result.matrixData[i] = matrixData[i] * scalarValue;
        }
        return result;
    }

    mat3 mat3::operator *(const mat3& srcMatrix) const
    {
        mat3 result = mat3();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.matrixData[i + j * 3] = 0.0f;
                for (int k = 0; k < 3; k++) {
                    result.matrixData[i + j * 3] += matrixData[i + k * 3] * srcMatrix.matrixData[j * 3 + k];
                }
            }
        }
        return result;
    }

    vec3 mat3::operator*(const vec3& srcVector) const {
        vec3 result = vec3();
        result.x = matrixData[0] * srcVector.x + matrixData[3] * srcVector.y + matrixData[6] * srcVector.z;
        result.y = matrixData[1] * srcVector.x + matrixData[4] * srcVector.y + matrixData[7] * srcVector.z;
        result.z = matrixData[2] * srcVector.x + matrixData[5] * srcVector.y + matrixData[8] * srcVector.z;

        return result;
    }


    mat3 mat3::operator+(const mat3& srcMatrix) const {
        mat3 result;
        for (int i = 0; i < 9; i++) {
            result.matrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
        }
        return result;
    }

    float& mat3::at(int i, int j) {
        if (i < 0 || i >= 3 || j < 0 || j >= 3) {
            throw std::out_of_range("Index out of bounds");
        }
        return matrixData[i + j * 3];
    }


    const float& mat3::at(int i, int j) const {
        if (i < 0 || i >= 3 || j < 0 || j >= 3) {
            throw std::out_of_range("Index out of bounds");
        }
        return matrixData[i  + j * 3];
    }

    float mat3::determinant() const {
        float det = 0.0f;
        det =
            matrixData[0] * (matrixData[4] * matrixData[8] - matrixData[7] * matrixData[5]) -
            matrixData[1] * (matrixData[3] * matrixData[8] - matrixData[6] * matrixData[5]) +
            matrixData[2] * (matrixData[3] * matrixData[7] - matrixData[6] * matrixData[4]);

        return det;
    }

    mat3 mat3::transpose() const {
        mat3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.matrixData[i + j * 3] = matrixData[i * 3 + j];
            }
        }

        return result;
    }


    mat3 mat3::inverse() const {
        float matrixDet = determinant();
        mat3 result = mat3();

        if (std::abs(matrixDet) >= std::numeric_limits<float>::epsilon()) {
            float invDet = 1.0f / matrixDet; 
            mat3 adjoint = mat3();
            (*this).transpose();
            //calculam coeficientii
            adjoint.matrixData[0] = (matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7]);
            adjoint.matrixData[1] = - matrixData[1] * matrixData[8] + matrixData[2] * matrixData[7];
            adjoint.matrixData[2] = (matrixData[1] * matrixData[5] - matrixData[2] * matrixData[4]);
            adjoint.matrixData[3] = - matrixData[3] * matrixData[8] + matrixData[5] * matrixData[6];
            adjoint.matrixData[4] =  (matrixData[0] * matrixData[8] - matrixData[2] * matrixData[6]);
            adjoint.matrixData[5] =  -matrixData[0] * matrixData[5] + matrixData[2] * matrixData[3];
            adjoint.matrixData[6] =  (matrixData[3] * matrixData[7] - matrixData[4] * matrixData[6]);
            adjoint.matrixData[7] =  - matrixData[0] * matrixData[7] + matrixData[1] * matrixData[6];
            adjoint.matrixData[8] =  (matrixData[0] * matrixData[4] - matrixData[1] * matrixData[3]);

            result = adjoint * invDet;
        }

        return result;
    }

  

}