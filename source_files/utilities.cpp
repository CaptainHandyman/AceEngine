/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:50
 * @modify date 2020-11-04 13:57:03
 * @version 0.045
 */

#include "../header_files/utilities.hpp"
using namespace ACE;

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

bool mouse::left_button_pressed()
{
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
}

bool mouse::right_button_pressed()
{
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT);
}

bool mouse::middle_button_pressed()
{
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE);
}

bool mouse::wheel_scrolled_up(SDL_Event event)
{
    if (event.type == SDL_MOUSEWHEEL)
        return event.wheel.y > 0;
}

bool mouse::wheel_scrolled_down(SDL_Event event)
{
    if (event.type == SDL_MOUSEWHEEL)
        return event.wheel.y < 0;
}

vector2<int> mouse::get_position()
{
    vector2<int> position;

    SDL_GetMouseState(&position.x, &position.y);

    return position;
}