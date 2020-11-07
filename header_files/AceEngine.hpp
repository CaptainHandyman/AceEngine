/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-11-04 23:02:05
 * @version 0.07
 * @desc This program is free software.
 *       you can redistribute it and/or modify.
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
enum {
    /* Disables all set flags */ ACE_WINDOW_NO_FLAGS = 1 << 0,
    /* Makes window fullscreen */ ACE_WINDOW_FULLSCREEN = 1 << 1,
    /* Makes window resizable */ ACE_WINDOW_RESIZABLE = 1 << 2
};
// Window flags

namespace ACE {
    class window {
      public:
        // Default constructor
        window();

        // Initializes OpenGL.
        void init_gl();

        // Creates a window.
        void create(ACE_STRING title, vector4<int> bounds);

        /*
         * Creates a window, but with ready-made position,
         * for example: ACE_WINDOW_POS_CENTERED, ACE_WINDOW_POS_TOP_LEFT etc.
         */
        void create(ACE_STRING title, uint8_t position, vector2<int> size);

        /*
         * Sets flags, for example: ACE_WINDOW_FULLSCREEN, ACE_WINDOW_RESIZABLE
         * etc., but if you set ACE_WINDOW_NO_FALGS all flags will be disabled!
         */
        void set_flags(ACE_FLAGS window_flags);

        // Sets the fill color.
        void set_fill_color(rgba_color fill_color);

        /*
         * Sets the ready-made position, for example:
         * ACE_WINDOW_POS_CENTERED, ACE_WINDOW_POS_TOP_LEFT.
         * You can't set your own position with this function.
         * If you want to set your own position, you need to type
         * SDL_SetWindowPosition(ACE::window::translate_to_sdl(), x, y)
         * or you can create a window with your own position!
         */
        void set_position(uint8_t position);

        // You can set your own SDL2 data for the window.
        window &operator=(SDL_Window *_window);

        // Checks if the current window is the same as another.
        bool operator==(SDL_Window *_window);

        // Checks if the current window isn't the same as another.
        bool operator!=(SDL_Window *_window);

        // Checks for quit.
        bool quit(SDL_Event event);

        // Checks if window is open.
        bool is_open();

        // Clear and display functions are required for drawing.
        void clear(), display();

        // Closes the window.
        void close();

        // Sets vertical sync.
        void set_vsync(bool _bool);

        /*
         * Translates the current window to the SDL2 window.
         * What for? Because if you need to set size, position or whatever,
         * you can just type SDL_SetWindowSize(translate_to_sdl(), 1920, 1080),
         * SDL_SetWindowPosition(translate_to_sdl(), 200, 200).
         */
        SDL_Window *translate_to_sdl();

        // Returns the OpenGL context.
        SDL_GLContext get_gl_context();

        // Returns the bounds of the window.
        vector4<int> get_bounds();

        // Returns the fill color of window.
        rgba_color get_fill_color();

      private:
        window_data _window_data;

        SDL_Window *_window;
    } /* class window */;

    class polygon {
      public:
        // Sets the count of points.
        void set_point_count(uint64_t count);

        // Sets the position of the point
        void set_point_position(uint64_t id, vector2<float> position);

        // Sets fill color.
        void set_fill_color(rgba_color fill_color);

        // Begin and end functions are required for drawing.
        void begin(), end();

        // Sets the position.
        void set_position(vector2<float> position);

        // Translates selected point to OpenGL vertex(glVertex2f(x, y)).
        void translate_point_to_vertex(uint64_t id);

        // With show_unfilled function, you can show current polygon unfilled,
        // with show_filled, filled.
        void show_unfilled(), show_filled();

        /*
         * With set_rotation function, you can rotate polygon only once,
         * with rotate function, you can rotate more than once.
         */
        void set_rotation(float angle), rotate(float angle);

        // Sets the center of the current polygon for rotation.
        void set_center(ACE::vector2<float> center);

        /*
         * Moves the current polygon in x and y coordinates.
         * Note: if you disable vsync, the movement of the current polygon will
         * be very slow.
         */
        void move(vector2<float> sides);

        // Returns the count of points.
        uint64_t get_point_count();

        // Returns the bounds.
        vector4<float> get_bounds();

        // Returns the fill color.
        rgba_color get_fill_color();

      private:
        polygon_data _polygon_data;
    } /* class polygon */;

    class box {
      public:
        // Default constructor.
        box();

        // Sets the size.
        void set_size(vector2<float> size);

        // Sets the position.
        void set_position(vector2<float> position);

        // Sets the fill color.
        void set_fill_color(rgba_color fill_color);

        /*
         * With set_rotation function, you can rotate polygon only once,
         * with rotate function, you can rotate more than once.
         */
        void rotate(float angle), set_rotation(float angle);

        // With show_unfilled function, you can show current polygon unfilled,
        // with show_filled, filled.
        void show_unfilled(), show_filled();

        // Squeezes current box.
        void squeeze(vector2<float> sides);

        // Sets the scale.
        void set_scale(vector2<float> scale);

        // Moves the box.
        void move(vector2<float> sides);

        // Returns the bounds.
        vector4<float> get_bounds();

        // Returns the fill color.
        rgba_color get_fill_color();

      private:
        polygon _polygon;
    };

    class texture {
      public:
        /*
         * Loads a texture from the specified path.
         * Formats: .png, .jpg, .jpeg, .bmp.
         */
        void load(ACE_STRING path);

        // Sets smoothness.
        void set_smooth(bool _bool);

        // Returns the id of current texture.
        int get_id();

        // Returns the size.
        vector2<int> get_size();

        // Returns the format.
        ACE_STRING get_format();

        // Checks if texture is smooth.
        bool smoothed();

      private:
        texture_data _texture_data;
    };

    class sprite {
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
