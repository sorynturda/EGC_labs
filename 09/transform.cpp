
#define _USE_MATH_DEFINES
#include <math.h>
#include "transform.h"

namespace egc {

    mat3 translate(const vec2 translateArray) {
        egc::mat3 trnslationMatrix = mat3();
        trnslationMatrix.matrixData[6] = translateArray.x;
        trnslationMatrix.matrixData[7] = translateArray.y;
        return trnslationMatrix;
    }
    mat3 translate(float tx, float ty) {
        egc::mat3 trnslationMatrix = mat3();
        trnslationMatrix.matrixData[6] = tx;
        trnslationMatrix.matrixData[7] = ty;
        return trnslationMatrix;
    }

    mat3 scale(const vec2 scaleArray) {
        egc::mat3 scaleMatrix = mat3();
        scaleMatrix.matrixData[0] = scaleArray.x;
        scaleMatrix.matrixData[4] = scaleArray.y;
        return scaleMatrix;
    }
    mat3 scale(float sx, float sy) {
        egc::mat3 scaleMatrix = mat3();
        scaleMatrix.matrixData[0] = sx;
        scaleMatrix.matrixData[4] = sy;
        return scaleMatrix;
    }

    mat3 rotate(float angle) {
        egc::mat3 rotationMatrix = mat3();
        float angleInRadians = angle * M_PI / 180.0f;
        float cosAngle = std::cos(angleInRadians);
        float sinAngle = std::sin(angleInRadians);

        rotationMatrix.matrixData[0] = cosAngle;
        rotationMatrix.matrixData[4] = cosAngle;
        rotationMatrix.matrixData[1] = sinAngle;
        rotationMatrix.matrixData[3] = -sinAngle;

        return rotationMatrix;
    }

    //transformation matrices in 3D
    mat4 translate(const vec3 translateArray) {
        egc::mat4 translateMatrix = mat4();
        translateMatrix.matrixData[12] = translateArray.x;
        translateMatrix.matrixData[13] = translateArray.y;
        translateMatrix.matrixData[14] = translateArray.z;
        return translateMatrix;
    }
    mat4 translate(float tx, float ty, float tz) {
        egc::mat4 translateMatrix = mat4();
        translateMatrix.matrixData[12] = tx;
        translateMatrix.matrixData[13] = ty;
        translateMatrix.matrixData[14] = tz;
        return translateMatrix;
    }

    mat4 scale(const vec3 scaleArray) {
        egc::mat4 scaleMatrix = mat4();
        scaleMatrix.matrixData[0] = scaleArray.x;
        scaleMatrix.matrixData[5] = scaleArray.y;
        scaleMatrix.matrixData[10] = scaleArray.z;

        return scaleMatrix;
    }
    mat4 scale(float sx, float sy, float sz) {
        egc::mat4 scaleMatrix = mat4();
        scaleMatrix.matrixData[0] = sx;
        scaleMatrix.matrixData[5] = sy;
        scaleMatrix.matrixData[10] = sz;

        return scaleMatrix;
    }

    mat4 rotateX(float angle) {
        egc::mat4 rotateXMatrix = mat4();
        float angleInRadians = angle * M_PI / 180.0f;
        const float cosAngle = std::cos(angleInRadians);
        const float sinAngle = std::sin(angleInRadians);
        rotateXMatrix.matrixData[5] = cosAngle; 
        rotateXMatrix.matrixData[6] = sinAngle; 
        rotateXMatrix.matrixData[9] = -sinAngle; 
        rotateXMatrix.matrixData[10] = cosAngle; 
        return rotateXMatrix;
    }
    mat4 rotateY(float angle) {
        egc::mat4 rotateYMatrix = mat4();
        float angleInRadians = angle * M_PI / 180.0f;
        const float cosAngle = std::cos(angleInRadians);
        const float sinAngle = std::sin(angleInRadians);
        rotateYMatrix.matrixData[0] = cosAngle;
        rotateYMatrix.matrixData[8] = sinAngle;
        rotateYMatrix.matrixData[2] = -sinAngle;
        rotateYMatrix.matrixData[10] = cosAngle;
        return rotateYMatrix;
    }
    mat4 rotateZ(float angle) {
        egc::mat4 rotateZMatrix = mat4();
        float angleInRadians = angle * M_PI / 180.0f;
        const float cosAngle = std::cos(angleInRadians);
        const float sinAngle = std::sin(angleInRadians);
        rotateZMatrix.matrixData[0] = cosAngle;
        rotateZMatrix.matrixData[1] = sinAngle;
        rotateZMatrix.matrixData[4] = -sinAngle;
        rotateZMatrix.matrixData[5] = cosAngle;
        return rotateZMatrix;
    }
}