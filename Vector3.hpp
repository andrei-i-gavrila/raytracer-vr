#include <cmath>

#ifndef RT_VECTOR_INCLUDED
#define RT_VECTOR_INCLUDED

namespace rt {

    class Vector3 {
    private:
        float x;
        float y;
        float z;
    public:
        Vector3() : x{0}, y{0}, z{0} {}

        Vector3(float x, float y, float z) : x{x}, y{y}, z{z} {}

        Vector3(const Vector3& vector) : x{vector.x}, y{vector.y}, z{vector.z} {}

        inline float& getX() {
            return x;
        }

        inline float& getY() {
            return y;
        }

        inline float& getZ() {
            return z;
        }

        inline Vector3 operator+(const Vector3& v) const {
            return Vector3(x + v.x, y + v.y, z + v.z);
        }

        inline Vector3& operator+=(const Vector3& v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        inline Vector3 operator-(const Vector3& v) const {
            return Vector3(x - v.x, y - v.y, z - v.z);
        }

        inline Vector3& operator-=(Vector3& v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        inline float operator*(const Vector3& v) const {
            return x * v.x + y * v.y + z * v.z;
        }

        inline Vector3 operator^(const Vector3& v) const {
            return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
        }

        inline Vector3 operator*(float k) const {
            return Vector3(x * k, y * k, z * k);
        }

        inline Vector3& operator*=(float k) {
            x *= k;
            y *= k;
            z *= k;
            return *this;
        }

        inline Vector3 operator/(float k) const {
            return Vector3(x / k, y / k, z / k);
        }

        inline Vector3& operator/=(float k) {
            x /= k;
            y /= k;
            z /= k;
            return *this;
        }

        inline float length() const {
            return sqrtf(x * x + y * y + z * z);
        }

        inline float length2() const {
            return x * x + y * y + z * z;
        }

        inline float normalize() {
            float norm = length();
            if (norm > 0.0f) {
                float inv = 1.0f / norm;
                x *= inv;
                y *= inv;
                z *= inv;
            }
            return norm;
        }

        float angle(const Vector3& other) {
            return acosf(*this * other / (this->length() * other.length()));
        }
    };
}

#endif
