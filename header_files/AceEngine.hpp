/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-10-29 18:39:53
 * @version 0.02
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

typedef uint16_t ACE_FLAGS;

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
         * with this function you can initialize OpenGL.
         * OpenGL is used to draw objects.
         */
        void init_gl();

        /*
         * with this function you can create a window.
         * 
         * in bounds you need to type position and size,
         * like: ACE::vector4<int>(0(x), 0(y), 800(width), 800(height));
         */
        void create(ACE_STRING title, vector4<int> bounds);

        /*
         * with this function you can create a window,
         * but with ready-made positions, like: centered,
         * top left, top right, bottom left, bottom right.
         */
        void create(ACE_STRING title, uint16_t position, vector2<int> size);

        window &operator=(SDL_Window *_window);

        bool operator==(SDL_Window *_window);

        bool operator!=(SDL_Window *_window);

        // with this boolean you can check if the window tried to close or not.
        bool quit(SDL_Event event);

        // with this boolean you can chek if the window is open or not.
        bool is_open();

    private:
        window_data _window_data;

        SDL_Window *_window;
    };
} // namespace ACE

#endif // ACEENGINE_HPP
