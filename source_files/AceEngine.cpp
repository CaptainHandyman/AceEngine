/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:48
 * @modify date 2020-11-06 09:48:26
 * @version 0.12
 * @desc This program is free software.
 *       you can redistribute it and/or modify.
 */

#include "../header_files/AceEngine.hpp"
#include <stdexcept>
using namespace ACE;

bool CAN_DRAW_OBJECTS = false;

window::window() { SDL_Init(SDL_INIT_VIDEO); }

void window::init_gl() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    _window_data.gl_context = SDL_GL_CreateContext(_window);

    SDL_GL_SetSwapInterval(SDL_FALSE);
}

void window::create(ACE_STRING title, vector4<int> bounds) {
    _window = SDL_CreateWindow(title, bounds.x, bounds.y, bounds.w, bounds.h,
                               SDL_WINDOW_OPENGL);

    init_gl();

    _window_data.bounds = bounds;
}

void window::create(ACE_STRING title, vector2<int> size) {
    _window_data.bounds.x = screen::get_size().x / 2 - size.x / 2;
    _window_data.bounds.y = screen::get_size().y / 2 - size.y / 2;

    _window =
        SDL_CreateWindow(title, _window_data.bounds.x, _window_data.bounds.y,
                         size.x, size.y, SDL_WINDOW_OPENGL);

    _window_data.bounds.w = size.x;
    _window_data.bounds.h = size.y;

    init_gl();
}

void window::create(ACE_STRING title, uint8_t position, vector2<int> size) {
    switch (position) {
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

    _window =
        SDL_CreateWindow(title, _window_data.bounds.x, _window_data.bounds.y,
                         size.x, size.y, SDL_WINDOW_OPENGL);

    _window_data.bounds.w = size.x;
    _window_data.bounds.h = size.y;

    init_gl();
}

void window::set_flags(ACE_FLAGS window_flags) {
    switch (window_flags) {
    case ACE_WINDOW_NO_FLAGS:
        SDL_SetWindowFullscreen(_window, SDL_FALSE);
        SDL_SetWindowResizable(_window, SDL_FALSE);
        break;
    case ACE_WINDOW_FULLSCREEN:
        SDL_SetWindowSize(_window, screen::get_size().x, screen::get_size().y);
        SDL_SetWindowFullscreen(_window, SDL_TRUE);
        break;
    case ACE_WINDOW_RESIZABLE:
        SDL_SetWindowResizable(_window, SDL_TRUE);
        break;
    }
}

void window::set_fill_color(rgba_color fill_color) {
    _window_data.fill_color = fill_color;
}

void window::close() {
    SDL_DestroyWindow(_window);
    _window = NULL;
}

void window::set_vsync(bool _bool) {
    if (_bool)
        SDL_GL_SetSwapInterval(SDL_TRUE);
    else
        SDL_GL_SetSwapInterval(SDL_FALSE);
}

void window::set_position(uint8_t position) {
    switch (position) {
    case ACE_WINDOW_POS_CENTERED:
        _window_data.bounds.x =
            screen::get_size().x / 2 - _window_data.bounds.w / 2;
        _window_data.bounds.y =
            screen::get_size().y / 2 - _window_data.bounds.h / 2;
        break;
    case ACE_WINDOW_POS_TOP_LEFT:
        _window_data.bounds.x = 0;
        _window_data.bounds.y = 0;
        break;
    case ACE_WINDOW_POS_TOP_RIGHT:
        _window_data.bounds.x = screen::get_size().x - _window_data.bounds.w;
        _window_data.bounds.y = 0;
        break;
    case ACE_WINDOW_POS_BOTTOM_LEFT:
        _window_data.bounds.x = 0;
        _window_data.bounds.y = screen::get_size().y - _window_data.bounds.h;
        break;
    case ACE_WINDOW_POS_BOTTOM_RIGHT:
        _window_data.bounds.x = screen::get_size().x - _window_data.bounds.w;
        _window_data.bounds.y = screen::get_size().y - _window_data.bounds.h;
        break;
    }

    SDL_SetWindowPosition(_window, _window_data.bounds.x,
                          _window_data.bounds.y);
}

window &window::operator=(SDL_Window *_window) {
    this->_window = _window;

    return *this;
}

bool window::operator==(SDL_Window *_window) {
    return this->_window == _window;
}

bool window::operator!=(SDL_Window *_window) {
    return this->_window != _window;
}

bool window::quit(SDL_Event event) {
    if (event.type == SDL_WINDOWEVENT &&
        event.window.event == SDL_WINDOWEVENT_CLOSE) {
        if (_window != NULL &&
            SDL_GetWindowFromID(event.window.windowID) == _window)
            return true;
        else
            return false;
    }

    return false;
}

bool window::is_open() { return _window != NULL; }

void update_window_data(SDL_Window *_window, window_data &_window_data) {
    SDL_GetWindowSize(_window, &_window_data.bounds.w, &_window_data.bounds.h);
    SDL_GetWindowPosition(_window, &_window_data.bounds.x,
                          &_window_data.bounds.y);
}

void window::clear() {
    update_window_data(_window, _window_data);

    glClearColor(
        _window_data.fill_color.r != 0 ? _window_data.fill_color.r / 255 : 0,
        _window_data.fill_color.g != 0 ? _window_data.fill_color.g / 255 : 0,
        _window_data.fill_color.b != 0 ? _window_data.fill_color.b / 255 : 0,
        0);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, _window_data.bounds.w, _window_data.bounds.h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, _window_data.bounds.w, _window_data.bounds.h, 0, -10, 10);

    CAN_DRAW_OBJECTS = true;
}

