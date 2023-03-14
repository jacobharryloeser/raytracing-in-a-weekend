#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        vec3() : inner{0,0,0} {}
        vec3(double e0, double e1, double e2) : inner{e0, e1, e2} {}

        double x() const { return inner[0]; }
        double y() const { return inner[1]; }
        double z() const { return inner[2]; }

        vec3 operator-() const { return vec3(-inner[0], -inner[1], -inner[2]); }
        double operator[](int i) const { return inner[i]; }
        double& operator[](int i) { return inner[i]; }

        vec3& operator+=(const vec3 &v) {
            inner[0] += v.inner[0];
            inner[1] += v.inner[1];
            inner[2] += v.inner[2];
            return *this;
        }

        vec3& operator*=(const double t) {
            inner[0] *= t;
            inner[1] *= t;
            inner[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return inner[0]*inner[0] + inner[1]*inner[1] + inner[2]*inner[2];
        }

    public:
        double inner[3];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif

// vec3 Utility Functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.inner[0] << ' ' << v.inner[1] << ' ' << v.inner[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.inner[0] + v.inner[0], u.inner[1] + v.inner[1], u.inner[2] + v.inner[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.inner[0] - v.inner[0], u.inner[1] - v.inner[1], u.inner[2] - v.inner[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.inner[0] * v.inner[0], u.inner[1] * v.inner[1], u.inner[2] * v.inner[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.inner[0], t*v.inner[1], t*v.inner[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.inner[0] * v.inner[0]
         + u.inner[1] * v.inner[1]
         + u.inner[2] * v.inner[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.inner[1] * v.inner[2] - u.inner[2] * v.inner[1],
                u.inner[2] * v.inner[0] - u.inner[0] * v.inner[2],
                u.inner[0] * v.inner[1] - u.inner[1] * v.inner[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}