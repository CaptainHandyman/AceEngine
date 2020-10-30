/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-10-31 00:52:06
 * @version 0.025
 */

#ifndef ACEENGINE_HPP
#define ACEENGINE_HPP

#include "includes.hpp"
#include "utilities.hpp"
#include "structures.hpp"

#define ACE_WINDOW_POS_CENTERED 0x0u
#define ACE_WINDOW_POS_TOP_LEFT 0x1u
#define ACE_WINDOW_POS_TOP_RIGHT 0x2u
#define ACE_WINDOW_POS_BOTTOM_LEFT 0x3u
#define ACE_WINDOW_POS_BOTTOM_RIGHT 0x4u

enum
{
    ACE_WINDOW_NO_FLAGS = 1 << 0,
    ACE_WINDOW_FULLSCREEN = 1 << 1,
    ACE_WINDOW_RESIZABLE = 1 << 2
};
// window flags

namespace ACE
{
    class window
    {
    public:
        window();

        void init_gl();

        void create(ACE_STRING title, vector4<int> bounds);

        void create(ACE_STRING title, uint16_t position, vector2<int> size);

        void set_flags(ACE_FLAGS window_flags);

        void set_fill_color(rgba_color fill_color);

        void close();

        window &operator=(SDL_Window *_window);

        bool operator==(SDL_Window *_window);

        bool operator!=(SDL_Window *_window);

        bool quit(SDL_Event event);

        bool is_open();

        void clear();

        void display();

        SDL_Window *translate_to_sdl();

        SDL_GLContext get_gl_context();

    private:
        window_data _window_data;

        SDL_Window *_window;
    };
} // namespace ACE

#endif // ACEENGINE_HPP
