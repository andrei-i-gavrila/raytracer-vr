#include "Geometry.hpp"
#include "Sphere.hpp"
#include "Light.hpp"
#include <array>

using namespace rt;

int geometryCount = 7;

const std::vector<Geometry*> scene{
        new Sphere(-50, -25, 175, 30, 0.1f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.7f, 0.0f, 0.0f, 10),
        new Sphere(-10, 0, 100, 10, 0.1f, 0.1f, 0.0f, 0.3f, 0.3f, 0.0f, 0.7f, 0.7f, 0.0f, 10),
        new Sphere(0, 0, 200, 40, 0.0f, 0.1f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.7f, 0.0f, 10),
        new Sphere(0, -50, 200, 10, 0.1f, 0.1f, 0.1f, 0.3f, 0.3f, 0.3f, 0.7f, 0.7f, 0.7f, 10),
        new Sphere(10, 0, 20, 5, 0.0f, 0.1f, 0.1f, 0.0f, 0.3f, 0.3f, 0.0f, 0.7f, 0.7f, 10),
        new Sphere(-70, 0, 100, 10, 0.1f, 0.0f, 0.1f, 0.3f, 0.0f, 0.3f, 0.7f, 0.0f, 0.7f, 10),
        new Sphere(50, 25, 75, 50, 0.0f, 0.0f, 0.1f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.7f, 10)
};

const std::vector<Light*> lights{
        new Light(-50, 0, 0, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 1),
        new Light(20, 20, 0, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 1)
};
