#include "Vector3.hpp"

#ifndef RT_LINE_INCLUDED
#define RT_LINE_INCLUDED

namespace rt {
    class Line {
    private:
        Vector3 origin;
        Vector3 direction;

    public:
        Line() : origin{0.0f, 0.0f, 0.0f}, direction{1.0f, 0.0f, 0.0f} {}

        Line(const Vector3& origin, const Vector3& directionOrDestination, bool parametric) : origin{{origin}} {
            if (parametric) {
                direction = Vector3(directionOrDestination);
            } else {
                direction = Vector3(directionOrDestination - origin);
            }
            direction.normalize();
        }

        Line(const Line& line) {
            origin = Vector3(line.origin);
            direction = Vector3(line.direction);
        }

        inline Vector3 getOrigin() const {
            return origin;
        }

        inline Vector3 getDirection() const {
            return direction;
        }

        inline Vector3 vec(float t) const {
            return Vector3(direction * t + origin);
        }
    };
}

#endif