void window::display() {
    CAN_DRAW_OBJECTS = false;

    SDL_GL_SwapWindow(_window);
}

SDL_Window *window::translate_to_sdl() { return _window; }

SDL_GLContext window::get_gl_context() { return _window_data.gl_context; }

vector4<int> window::get_bounds() { return _window_data.bounds; }

rgba_color window::get_fill_color() { return _window_data.fill_color; }

void polygon::set_point_count(uint64_t count) {
    for (int i = 0; i <= count; i++)
        _polygon_data.point_position.push_back(vector2<float>(0, 0));
}

void polygon::set_point_position(uint64_t id, vector2<float> position) {
    _polygon_data.point_position.at(id) = position;

    for (uint64_t i = 0; i < _polygon_data.point_position.size(); i++) {
        for (uint64_t j = i + 1; j < _polygon_data.point_position.size(); j++) {
            _polygon_data.bounds.w =
                std::max(_polygon_data.point_position.at(i).x,
                         _polygon_data.point_position.at(j).x);
            _polygon_data.bounds.h =
                std::max(_polygon_data.point_position.at(i).y,
                         _polygon_data.point_position.at(j).y);
        }
    }
}

void polygon::set_fill_color(rgba_color fill_color) {
    _polygon_data.fill_color = fill_color;
}

void polygon::begin() {
    if (CAN_DRAW_OBJECTS) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glTranslatef(_polygon_data.bounds.x + _polygon_data.center.x,
                     _polygon_data.bounds.y + _polygon_data.center.y, 0);
        glRotatef(_polygon_data.angle, 0, 0, 1);
        glTranslatef(-(_polygon_data.bounds.x + _polygon_data.center.x),
                     -(_polygon_data.bounds.y + _polygon_data.center.y), 0);

        glTranslatef(_polygon_data.bounds.x, _polygon_data.bounds.y, 0);
        glBegin(GL_POLYGON);
    }
}

void polygon::end() {
    if (CAN_DRAW_OBJECTS) {
        glEnd();

        glDisable(GL_BLEND);
    }
}

void polygon::set_position(vector2<float> position) {
    _polygon_data.bounds.x = position.x;
    _polygon_data.bounds.y = position.y;
}

void polygon::translate_point_to_vertex(uint64_t id) {
    _polygon_data.point_position.at(id).translate_to_vertex();
}

void polygon::show_unfilled() {
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    begin();
    {
        glColor4ub(_polygon_data.fill_color.r, _polygon_data.fill_color.g,
                   _polygon_data.fill_color.b, _polygon_data.fill_color.a);
        for (int i = 0; i < _polygon_data.point_position.size(); i++)
            translate_point_to_vertex(i);
    }
    end();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPopMatrix();
}

