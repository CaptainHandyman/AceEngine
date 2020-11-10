/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:25
 * @modify date 2020-11-04 23:02:05
 * @version 0.14
 * @desc This program is free software.
 *       You can redistribute it and/or modify.
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
        /*
         * Default constructor.
         * If you want to set your own position or size or anything else,
         * you can type SDL_SetWindowSize(ACE::window::translate_to_sld(),
         * width, height) for size, for position
         * SDL_SetWindowPosition(ACE::window::translate_to_sdl(), x, y).
         */
        window();

        // Initializes OpenGL.
        void init_gl();

        // Creates a window.
        void create(ACE_STRING title, vector4<int> bounds);

        // Creates a window, but with centered position.
        void create(ACE_STRING title, vector2<int> size);

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

        /*
         * Clear and display functions are required for drawing.
         * Clear and display functions should always be performed in a while
         * loop.
         */
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

        // Returns the bounds (x, y, w, h).
        vector4<int> get_bounds();

        // Returns the fill color (RGB).
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
         * With set_rotation function you can rotate polygon only once,
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

        // Returns the bounds (x, y, w, h).
        vector4<float> get_bounds();

        // Returns the fill color (RGBA).
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
         * With set_rotation function, you can rotate box only once,
         * with rotate function, you can rotate more than once.
         * The rotate function must always be in a while loop.
         */
        void rotate(float angle), set_rotation(float angle);

        /*
         * With show_unfilled function, you can show current polygon unfilled,
         * with show_filled, filled.
         */
        void show_unfilled(), show_filled();

        // Squeezes current box.
        void squeeze(vector2<float> sides);

        // Sets the scale.
        void set_scale(vector2<float> scale);

        /*
         * Moves the box.
         * Note: if you disable vsync, the movement of the current polygon will
         * be very slow.
         */
        void move(vector2<float> sides);

        // Returns the bounds (x, y, w, h).
        vector4<float> get_bounds();

        // Returns the fill color (RGBA).
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
        // Default constructor.
        sprite();

        // Sets texture.
        void set_texture(texture _texture);

        // Sets size.
        void set_size(vector2<float> size);

        // Sets position.
        void set_position(vector2<float> position);

        /*
         * Sets center of rotation.
         * Default is ACE::vector2<float>(0, 0).
         */
        void set_center(vector2<float> center);

        /*
         * With set_rotation function, you can rotate sprite only once,
         * with rotate function, you can rotate more than once.
         * The rotate function must always be in a while loop.
         */
        void set_rotation(float angle), rotate(float angle);

        // Squeezes the sprite.
        void squeeze(vector2<float> sides);

        // Changes the scale of sprite.
        void set_scale(vector2<float> scale);

        // Sets transparency.
        void set_transparency(int transparency);

        // Sets part of texture, by default show fulls part.
        void set_texture_part(vector4<int> bounds);

        /*
         * Moves the sprite.
         * Note: if you disable vsync, the movement of the current polygon will
         * be very slow.
         */
        void move(vector2<float> sides);

        // Shows the sprite.
        void show();

        // Returns the bounds of the sprite (x, y, w, h).
        vector4<float> get_bounds();

        // Returns the fill color (RGBA).
        rgba_color get_fill_color();

      private:
        sprite_data _sprite_data;

        texture _texture;
        polygon _polygon;
    };

    class animation {
      public:
        /*
         * Inserts the texture part of sprites texture.
         * Tp means texture part.
         */
        void insert_tp(vector4<int> bounds);

        // Replaces the texture part with a new one.
        void replace_tp(int id, vector4<int> bounds);

        // Sets the time stamp for the animation in milliseconds.
        void set_time_stamp(float milliseconds);

        // Removes part of the texture from the array.
        void erase_tp(int id);

        /*
         * If you don't call start function, function play
         * wont work! Stop function stops the animation.
         * In play function, you need to specify the sprite.
         * The play function must always be in a while loop.
         */
        void start(), play(sprite &_sprite), stop();

        // Returns the number of pieces of the texture.
        int get_array_size();

        // Checks if the animation has started.
        bool is_started();

      private:
        animation_data _animation_data;

        timer _timer;
    } /* class animation */;

    class font {
      public:
      private:
    } /* class font */;

    class text {
      public:
      private:
    } /* class text */;
} // namespace ACE

#endif // ACEENGINE_HPP
