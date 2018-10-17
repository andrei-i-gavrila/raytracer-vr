#include <iostream>
#include "Vector3.hpp"

#ifndef RT_INTERSECTION_INCLUDED
#define RT_INTERSECTION_INCLUDED

namespace rt {
    class Geometry;
    class Line;

    class Intersection {
    private:
        float distanceFromSource;
        Vector3 point;
        const Geometry& body;
        const Line& ray;

    public:
        Intersection(const Geometry& body, const Line& ray, float distance) : distanceFromSource{distance}, point{ray.vec(distance)}, body{body}, ray{ray} {}

        inline float getDistanceFromSource() const {
            return distanceFromSource;
        }

        inline const Vector3& getIntersectionPoint() const {
            return point;
        }

        inline const Geometry& getBody() const {
            return body;
        }

        inline const Line& line() const {
            return ray;
        }
    };
}

#endif
