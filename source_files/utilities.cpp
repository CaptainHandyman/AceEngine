/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:50
 * @modify date 2020-10-29 23:29:18
 * @version 0.04
 */

#include "../header_files/utilities.hpp"
using namespace ACE;

int UTILITIES::get_string_length(ACE_STRING str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}

rgba_color::rgba_color() {}

rgba_color::rgba_color(uint16_t r, uint16_t g,
                       uint16_t b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

rgba_color::rgba_color(uint16_t r, uint16_t g,
                       uint16_t b, uint16_t a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

SDL_DisplayMode display_mode;

vector2<uint32_t> screen::get_size()
{
    SDL_GetCurrentDisplayMode(0, &display_mode);

    return {display_mode.w, display_mode.h};
}