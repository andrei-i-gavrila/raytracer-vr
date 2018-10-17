#include "Vector3.hpp"
#include "Line.hpp"
#include "Intersection.hpp"
#include "Geometry.hpp"
#include "Material.hpp"
#include <optional>

#ifndef RT_SPHERE_INCLUDED
#define RT_SPHERE_INCLUDED

namespace rt {

    class Sphere : public Geometry {
    private:
        Vector3 center;
        float radius;

    public:
        Sphere(const Vector3& center, float radius, const Material& material) : Geometry(material), center{Vector3{center}}, radius{radius} {}

        Sphere(float x, float y, float z, float radius, float r, float g, float b) : Geometry(Color(r, g, b)), center{Vector3{x, y, z}}, radius{radius} {}

        Sphere(float x, float y, float z, float radius, float ar, float ag, float ab, float dr, float dg, float db, float sr, float sg, float sb, int sh)
                : Geometry(Material(ar, ag, ab, dr, dg, db, sr, sg, sb, sh)), center{Vector3{x, y, z}}, radius{radius} {}

        ~Sphere() override = default;

        inline Intersection* getIntersection(const Line& line, float minDist, float maxDist) const override {
            auto originToCenter = line.getOrigin() - center;
            auto d = originToCenter * line.getDirection();
            auto squaredDelta = d*d - originToCenter * originToCenter + radius * radius;

            if (squaredDelta < 0.0f) {
                return nullptr;
            }

            auto delta = sqrtf(squaredDelta);

            auto distance1 = -d - delta;
            auto distance2 = -d + delta;

            if (distance1 > minDist && distance1 < maxDist) {
                return new Intersection(*this, line, distance1);
            }

            if (distance2 > minDist && distance2 < maxDist) {
                return new Intersection(*this, line, distance2);
            }

            return nullptr;
        }

        inline float getRadius() const {
            return radius;
        }

        inline const Vector3& getCenter() const {
            return center;
        }

        const Vector3 normal(const Vector3& vec) const override {
            auto normal = vec - center;
            normal.normalize();

            return normal;
        }
    };
}

#endif
