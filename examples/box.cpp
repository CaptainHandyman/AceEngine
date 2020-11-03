/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-11-01 16:14:58
 * @modify date 2020-11-01 16:14:58
 * @version 0.04
 */

#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
ACE::box box;
SDL_Event event;

int main()
{
    window.create("C++", ACE_WINDOW_POS_CENTERED, ACE::vector2<int>(800, 800));

    box.set_size(ACE::vector2<float>(100, 100));
    box.set_fill_color(ACE::rgba_color(255, 0, 0));
    box.set_position(ACE::vector2<float>(200, 200));
    box.set_scale(ACE::vector2<float>(2, 2));

    while (window.is_open())
    {
        while (SDL_PollEvent(&event))
        {
            if (window.quit(event))
                window.close();
        }

        box.squeeze(ACE::vector2<float>(-0.004, 0));

        cout << box.get_bounds().w << endl;

        window.clear();
        box.show_filled();
        window.display();
    }
}