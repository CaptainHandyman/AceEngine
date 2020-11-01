/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-10-30 22:46:38
 * @modify date 2020-10-31 23:04:30
 * @version 0.035
 */

#include <AceEngine/AceEngine.hpp>

ACE::window window;
SDL_Event event;

int main()
{
    window.create("window", ACE_WINDOW_POS_CENTERED, ACE::vector2<int>(800, 800));

    while (window.is_open())
    {
        while (SDL_PollEvent(&event))
        {
            if (window.quit(event))
                window.close();
        }

        window.clear();
        window.display();
    }
}