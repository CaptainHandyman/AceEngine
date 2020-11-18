/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:47:31
 * @modify date 2020-11-05 12:08:23
 * @version 0.16
 * @desc This program is free software.
 *       You can redistribute it and/or modify.
 */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "includes.hpp"
#include <stdint.h>

#define ACE_STRING const char *

typedef uint16_t ACE_FLAGS;

namespace ACE {
    // 2D vector
    template <typename T> class vector2 {
      public:
        vector2();

        vector2(T x, T y);

        void translate_to_vertex();

        T x = 0, y = 0;
    };

    // 3D vector
    template <typename T> class vector3 {
      public:
        vector3();

        vector3(T x, T y, T z);

        void translate_to_vertex();

        T x = 0, y = 0, z = 0;
    };

    // 4D vector
    template <typename T> class vector4 {
      public:
        vector4();

        vector4(T x, T y, T w, T h);

        T x = 0, y = 0, w = 0, h = 0;
    };

    // rgba color
    class rgba_color {
      public:
        rgba_color();

        rgba_color(uint16_t r, uint16_t g, uint16_t b);

        rgba_color(uint16_t r, uint16_t g, uint16_t b, uint16_t a);

        uint16_t r = 0, g = 0, b = 0, a = 255;
    };

    class screen {
      public:
        // Returns the size of your desktop.
        static vector2<int> get_size();
    };

    class mouse {
      public:
        // Checks if the left mouse button was pressed.
        static bool left_button_pressed();

        // Checks if the right mouse button was pressed.
        static bool right_button_pressed();

        // Checks if the middle mouse button was pressed.
        static bool middle_button_pressed();

        // Checks if the mouse wheel was scrolled up.
        static bool wheel_scrolled_up(SDL_Event event);

        // Checks if the mouse wheel was scrolled down.
        static bool wheel_scrolled_down(SDL_Event event);

        // Returns the position of your mouse.
        static vector2<int> get_position();
    };

    class timer {
      public:
        // Returns time in float.
        float in_milliseconds();

        // Returns time in int.
        int in_seconds();

        // Starts the timer.
        void start();

        // Stops the timer.
        void stop();

        // Restarts the timer.
        void restart();

        // Checks if the timer is started.
        bool is_started();

      private:
        float milliseconds = 0, a = 0;
        bool started = false;
    };

    class keyboard {
      public:
        // Checks if key was pressed on your keyboard.
        static bool is_key_pressed(SDL_Scancode scancode);

        // Checks if any key was pressed on your keyboard.
        static bool is_any_key_pressed();
    };

#include "utilities.imp"

} // namespace ACE

#endif // TOOLS_HPP
