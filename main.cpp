#include <cmath>
#include <iostream>
#include <string>
#include <ctime>

#include "Vector3.hpp"
#include "Line.hpp"
#include "Geometry.hpp"
#include "Sphere.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Intersection.hpp"
#include "Material.hpp"

#include "Scene.hpp"


using namespace std;
using namespace rt;

inline Line getRayForPixel(int x, int y, const Vector3& camera, const Vector3& front, const Vector3& up, const Vector3& right, float viewPlaneDist, float viewPlaneWidth, float viewPlaneHeight) {
    auto targetPos = camera + front * viewPlaneDist + up * (y - viewPlaneHeight / 2) + right * (x - viewPlaneWidth / 2);

    return Line{camera, targetPos, false};
}

inline Intersection* traceRay(const Line& ray, float minDist, float maxDist) {
    Intersection* closestIntersection = nullptr;

    for (auto geometry: scene) {
        auto intersection = geometry->getIntersection(ray, minDist, maxDist);
        if (!closestIntersection && intersection) {
            closestIntersection = intersection;
        } else if (intersection && intersection->getDistanceFromSource() < closestIntersection->getDistanceFromSource()) {
            delete closestIntersection;
            closestIntersection = intersection;
        }
    }

    return closestIntersection;
}

Color calculateLightColor(Intersection* intersection, const Vector3& viewPoint) {
    if (intersection == nullptr) {
        return Color{0.0f, 0.0f, 0.0f};
    }

    Color color{};

    for (auto light: lights) {
        auto baseColor = intersection->getBody().getMaterial().getAmbient() * light->getAmbient();

        auto N = intersection->getBody().normal(intersection->getIntersectionPoint());
        auto T = light->getPosition() - intersection->getIntersectionPoint();
        T.normalize();
        auto NT = N * T;
        if (NT > 0) {
            baseColor += intersection->getBody().getMaterial().getDiffuse() * light->getDiffuse() * NT;
        }
        auto R = N * NT * 2 - T;
        R.normalize();
        auto E = viewPoint - intersection->getIntersectionPoint();
        E.normalize();
        auto ER = E * R;
        if (ER > 0) {
            baseColor += intersection->getBody().getMaterial().getSpecular() * light->getSpecular() * powf(ER, intersection->getBody().getMaterial().getShininess());
        }
        color += baseColor;
    }

    return color;
}

int main() {
    Vector3 viewPoint{0, 0, 0};
    Vector3 viewDirection{0, 0, 1};
    Vector3 viewUp{0, -1, 0};

    auto viewParallel = viewUp^viewDirection;
    viewParallel.normalize();

    auto frontPlaneDist = 0.0f;
    auto backPlaneDist = 1000.0f;

    auto imageWidth = 1920;
    auto imageHeight = 1080;

    auto viewPlaneDist = 512.0f;
    auto viewPlaneWidth = imageWidth * 1.0f;
    auto viewPlaneHeight = imageHeight * 1.0f;


    Image image{static_cast<unsigned int>(imageWidth), static_cast<unsigned int>(imageHeight)};


    for (auto x = 0; x < imageWidth; x++) {
        for (auto y = 0; y < imageHeight; y++) {
            auto&& ray = getRayForPixel(x, y, viewPoint, viewDirection, viewUp, viewParallel, viewPlaneDist, viewPlaneWidth, viewPlaneHeight);
            auto&& intersection = traceRay(ray, frontPlaneDist, backPlaneDist);
            auto&& lightColor = calculateLightColor(intersection, viewPoint);
            image.setPixel(x, y, lightColor);
        }
    }
    image.store("../scene.png");


    return 0;
}
