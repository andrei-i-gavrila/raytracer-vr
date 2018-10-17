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

inline Color traceRay(const Line& ray, float minDist, float maxDist) {
    Intersection* closestIntersection = nullptr;

    for (auto geometry: scene) {
        auto intersection = geometry->getIntersection(ray, minDist, maxDist);
//        if (intersection) {
//            return intersection->getBody().getColor();
//        }
        if (!closestIntersection && intersection) {
            closestIntersection = intersection;
        } else if (intersection && intersection->getDistanceFromSource() < closestIntersection->getDistanceFromSource()) {
            delete closestIntersection;
            closestIntersection = intersection;
        }
    }

    if (!closestIntersection) {
        return Color{0.0f, 0.0f, 0.0f};
    }

    return closestIntersection->getBody().getColor();
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


    auto start = clock();
    clock_t rayStart;
    auto total = 0;
    for (auto x = 0; x < imageWidth; x++) {
        for (auto y = 0; y < imageHeight; y++) {
            auto&& ray = getRayForPixel(x, y, viewPoint, viewDirection, viewUp, viewParallel, viewPlaneDist, viewPlaneWidth, viewPlaneHeight);
            rayStart = clock();
            auto&& color = traceRay(ray, frontPlaneDist, backPlaneDist);
            total += clock() - rayStart;
            image.setPixel(x, y, color);
        }
    }

    cout << clock() - start << " / " << total <<'\n';

    image.store("../scene.png");


    return 0;
}
