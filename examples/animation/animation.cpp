#include <AceEngine/AceEngine.hpp>

ACE::window window;
ACE::texture texture;
ACE::sprite sprite;
ACE::animation animation;
SDL_Event event;

const float ANIMATION_TIME_STAMP = 0.4;

int main()
{
    window.create("animation", ACE::vector2<int>(800, 800));

    texture.load("animation.png");
    sprite.set_texture(texture);
    sprite.set_texture_part(ACE::vector4<int>(0, 0, 100, 100));

    animation.set_time_stamp(ANIMATION_TIME_STAMP);
    animation.insert_tp(ACE::vector4<int>(0, 0, 100, 100));
    animation.insert_tp(ACE::vector4<int>(100, 0, 100, 100));
    animation.start();

    while(window.is_open())
    {
        while(SDL_PollEvent(&event))
        {
            if(window.quit(event))
                window.close();
        }

        animation.play(sprite);

        window.clear();
        sprite.show();
        window.display();
    }
}