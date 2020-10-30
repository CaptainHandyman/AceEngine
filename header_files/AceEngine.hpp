/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-10-30 21:48:33
 * @version 0.025
 */

#ifndef ACEENGINE_HPP
#define ACEENGINE_HPP

#include "includes.hpp"
#include "utilities.hpp"
#include "structures.hpp"

// window positions
#define /* centered     */ ACE_WINDOW_POS_CENTERED 0x0u
#define /* top left     */ ACE_WINDOW_POS_TOP_LEFT 0x1u
#define /* top right    */ ACE_WINDOW_POS_TOP_RIGHT 0x2u
#define /* bottom left  */ ACE_WINDOW_POS_BOTTOM_LEFT 0x3u
#define /* bottom right */ ACE_WINDOW_POS_BOTTOM_RIGHT 0x4u
// window positions

// window flags
enum
{
    /* delete all flags */ ACE_WINDOW_NO_FLAGS = 1 << 0,
    /* fullscreen       */ ACE_WINDOW_FULLSCREEN = 1 << 1,
    /* resizable        */ ACE_WINDOW_RESIZABLE = 1 << 2
};
// window flags

namespace ACE
{
    class window
    {
    public:
        window();

        /*
         * this function initializes OpenGL.
         * OpenGL is used to draw objects.
         * by default OpenGL is initialized when the window is created.
         */
        void init_gl();

        /*
         * this function creates a window.
         * in bounds you need to type position and size,
         * like: ACE::vector4<int>(0(x), 0(y), 800(width), 800(height))
         */
        void create(ACE_STRING title, vector4<int> bounds);

        /*
         * this function creates a window,
         * but with ready-made positions, like: centered,
         * top left, top right, bottom left, bottom right.
         */
        void create(ACE_STRING title, uint16_t position, vector2<int> size);

        /*
         * this function sets flags for the window,
         * like: set_flags(ACE_WINDOW_RESIZABLE |
         *                 ACE_WINDOW_FULLSCREEN).
         * with ACE_WINDOW_NO_FLAGS, you can cancel all flags, you have set.
         */
        void set_flags(ACE_FLAGS window_flags);

        void set_fill_color(rgba_color fill_color);

        // this function closes the window.
        void close();

        window &operator=(SDL_Window *_window);

        bool operator==(SDL_Window *_window);

        bool operator!=(SDL_Window *_window);

        // this boolean checks if the window tried to close or not.
        bool quit(SDL_Event event);

        // this boolean cheks if the window is open or not.
        bool is_open();

        /**/ void clear();
        /*
         * clear and display functions are requ-
         * ired for the drawing to work.
        */
        /**/ void display();

        // this function translates current window to sdl.
        SDL_Window *translate_to_sdl();

    private:
        window_data _window_data;

        SDL_Window *_window;
    };
} // namespace ACE

#endif // ACEENGINE_HPP
