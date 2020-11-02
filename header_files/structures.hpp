/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:19
 * @modify date 2020-11-03 03:53:43
 * @version 0.04
 */

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include "includes.hpp"
#include "utilities.hpp"
#include <vector>

namespace ACE
{
    struct window_data
    {
        vector4<int> bounds;
        rgba_color fill_color;
        SDL_GLContext gl_context;
    };

    struct polygon_data
    {
        vector2<float> center;
        vector4<float> bounds;
        std::vector<vector2<float>> point_position;
        rgba_color fill_color;
        float angle = 0;
    };

    struct texture_data
    {
        SDL_Surface *sufrace;
        unsigned int id = 0;
        vector2<int> size;
        int format, parameter = GL_NEAREST;
    };
} // namespace ACE

#endif // STRUCTURES_HPP