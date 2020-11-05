/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-11-05 13:08:33
 * @modify date 2020-11-05 13:08:33
 * @version 0.06
 */

#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
ACE::box box;
SDL_Event event;

#define MOVEMENT_SPEED 0.04

void controller()
{
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_D))
    {
        if (box.get_bounds().x <= window.get_bounds().w - box.get_bounds().w)
            box.move(ACE::vector2<float>(MOVEMENT_SPEED, 0));
    }
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_A))
    {
        if (box.get_bounds().x >= 0)
            box.move(ACE::vector2<float>(-MOVEMENT_SPEED, 0));
    }
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_W))
    {
        if (box.get_bounds().y >= 0)
            box.move(ACE::vector2<float>(0, -MOVEMENT_SPEED));
    }
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_S))
    {
        if (box.get_bounds().y <= window.get_bounds().h - box.get_bounds().h)
            box.move(ACE::vector2<float>(0, MOVEMENT_SPEED));
    }
}

int main()
{
    window.create("window", ACE_WINDOW_POS_CENTERED, ACE::vector2<int>(800, 800));

    box.set_size(ACE::vector2<float>(100, 100));
    box.set_position(ACE::vector2<float>(350, 350));
    box.set_fill_color(ACE::rgba_color(255, 0, 0));

    while (window.is_open())
    {
        while (SDL_PollEvent(&event))
        {
            if (window.quit(event))
                window.close();
        }

        controller();

        window.clear();
        box.show_filled();
        window.display();
    }
}