/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-11-04 01:55:37
 * @version 0.04
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

        void set_vsync(bool _bool);

        SDL_Window *translate_to_sdl();

        SDL_GLContext get_gl_context();

        vector4<int> get_bounds();

        rgba_color get_fill_color();

    private:
        window_data _window_data;

        SDL_Window *_window;
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

        rgba_color get_fill_color();

    private:
        polygon_data _polygon_data;
    } /* class polygon */;

    class box
    {
    public:
        box();

        void set_size(vector2<float> size);

        void set_position(vector2<float> position);

        void set_fill_color(rgba_color fill_color);

        void rotate(float angle), set_rotation(float angle);

        void show_unfilled(), show_filled();

        void squeeze(vector2<float> sides);

        void set_scale(vector2<float> scale);

        vector4<float> get_bounds();

        rgba_color get_fill_color();

    private:
        polygon _polygon;
    };

    class texture
    {
    public:
        void load(ACE_STRING path);

        void set_smooth(bool _bool);

        int get_id();

        vector2<int> get_size();

        ACE_STRING get_format();

    private:
        texture_data _texture_data;
    };

    class sprite
    {
    public:
        sprite();

        void set_texture(texture _texture);

        void set_size(vector2<float> size);

        void set_position(vector2<float> position);

        void set_center(vector2<float> center);

        void set_rotation(float angle), rotate(float angle);

        void squeeze(vector2<float> sides);

        void set_scale(vector2<float> scale);

        void set_transparency(int transparency);

        void set_texture_part(vector4<int> bounds);

        void show();

        vector4<float> get_bounds();

        rgba_color get_fill_color();

    private:
        sprite_data _sprite_data;

        texture _texture;
        polygon _polygon;
    };
} // namespace ACE

#endif // ACEENGINE_HPP