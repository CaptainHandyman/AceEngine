#include <AceEngine/AceEngine.hpp>

ACE::window window;
ACE::texture texture;
ACE::sprite sprite;
SDL_Event event;

int main()
{
    window.create("sprite", ACE_WINDOW_POS_CENTERED, ACE::vector2<int>(800, 800));

    // texture.set_smooth(true);
    texture.load("texture.png");
    sprite.set_texture(texture);
    sprite.set_scale(ACE::vector2<float>(2, 2));
    // sprite.set_texture_part(ACE::vector4<int>(x, y, width, height));

    while (window.is_open())
    {
        while (SDL_PollEvent(&event))
        {
            if (window.quit(event))
                window.close();
        }

        window.clear();
        sprite.show();
        window.display();
    }
}