/**
 * @author Alexandr
 * @email alexandralibekov@yahoo.com
 * @create date 2020-11-04 13:50:23
 * @modify date 2020-11-04 13:50:23
 * @version 0.045
 */

#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
SDL_Event event;

void print_mouse_position()
{
    cout << "Position X: " << ACE::mouse::get_position().x << endl;
    cout << "Position Y: " << ACE::mouse::get_position().y << endl;
}

int main()
{
    window.create("mouse", ACE_WINDOW_POS_CENTERED, ACE::vector2<int>(800, 800));

    while (window.is_open())
    {
        while (SDL_PollEvent(&event))
        {
            if (window.quit(event))
                window.close();

            if (ACE::mouse::wheel_scrolled_up(event))
                cout << "Wheel scrolled up" << endl;
            if (ACE::mouse::wheel_scrolled_down(event))
                cout << "Wheel scrolled down" << endl;
        }

        if (ACE::mouse::left_button_pressed())
        {
            cout << "Button left was pressed!" << endl;
            print_mouse_position();
        }
        if (ACE::mouse::right_button_pressed())
        {
            cout << "Button right was pressed!" << endl;
            print_mouse_position();
        }
        if (ACE::mouse::middle_button_pressed())
        {
            cout << "Button middle was pressed!" << endl;
            print_mouse_position();
        }

        window.clear();
        window.display();
    }
}