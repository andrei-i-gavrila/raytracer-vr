#ifndef RT_COLOR_INCLUDED
#define RT_COLOR_INCLUDED


namespace rt {

    class Color {
    private:
        float red;
        float green;
        float blue;

    public:
        Color() : red{0.0f}, green{0.0f}, blue{0.0f} {}

        Color(float r, float g, float b) : red{r}, green{g}, blue{b} {}

        Color(const Color& color) : red{color.red}, green{color.green}, blue{color.blue} {}

        inline float getRed() const {
            return red;
        }

        inline float getGreen() const {
            return green;
        }

        inline float getBlue() const {
            return blue;
        }

        inline Color operator+(const Color& color) const {
            return Color(red + color.red, green + color.green, blue + color.blue);
        }

        inline Color& operator+=(const Color& color) {
            red += color.red;
            green += color.green;
            blue += color.blue;
            return *this;
        }

        inline Color operator-(const Color& color) const {
            return Color(red - color.red, green - color.green, blue - color.blue);
        }

        inline Color& operator-=(const Color& color) {
            red -= color.red;
            green -= color.green;
            blue -= color.blue;
            return *this;
        }

        inline Color operator*(const Color& c) const {
            return Color(red * c.red, green * c.green, blue * c.blue);
        }

        inline Color& operator*=(const Color& c) {
            red *= c.red;
            green *= c.green;
            blue *= c.blue;
            return *this;
        }

        inline Color operator/(const Color& color) const {
            return Color(red / color.red, green / color.green, blue / color.blue);
        }

        inline Color& operator/=(const Color& color) {
            red /= color.red;
            green /= color.green;
            blue /= color.blue;
            return *this;
        }

        inline Color operator*(float k) const {
            return Color(red * k, green * k, blue * k);
        }

        inline Color& operator*=(float k) {
            red *= k;
            green *= k;
            blue *= k;
            return *this;
        }

        inline Color operator/(float k) const {
            return Color(red / k, green / k, blue / k);
        }

        inline Color& operator/=(float k) {
            red /= k;
            green /= k;
            blue /= k;
            return *this;
        }
    };
}

#endif
