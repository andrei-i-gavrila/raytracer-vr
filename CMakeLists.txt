cmake_minimum_required(VERSION 3.10)
project(rt_incomplete_2)

set(CMAKE_CXX_STANDARD 17)


add_executable(rt_incomplete_2
        Color.hpp
        Geometry.hpp
        Image.hpp
        Intersection.hpp
        Light.hpp
        Line.hpp
        lib/lodepng.cpp
        lib/lodepng.hpp
        main.cpp
        Material.hpp
        Scene.hpp
        Sphere.hpp
        Vector3.hpp)

target_compile_options(rt_incomplete_2 PRIVATE -Ofast -Werror -Wall)
