#include <iostream>
#include <fstream>
#include "Color.hpp"
#include <string>
#include "lib/lodepng.hpp"

#ifndef RT_IMAGE_INCLUDED
#define RT_IMAGE_INCLUDED

namespace rt {

    class Image {
        using byte = uint8_t;
    private:
        unsigned int width;
        unsigned int height;
        byte* buffer;

    public:
        Image(unsigned int width, unsigned int height) : width{width}, height{height}, buffer{new byte[4 * width * height]} {
            memset(buffer, 0, static_cast<size_t>(4 * width * height));
        }

        void setPixel(int x, int y, const Color& color) {
            int k = 4 * (y * width + x);
            auto p = ceilf(color.getRed() * 255);
            if (p > 255) {
                p = 255;
            }
            buffer[k] = (byte) p;

            p = ceilf(color.getGreen() * 255);
            if (p > 255) {
                p = 255;
            }
            buffer[k + 1] = (byte) p;

            p = ceilf(color.getBlue() * 255);
            if (p > 255) {
                p = 255;
            }
            buffer[k + 2] = (byte) p;
            buffer[k + 3] = 255;
        }

        void store(const std::string& filename) {
            unsigned char* png;
            size_t pngSize;
            LodePNGState state;

            lodepng_state_init(&state);

            auto error = lodepng_encode(&png, &pngSize, buffer, width, height, &state);
            if (!error) {
                lodepng_save_file(png, pngSize, filename.c_str());
            }
            if (error) {
                std::cerr << "ERROR: " << error << lodepng_error_text(error) << '\n';
            }

            lodepng_state_cleanup(&state);
            delete png;
        }
    };
}

#endif
