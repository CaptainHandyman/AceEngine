/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-31 23:04:46
 * @modify date 2020-11-01 16:15:50
 * @version 0.03
 */

#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
ACE::polygon polygon;
SDL_Event event;

int main()
{
    window.create("polygon", ACE_WINDOW_POS_CENTERED, ACE::vector2<int>(800, 800));
    window.set_flags(ACE_WINDOW_RESIZABLE);

    SDL_SetWindowSize(window.translate_to_sdl(), ACE::screen::get_size().x,
                      ACE::screen::get_size().y);

    polygon.set_point_count(3);
    polygon.set_point_position(0, ACE::vector2<float>(0, 0));
    polygon.set_point_position(1, ACE::vector2<float>(100, 0));
    polygon.set_point_position(2, ACE::vector2<float>(100, 100));
    polygon.set_point_position(3, ACE::vector2<float>(0, 100));
    polygon.set_fill_color({255, 0, 0, 255});
    polygon.set_position(ACE::vector2<float>(ACE::screen::get_size().x / 2 - 50,
                                             ACE::screen::get_size().y / 2 - 50));
    polygon.set_center(ACE::vector2<float>(50, 50));

    while (window.is_open())
    {
        while (SDL_PollEvent(&event))
        {
            if (window.quit(event))
                window.close();
        }

        window.clear();
        polygon.show_filled();
        window.display();
    }
}