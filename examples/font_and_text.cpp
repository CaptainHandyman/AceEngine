#include <AceEngine/AceEngine.hpp>
#include <iostream>
using namespace std;

ACE::window window;
ACE::font font;
ACE::text text;
SDL_Event event;

int main() {
    window.create("font_text", ACE::vector2<int>(800, 800));

    font.load("font.ttf", 40);
    text.set_font(font);
    text.set_string("text");
    text.set_fill_color(ACE::rgba_color(255, 0, 0));

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            if (window.quit(event))
                window.close();
        }

        cout << "text_size: " << text.get_bounds().w << ", "
             << text.get_bounds().h << endl;
        cout << "text_position: " << text.get_bounds().x << ", "
             << text.get_bounds().y << endl;
        cout << "text_string: " << text.get_string() << endl;

        cout << "font_thickness: " << font.get_thickness() << endl;

        window.clear();
        text.show();
        window.display();
    }
}
