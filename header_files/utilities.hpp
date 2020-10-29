/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:47:31
 * @modify date 2020-10-29 23:29:10
 * @version 0.025
 */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "includes.hpp"

#define ACE_STRING const char *

namespace ACE
{
    template <typename T>
    class vector2
    {
    public:
        vector2();

        vector2(T x, T y);

        T x = 0, y = 0;
    };

    template <typename T>
    class vector4
    {
    public:
        vector4();

        vector4(T x, T y,
                T w, T h);

        T x = 0, y = 0,
          w = 0, h = 0;
    };

    class rgba_color
    {
    public:
        rgba_color();

        rgba_color(uint16_t r, uint16_t g,
                   uint16_t b);

        rgba_color(uint16_t r, uint16_t g,
                   uint16_t b, uint16_t a);

        uint16_t r = 0, g = 0,
                 b = 0, a = 0;
    };

    class screen
    {
    public:
        static vector2<uint32_t> get_size();
    };

#include "utilities.imp"

} // namespace ACE

#endif // TOOLS_HPP