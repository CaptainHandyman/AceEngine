/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:19
 * @modify date 2020-10-31 09:46:06
 * @version 0.025
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
        vector4<float> bounds;
        vector2<float> position;
        std::vector<vector2<float>> point_position;
        rgba_color fill_color;
    };
} // namespace ACE

#endif // STRUCTURES_HPP