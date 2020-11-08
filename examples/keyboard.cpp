#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
SDL_Event event;

int main() {
    window.create("window", ACE_WINDOW_POS_CENTERED,
                  ACE::vector2<int>(800, 800));

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            if (window.quit(event))
                window.close();
        }

        if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_D))
            cout << "Key 'D' was pressed!" << endl;

        window.clear();
        window.display();
    }
}