void polygon::show_filled() {
    glPushMatrix();

    begin();
    {
        glColor4ub(_polygon_data.fill_color.r, _polygon_data.fill_color.g,
                   _polygon_data.fill_color.b, _polygon_data.fill_color.a);
        for (int i = 0; i < _polygon_data.point_position.size(); i++)
            translate_point_to_vertex(i);
    }
    end();

    glPopMatrix();
}

void polygon::set_rotation(float angle) {
    _polygon_data.angle = angle;

    while (_polygon_data.angle > 360)
        _polygon_data.angle -= 360;
}

void polygon::rotate(float angle) { _polygon_data.angle += angle; }

void polygon::set_center(vector2<float> center) {
    _polygon_data.center = center;
}

void polygon::move(vector2<float> sides) {
    set_position(
        vector2<float>(get_bounds().x + sides.x, get_bounds().y + sides.y));
}

uint64_t polygon::get_point_count() {
    return _polygon_data.point_position.size();
}

vector4<float> polygon::get_bounds() { return _polygon_data.bounds; }

rgba_color polygon::get_fill_color() { return _polygon_data.fill_color; }

box::box() { _polygon.set_point_count(3); }

void box::set_size(vector2<float> size) {
    _polygon.set_point_position(1, vector2<float>(size.x, 0));
    _polygon.set_point_position(2, vector2<float>(size.x, size.y));
    _polygon.set_point_position(3, vector2<float>(0, size.y));
}

void box::set_position(vector2<float> position) {
    _polygon.set_position(position);
}

void box::set_fill_color(rgba_color fill_color) {
    _polygon.set_fill_color(fill_color);
}

void box::rotate(float angle) { _polygon.rotate(angle); }

void box::set_rotation(float angle) { _polygon.set_rotation(angle); }

void box::show_unfilled() { _polygon.show_unfilled(); }

void box::show_filled() { _polygon.show_filled(); }

void box::squeeze(vector2<float> sides) {
    set_size(
        vector2<float>(get_bounds().w - sides.x, get_bounds().h - sides.y));
    set_position(vector2<float>(get_bounds().x + sides.x / 2,
                                get_bounds().y + sides.y / 2));
}

void box::set_scale(vector2<float> scale) {
    vector2<float> size;

    if (scale.x >= 0)
        size.x = get_bounds().w * scale.x;
    else
        size.x = get_bounds().w / abs(scale.x);
    if (scale.y >= 0)
        size.y = get_bounds().h * scale.y;
    else
        size.y = get_bounds().h / abs(scale.y);

    set_size(size);
}

void box::move(vector2<float> sides) { _polygon.move(sides); }

vector4<float> box::get_bounds() { return _polygon.get_bounds(); }

rgba_color box::get_fill_color() { return _polygon.get_fill_color(); }

