/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-28 14:48:50
 * @modify date 2020-11-05 12:08:19
 * @version 0.18
 * @desc This program is free software.
 *       You can redistribute it and/or modify.
 */

#include "../header_files/utilities.hpp"
using namespace ACE;

rgba_color::rgba_color() {}

rgba_color::rgba_color(Uint8 r, Uint8 g, Uint8 b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

rgba_color::rgba_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

SDL_DisplayMode display_mode;

vector2<int> screen::get_size() {
    SDL_GetCurrentDisplayMode(0, &display_mode);

    return {display_mode.w, display_mode.h};
}

bool mouse::left_button_pressed() {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
}

bool mouse::right_button_pressed() {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT);
}

bool mouse::middle_button_pressed() {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE);
}

bool mouse::wheel_scrolled_up(SDL_Event event) {
    if (event.type == SDL_MOUSEWHEEL)
        return event.wheel.y > 0;
}

bool mouse::wheel_scrolled_down(SDL_Event event) {
    if (event.type == SDL_MOUSEWHEEL)
        return event.wheel.y < 0;
}

vector2<int> mouse::get_position() {
    vector2<int> position;

    SDL_GetMouseState(&position.x, &position.y);

    return position;
}

float timer::in_milliseconds() {
    if (started)
        milliseconds = (float)(SDL_GetTicks() - a) / 1000;

    return milliseconds;
}

int timer::in_seconds() {
    if (started)
        return (SDL_GetTicks() - a) / 1000;
}

void timer::start() {
    if (!started) {
        a = SDL_GetTicks();
        started = true;
    }
}

void timer::stop() {
    if (started)
        started = false;
}

void timer::restart() {
    stop();
    start();
}

bool timer::is_started() { return started; }

const Uint8 *key = SDL_GetKeyboardState(NULL);

bool keyboard::is_key_pressed(SDL_Scancode scancode) { return key[scancode]; }

bool keyboard::is_any_key_pressed() {
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        if (key[i])
            return true;
    }

    return false;
}
