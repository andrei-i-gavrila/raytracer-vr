#include "Vector3.hpp"
#include "Line.hpp"
#include "Color.hpp"
#include "Intersection.hpp"

#ifndef RT_MATERIAL_INCLUDED
#define RT_MATERIAL_INCLUDED

namespace rt {

    class Material {
    private:
        Color ambient;
        Color diffuse;
        Color specular;
        int shininess;

    public:
        Material() {
            shininess = 0;
        }

        Material(const Color& ambient, const Color& diffuse, const Color& specular, int shininess) :
                ambient{Color{ambient}}, diffuse{Color{diffuse}}, specular{Color{specular}}, shininess{shininess} {}

        Material(float ar, float ag, float ab, float dr, float dg, float db, float sr, float sg, float sb, int shininess) :
                ambient{Color{ar, ag, ab}}, diffuse{Color(dr, dg, db)}, specular{Color(sr, sg, sb)}, shininess{shininess} {}

        Material(const Material& mat) : ambient{Color{mat.ambient}}, diffuse{Color{mat.diffuse}}, specular{Color{mat.specular}}, shininess{mat.shininess} {}

        inline const Color& getAmbient() const {
            return ambient;
        }

        inline const Color& getDiffuse() const {
            return diffuse;
        }

        inline const Color& getSpecular() const {
            return specular;
        }

        inline int getShininess() const {
            return shininess;
        }
    };
}

#endif
