/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-10-31 23:05:11
 * @version 0.03
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

namespace ACE
{
    class window
    {
    public:
        window();

        void init_gl();

        void create(ACE_STRING title, vector4<int> bounds);

        void create(ACE_STRING title, uint16_t position,
                    vector2<int> size);

        void set_flags(ACE_FLAGS window_flags);

        void set_fill_color(rgba_color fill_color);

        window &operator=(SDL_Window *_window);

        bool operator==(SDL_Window *_window);

        bool operator!=(SDL_Window *_window);

        bool quit(SDL_Event event), is_open();

        void clear(), display(), close();

        SDL_Window *translate_to_sdl();

        SDL_GLContext get_gl_context();

        vector4<int> get_bounds();

    private:
        window_data _window_data; SDL_Window *_window;
    } /* class window */;

    class polygon
    {
    public:
        void set_point_count(uint64_t count);

        void set_point_position(uint64_t id,
                                vector2<float> position);

        void set_fill_color(rgba_color fill_color);

        void begin(), end();

        void set_position(vector2<float> position);

        void translate_point_to_vertex(uint64_t id);

        void show_unfilled(), show_filled();

        void set_rotation(float angle), rotate(float angle);

        void set_center(ACE::vector2<float> center);

        vector4<float> get_bounds();

    private:
        polygon_data _polygon_data;
    } /* class polygon */;
} // namespace ACE

#endif // ACEENGINE_HPP