void texture::load(ACE_STRING path) {
    _texture_data.sufrace = IMG_Load(path);

    if (_texture_data.sufrace->format->Amask)
        _texture_data.format = GL_RGBA;
    else
        _texture_data.format = GL_RGB;

    glGenTextures(1, &_texture_data.id);
    glBindTexture(GL_TEXTURE_2D, _texture_data.id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    _texture_data.parameter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    _texture_data.parameter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    _texture_data.size.x = _texture_data.sufrace->w;
    _texture_data.size.y = _texture_data.sufrace->h;

    glTexImage2D(GL_TEXTURE_2D, 0, _texture_data.format, get_size().x,
                 get_size().y, 0, _texture_data.format, GL_UNSIGNED_BYTE,
                 _texture_data.sufrace->pixels);

    SDL_FreeSurface(_texture_data.sufrace);
}

void texture::set_smooth(bool _bool) {
    if (_bool)
        _texture_data.parameter = GL_LINEAR;
    else
        _texture_data.parameter = GL_NEAREST;
}

int texture::get_id() { return _texture_data.id; }

vector2<int> texture::get_size() { return _texture_data.size; }

ACE_STRING texture::get_format() {
    if (_texture_data.format == GL_RGBA)
        return "RGBA";
    else
        return "RGB";
}

bool texture::smoothed() { return _texture_data.parameter == GL_LINEAR; }

sprite::sprite() {
    _polygon.set_point_count(3);
    _polygon.set_fill_color(rgba_color(255, 255, 255, 255));

    _sprite_data.texture_part = {0, 0, 1, 1};
}

void sprite::set_texture(texture _texture) {
    this->_texture = _texture;

    set_size(vector2<float>(_texture.get_size().x, _texture.get_size().y));
}

void sprite::set_size(vector2<float> size) {
    _polygon.set_point_position(1, vector2<float>(size.x, 0));
    _polygon.set_point_position(2, vector2<float>(size.x, size.y));
    _polygon.set_point_position(3, vector2<float>(0, size.y));
}

void sprite::set_position(vector2<float> position) {
    _polygon.set_position(position);
}

void sprite::set_center(vector2<float> center) { _polygon.set_center(center); }

void sprite::set_rotation(float angle) { _polygon.set_rotation(angle); }

void sprite::rotate(float angle) { _polygon.rotate(angle); }

void sprite::squeeze(vector2<float> sides) {
    set_size(
        vector2<float>(get_bounds().w + sides.x, get_bounds().h + sides.y));
    set_position(vector2<float>(get_bounds().x - sides.x / 2,
                                get_bounds().y - sides.y / 2));
}

void sprite::set_scale(vector2<float> scale) {
    ACE::vector2<float> size;

    if (scale.x >= 0)
        size.x = get_bounds().w * scale.x;
    else
        size.x = get_bounds().w / abs(scale.x);
    if (scale.y >= 0)
        size.y = get_bounds().h * scale.y;
    else
        size.y = get_bounds().h / abs(scale.y);

    set_size(size);
}

void sprite::set_transparency(int transparency) {
    _polygon.set_fill_color(rgba_color(255, 255, 255, transparency));
}

void sprite::set_texture_part(vector4<int> bounds) {
    _sprite_data.texture_part.x = (float)bounds.x / _texture.get_size().x;
    _sprite_data.texture_part.y = (float)bounds.y / _texture.get_size().y;

    _sprite_data.texture_part.w =
        (float)(bounds.x + bounds.w) / _texture.get_size().x;
    _sprite_data.texture_part.h =
        (float)(bounds.y + bounds.h) / _texture.get_size().y;

    set_size(vector2<float>(bounds.w, bounds.h));
}

void sprite::move(vector2<float> sides) { _polygon.move(sides); }

void sprite::show() {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);

    _polygon.begin();
    {
        glTexCoord2f(_sprite_data.texture_part.x, _sprite_data.texture_part.y);
        _polygon.translate_point_to_vertex(0);
        glTexCoord2f(_sprite_data.texture_part.w, _sprite_data.texture_part.y);
        _polygon.translate_point_to_vertex(1);
        glTexCoord2f(_sprite_data.texture_part.w, _sprite_data.texture_part.h);
        _polygon.translate_point_to_vertex(2);
        glTexCoord2f(_sprite_data.texture_part.x, _sprite_data.texture_part.h);
        _polygon.translate_point_to_vertex(3);
    }
    _polygon.end();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

vector4<float> sprite::get_bounds() { return _polygon.get_bounds(); }

rgba_color sprite::get_fill_color() { return _polygon.get_fill_color(); }

void animation::insert_tp(vector4<int> bounds) {
    _animation_data.tp.push_back(bounds);
}

void animation::replace_tp(int id, vector4<int> bounds) {
    _animation_data.tp.at(id) = bounds;
}

void animation::set_time_stamp(float milliseconds) {
    _animation_data.time_stamp = milliseconds;
}

void animation::start() {
    if (!_animation_data.started)
        _animation_data.started = true;
}

void animation::play(sprite &_sprite) {
    if (_animation_data.started) {
        if (!_timer.is_started())
            _timer.start();

        if (_timer.in_milliseconds() > _animation_data.time_stamp) {
            _sprite.set_texture_part(
                _animation_data.tp.at(_animation_data.played_tp));
            _animation_data.played_tp++;
            _timer.restart();
        }

        if (_animation_data.played_tp > _animation_data.tp.size() - 1)
            _animation_data.played_tp = 0;
    }
}

void animation::stop() {
    if (_animation_data.started)
        _animation_data.started = false;
}

int animation::get_tp_size() { return _animation_data.tp.size(); }

bool animation::is_started() { return _animation_data.started; }