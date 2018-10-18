#include <memory>
#include <optional>
#include "Material.hpp"
#include "Vector3.hpp"
#include "Line.hpp"
#include "Intersection.hpp"

#ifndef RT_GEOMETRY_INCLUDED
#define RT_GEOMETRY_INCLUDED

namespace rt {

    class Geometry {
    private:
        Color color;
        Material material;

    public:
        Geometry() : color{}, material{} {}

        explicit Geometry(const Material& material) : color{}, material{{material}} {}

        explicit Geometry(const Color& color) : color{{color}}, material{} {}

        Geometry(const Geometry& geometry) : color{{geometry.color}}, material{{geometry.material}} {}

        virtual ~Geometry() = default;

        inline const Material& getMaterial() const {
            return material;
        }

        inline const Color& getColor() const {
            return color;
        }

        virtual Intersection* getIntersection(const Line& line, float minDist, float maxDist) const = 0;

        virtual const Vector3 normal(const Vector3& vec) const = 0;
    };
}

#endif
