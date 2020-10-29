/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:48
 * @modify date 2020-10-29 23:29:16
 * @version 0.025
 */

#include "../header_files/AceEngine.hpp"
#include <stdexcept>
using namespace ACE;

window::window()
{
    SDL_Init(SDL_INIT_VIDEO);
}

void window::init_gl()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    _window_data.gl_context = SDL_GL_CreateContext(_window);

    SDL_GL_SetSwapInterval(SDL_FALSE);
}

void window::create(ACE_STRING title, vector4<int> bounds)
{
    _window = SDL_CreateWindow(title, bounds.x,
                               bounds.y, bounds.w,
                               bounds.h, SDL_WINDOW_OPENGL);

    init_gl();

    _window_data.bounds = bounds;
}

void window::create(ACE_STRING title, uint16_t position, vector2<int> size)
{
    switch (position)
    {
    case ACE_WINDOW_POS_CENTERED:
        _window_data.bounds.x = screen::get_size().x / 2 - size.x / 2;
        _window_data.bounds.y = screen::get_size().y / 2 - size.y / 2;
        break;
    case ACE_WINDOW_POS_TOP_LEFT:
        _window_data.bounds.x = 0;
        _window_data.bounds.y = 0;
        break;
    case ACE_WINDOW_POS_TOP_RIGHT:
        _window_data.bounds.x = screen::get_size().x - size.x;
        _window_data.bounds.y = 0;
        break;
    case ACE_WINDOW_POS_BOTTOM_LEFT:
        _window_data.bounds.x = 0;
        _window_data.bounds.y = screen::get_size().y - size.y;
        break;
    case ACE_WINDOW_POS_BOTTOM_RIGHT:
        _window_data.bounds.x = screen::get_size().x - size.x;
        _window_data.bounds.y = screen::get_size().y - size.y;
        break;
    }

    _window = SDL_CreateWindow(title, _window_data.bounds.x,
                               _window_data.bounds.y, size.x,
                               size.y, SDL_WINDOW_OPENGL);

    init_gl();

    _window_data.bounds.w = size.x;
    _window_data.bounds.h = size.y;
}

void window::set_fill_color(rgba_color fill_color)
{
    _window_data.fill_color = fill_color;
}

window &window::operator=(SDL_Window *_window)
{
    this->_window = _window;

    return *this;
}

bool window::operator==(SDL_Window *_window)
{
    return this->_window == _window;
}

bool window::operator!=(SDL_Window *_window)
{
    return this->_window != _window;
}

bool window::quit(SDL_Event event)
{
    if (event.type == SDL_WINDOWEVENT &&
        event.window.event == SDL_WINDOWEVENT_CLOSE)
    {
        if (_window != NULL &&
            SDL_GetWindowFromID(event.window.windowID) == _window)
            return true;
        else
            return false;
    }

    return false;
}

bool window::is_open()
{
    return _window != NULL;
}

void window::clear()
{
    glClearColor(_window_data.fill_color.r != 0 ? _window_data.fill_color.r / 255 : 0,
                 _window_data.fill_color.g != 0 ? _window_data.fill_color.g / 255 : 0,
                 _window_data.fill_color.b != 0 ? _window_data.fill_color.b / 255 : 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, _window_data.bounds.w, _window_data.bounds.h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, _window_data.bounds.w, _window_data.bounds.h, 0, -10, 10);
}

void window::display()
{
    SDL_GL_SwapWindow(_window);
}

SDL_Window *window::translate_to_sdl()
{
    return _window;
}