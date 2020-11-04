/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:47:31
 * @modify date 2020-11-04 23:02:02
 * @version 0.045
 */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "includes.hpp"

#define ACE_STRING const char *

typedef uint16_t ACE_FLAGS;

namespace ACE
{
    template <typename T>
    class vector2
    {
    public:
        vector2();

        vector2(T x, T y);

        void translate_to_vertex();

        T x = 0, y = 0;
    };

    template <typename T>
    class vector3
    {
    public:
        vector3();

        vector3(T x, T y, T z);

        void translate_to_vertex();

        T x = 0, y = 0, z = 0;
    };

    template <typename T>
    class vector4
    {
    public:
        vector4();

        vector4(T x, T y,
                T w, T h);

        T x = 0, y = 0,
          w = 0, h = 0;
    };

    class rgba_color
    {
    public:
        rgba_color();

        rgba_color(uint16_t r, uint16_t g,
                   uint16_t b);

        rgba_color(uint16_t r, uint16_t g,
                   uint16_t b, uint16_t a);

        uint16_t r = 0, g = 0,
                 b = 0, a = 255;
    };

    class screen
    {
    public:
        static vector2<uint32_t> get_size();
    };

    class mouse
    {
    public:
        static bool left_button_pressed();

        static bool right_button_pressed();

        static bool middle_button_pressed();

        static bool wheel_scrolled_up(SDL_Event event);

        static bool wheel_scrolled_down(SDL_Event event);

        static vector2<int> get_position();
    };

    class timer
    {
    public:
        float in_milliseconds();

        int in_seconds();

        void start();

        void stop();

        void restart();

    private:
        float milliseconds = 0, a = 0;
        bool started = false;
    };

#include "utilities.imp"

} // namespace ACE

#endif // TOOLS_HPP