/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-10-31 00:03:23
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
    /*
     * Don't assume that there are no set_size() and set_position() functions for a window,
     * this is because you can easily set size and position, using SDL2 functions, for example: size -
     *  - SDL_SetWindowSize(ACE::window::translate_to_sdl(), width, height), position -
     *  - SDL_SetWindowPosition(ACE::window::translate_to_sdl(), x, y), thats why there is
     * translate_to_sdl() function. Or if you want to make window fullscreen, you can type
     * SDL_SetWindowFullscreen(ACE::window::translate_to_sdl(), SDL_TRUE | SDL_FALSE)
     * so if you can't find any function here, try to use SDL2 functions, because
     * I don't want to copy SDL2 functions and it's important!
    */
    class window
    {
    public:
        window();

        /*
         * This function initializes OpenGL.
         * OpenGL is used to draw objects.
         * By default OpenGL is initialized when the window is created.
         */
        void init_gl();

        /*
         * This function creates a window.
         * In bounds you need to type position and size,
         * like: ACE::vector4<int>(0(x), 0(y), 800(width), 800(height))
         */
        void create(ACE_STRING title, vector4<int> bounds);

        /*
         * This function creates a window,
         * but with ready-made positions, like: centered,
         * top left, top right, bottom left, bottom right.
         */
        void create(ACE_STRING title, uint16_t position, vector2<int> size);

        /*
         * This function sets flags for the window,
         * like: set_flags(ACE_WINDOW_RESIZABLE |
         *                 ACE_WINDOW_FULLSCREEN).
         * With ACE_WINDOW_NO_FLAGS, you can cancel all flags, you have set.
         */
        void set_flags(ACE_FLAGS window_flags);

        void set_fill_color(rgba_color fill_color);

        // This function closes the window.
        void close();

        window &operator=(SDL_Window *_window);

        bool operator==(SDL_Window *_window);

        bool operator!=(SDL_Window *_window);

        // This boolean checks if the window tried to close or not.
        bool quit(SDL_Event event);

        // This boolean checks if the window is open or not.
        bool is_open();

        /**/ void clear();
        /*
         * Clear and display functions are
         * required for the drawing to work.
        */
        /**/ void display();

        // This function translates current window to SDL2.
        SDL_Window *translate_to_sdl();

        // This function returns OpenGL context.
        SDL_GLContext get_gl_context();

    private:
        // attributes for the window
        /**/ window_data _window_data;
        /**/
        /**/ SDL_Window *_window;
        // attributes for the window
    };
} // namespace ACE

#endif // ACEENGINE_HPP
