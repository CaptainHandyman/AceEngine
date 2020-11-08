#include <AceEngine/AceEngine.hpp>

ACE::window window;
SDL_Event event;

// const int pos_x = ACE::screen::get_size().x / 2 - 400;
// const int pos_y = ACE::screen::get_size().y / 2 - 400;

int main() {
    window.create("window", ACE_WINDOW_POS_CENTERED,
                  ACE::vector2<int>(800, 800));
    // window.create("window", ACE::vector4<int>(pos_x, pos_y, 800, 800));

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            if (window.quit(event))
                window.close();
        }

        window.clear();
        window.display();
    }
}