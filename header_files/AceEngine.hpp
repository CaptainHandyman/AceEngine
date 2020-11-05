/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-11-04 23:02:05
 * @version 0.06
 */

#ifndef ACEENGINE_HPP
#define ACEENGINE_HPP

#include "includes.hpp"
#include "structures.hpp"

// Ready-made positions
#define ACE_WINDOW_POS_CENTERED 0x0u
#define ACE_WINDOW_POS_TOP_LEFT 0x1u
#define ACE_WINDOW_POS_TOP_RIGHT 0x2u
#define ACE_WINDOW_POS_BOTTOM_LEFT 0x3u
#define ACE_WINDOW_POS_BOTTOM_RIGHT 0x4u
// Ready-made positions

// Window flags
enum
{
    /* Disables all set flags */ ACE_WINDOW_NO_FLAGS = 1 << 0,
    /* Makes window fullscreen */ ACE_WINDOW_FULLSCREEN = 1 << 1,
    /* Makes window resizable */ ACE_WINDOW_RESIZABLE = 1 << 2
};
// Window flags

namespace ACE
{
    class window
    {
    public:
        // Default constructor
        window();

        // This function initializes OpenGL.
        void init_gl();

        // This function creates a window.
        void create(ACE_STRING title, vector4<int> bounds);

        /*
         * This function creates a window, but with ready-made position,
         * for example: ACE_WINDOW_POS_CENTERED, ACE_WINDOW_POS_TOP_LEFT etc.
         */
        void create(ACE_STRING title, uint8_t position,
                    vector2<int> size);

        /*
         * This function sets flags for window, for example:
         * ACE_WINDOW_FULLSCREEN, ACE_WINDOW_RESIZABLE,
         * but if you set ACE_WINDOW_NO_FALGS all flags will be disabled!
         */
        void set_flags(ACE_FLAGS window_flags);

        // This function sets the fill color of the window.
        void set_fill_color(rgba_color fill_color);

        // This function sets the position of the window.
        void set_position(uint8_t position);

        // You can set your own SDL2 data for the window.
        window &operator=(SDL_Window *_window);

        // This boolean checks if the current window is the same as another.
        bool operator==(SDL_Window *_window);

        // This boolean checks if the current window isn't the same as another.
        bool operator!=(SDL_Window *_window);

        bool /* Check for quit. */ quit(SDL_Event event),
            /* Checks if window is open. */ is_open();

        /*
         * Clear and display functions are required for drawing.
         */
        void clear(), display(),
            /* Closes the window. */ close();

        /*
         * This function sets vertical sync.
         */
        void set_vsync(bool _bool);

        /*
         * This function translates the current window to the SDL2 window.
         * What for? Because if you need to set size, position or whatever,
         * you can just type SDL_SetWindowSize(translate_to_sdl(), 1920, 1080), 
         * SDL_SetWindowPosition(translate_to_sdl(), 200, 200).
         */
        SDL_Window *translate_to_sdl();

        SDL_GLContext get_gl_context();

        // This function returns the bounds of the window.
        vector4<int> get_bounds();

        // With this function you can get the RGB color of the window.
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

        void move(vector2<float> sides);

        uint64_t get_point_count();

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

        void move(vector2<float> sides);

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

        void move(vector2<float> sides);

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