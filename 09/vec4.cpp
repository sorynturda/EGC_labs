#include "vec4.h"

namespace egc {

    vec4& vec4::operator =(const vec4& srcVector) {
        x = srcVector.x;
        y = srcVector.y;
        z = srcVector.z;
        w = srcVector.w;
        return *this;
    }

    vec4 vec4::operator +(const vec4& srcVector) const {
        return vec4(x + srcVector.x, y + srcVector.y, z + srcVector.z, w + srcVector.w);
    }

    vec4& vec4::operator +=(const vec4& srcVector) {
        x += srcVector.x;
        y += srcVector.y;
        z += srcVector.z;
        w += srcVector.w;
        return *this;
    }

    vec4 vec4::operator *(float scalarValue) const {
        return vec4(x * scalarValue, y * scalarValue, z * scalarValue, w * scalarValue);
    }

    vec4 vec4::operator -(const vec4& srcVector) const {
        return vec4(x - srcVector.x, y - srcVector.y, z - srcVector.z, w - srcVector.w);
    }

    vec4& vec4::operator -=(const vec4& srcVector) {
        x -= srcVector.x;
        y -= srcVector.y;
        z -= srcVector.z;
        w -= srcVector.w;
        return *this;
    }

    vec4 vec4::operator -() const {
        return vec4(-x, -y, -z, -w);
    }

    float vec4::length() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    vec4& vec4::normalize() {
        float len = length();
        if (len > std::numeric_limits<float>::epsilon()) {
            float invLen = 1.0f / len;
            x *= invLen;
            y *= invLen;
            z *= invLen;
            w *= invLen;
        }
        return *this;
    }

} // namespace egc
