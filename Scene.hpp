#include "Geometry.hpp"
#include "Sphere.hpp"
#include "Light.hpp"
#include <array>

using namespace rt;

int geometryCount = 7;

const std::vector<Geometry*> scene {
        new Sphere(-50, -25, 175, 30, 0.7f, 0.0f, 0.0f),
        new Sphere(-10, 0, 100, 10, 0.7f, 0.7f, 0.0f),
        new Sphere(0, 0, 200, 40, 0.0f, 0.7f, 0.0f),
        new Sphere(0, -50, 200, 10, 0.7f, 0.7f, 0.7f),
        new Sphere(10, 0, 20, 5, 0.0f, 0.7f, 0.7f),
        new Sphere(-70, 0, 100, 10, 0.7f, 0.0f, 0.7f),
        new Sphere(50, 25, 75, 50, 0.0f, 0.0f, 0.7f),
        new Sphere(100, -25, 75, 20, 0.7f, 0.2f, 0.2f)
};

const std::vector<Light*> lights {
        new Light(-50, 0, 0, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 1),
        new Light(20, 20, 0, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 1)
};
