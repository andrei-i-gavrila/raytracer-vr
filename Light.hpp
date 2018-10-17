#include "Vector3.hpp"
#include "Line.hpp"
#include "Color.hpp"
#include "Intersection.hpp"

#ifndef RT_LIGHT_INCLUDED
#define RT_LIGHT_INCLUDED

namespace rt {
    class Light {
    private:
        Vector3 position;
        Color ambient;
        Color diffuse;
        Color specular;
        int intensity;

    public:
        Light() {
            intensity = 0;
        }

        Light(const Vector3& position, const Color& ambient, const Color& diffuse, const Color& specular, int intensity) :
                position{{position}}, ambient{{ambient}}, diffuse{{diffuse}}, specular{{specular}}, intensity{intensity} {}

        Light(float x, float y, float z, float ar, float ag, float ab, float dr, float dg, float db, float sr, float sg, float sb, int sh) :
                position{x, y, z}, ambient{ar, ag, ab}, diffuse{dr, dg, db}, specular{sr, sg, sb}, intensity{sh} {}

        Light(const Light& light) : position{{light.position}}, ambient{{light.ambient}}, diffuse{{light.diffuse}}, specular{{light.specular}}, intensity{light.intensity} {
        }

        inline const Color& getAmbient() const {
            return ambient;
        }

        inline const Color& getDiffuse() const {
            return diffuse;
        }

        inline const Color& getSpecular() const {
            return specular;
        }

        inline const Vector3& getPosition() const {
            return position;
        }

        inline int getIntensity() const {
            return intensity;
        }
    };
}

#endif
