/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:19
 * @modify date 2020-10-28 22:46:06
 * @version 0.025
 */

#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include "includes.hpp"
#include "utilities.hpp"

namespace ACE
{
    struct window_data
    {
        vector4<int> bounds;
        rgba_color fill_color;
        SDL_GLContext gl_context;
    };
} // namespace ACE

#endif // STRUCTURES_HPP