/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:19
 * @modify date 2020-11-04 01:55:34
 * @version 0.16
 * @desc This program is free software.
 *       You can redistribute it and/or modify.
 */

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include "includes.hpp"
#include "utilities.hpp"
#include <SDL2/SDL_ttf.h>
#include <vector>

namespace ACE {
    struct window_data {
        vector4<int> bounds;
        rgba_color fill_color;
        SDL_GLContext gl_context;
    } /* window_data */;

    struct polygon_data {
        vector2<float> center;
        vector4<float> bounds;
        std::vector<vector2<float>> point_position;
        rgba_color fill_color;
        float angle = 0;
    } /* polygon_data */;

    struct texture_data {
        SDL_Surface *sufrace;
        unsigned int id = 0;
        vector2<int> size;
        int format, parameter = GL_NEAREST;
    } /* texture_data */;

    struct sprite_data {
        vector4<float> texture_part;
    } /* sprite_data */;

    struct animation_data {
        float time_stamp;
        std::vector<vector4<int>> tp;
        int played_tp = 0;
        bool started = false;
    };

    struct text_data {
        ACE_STRING text;
        SDL_Surface *surface;
        vector4<float> bounds;
        rgba_color fill_color;
        bool build;
        uint id;
    };
} // namespace ACE

#endif // STRUCTURES_HPP
