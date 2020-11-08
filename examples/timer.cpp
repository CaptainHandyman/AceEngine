#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
ACE::timer timer;
SDL_Event event;

int main() {
    window.create("timer", ACE_WINDOW_POS_CENTERED,
                  ACE::vector2<int>(800, 800));

    timer.start();

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            if (window.quit(event))
                window.close();
            if (event.key.keysym.scancode == SDL_SCANCODE_Q)
                timer.stop();
            if (event.key.keysym.scancode == SDL_SCANCODE_S)
                timer.start();
        }

        if (timer.in_milliseconds() >= 20)
            timer.restart();

        cout << timer.in_milliseconds() << endl;

        window.clear();
        window.display();
    }
}