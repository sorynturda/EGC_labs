#include "transform.h"

namespace egc {
    mat3 translate(const vec2 translateArray) {
        mat3 result;
        
        result.matrixData[6] = translateArray.x;
        result.matrixData[7] = translateArray.y;

        return result;
    }
    mat3 translate(float tx, float ty) {
        mat3 result;

        result.matrixData[6] = tx;
        result.matrixData[7] = ty;

        return result;
    }

    mat3 scale(const vec2 scaleArray) {
         mat3 result;

         result.matrixData[0] = scaleArray.x;
         result.matrixData[4] = scaleArray.y;

        return result;
    }
    mat3 scale(float sx, float sy) {
        mat3 result;

        result.matrixData[0] = sx;
        result.matrixData[4] = sy;

        return result;
    }

    mat3 rotate(float angle) {
        float rad = (PI / 180) * angle;
        mat3 result;

        result.matrixData[0] = cos(rad);
        result.matrixData[1] = sin(rad);
        result.matrixData[3] = -sin(rad);
        result.matrixData[4] = cos(rad);

        return result;
    }

    //transformation matrices in 3D
    mat4 translate(const vec3 translateArray) {
        mat4 result;
        
        result.matrixData[12] = translateArray.x;
        result.matrixData[13] = translateArray.y;
        result.matrixData[14] = translateArray.z;

        return result;
    }

    mat4 translate(float tx, float ty, float tz) {
        mat4 result;

        result.matrixData[12] = tx;
        result.matrixData[13] = ty;
        result.matrixData[14] = tz;

        return result;
    }

    mat4 scale(const vec3 scaleArray) {
        mat4 result;

        result.matrixData[0] = scaleArray.x;
        result.matrixData[5] = scaleArray.y;
        result.matrixData[10] = scaleArray.z;

        return result;
    }
    mat4 scale(float sx, float sy, float sz) {
        mat4 result;

        result.matrixData[0] = sx;
        result.matrixData[5] = sy;
        result.matrixData[10] = sz;

        return result;
    }

    mat4 rotateX(float angle) {
        float rad = (PI / 180) * angle;
        mat4 result;

        result.matrixData[5] = cos(rad);
        result.matrixData[6] = sin(rad);
        result.matrixData[9] = -sin(rad);
        result.matrixData[10] = cos(rad);

        return result;
    }
    mat4 rotateY(float angle) {
        float rad = (PI / 180) * angle;
        mat4 result;

        result.matrixData[0] = cos(rad);
        result.matrixData[2] = -sin(rad);
        result.matrixData[8] = sin(rad);
        result.matrixData[10] = cos(rad);

        return result;
    }
    mat4 rotateZ(float angle) {
        float rad = (PI / 180) * angle;
        mat4 result;

        result.matrixData[0] = cos(rad);
        result.matrixData[1] = sin(rad);
        result.matrixData[4] = -sin(rad);
        result.matrixData[5] = cos(rad);

        return result;
    }
}