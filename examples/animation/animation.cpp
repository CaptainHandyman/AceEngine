#include <AceEngine/AceEngine.hpp>

ACE::window window;
ACE::texture texture;
ACE::sprite sprite;
ACE::animation movement_animation[4];
SDL_Event event;

#define MOVEMENT_SPEED 0.04
#define ANIMATION_TIME_STAMP 0.2

void init_sprite_and_texture() {
    texture.load("animation.png");
    sprite.set_texture(texture);
}

void character_controller() {
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_D)) {
        if (sprite.get_bounds().x <=
            window.get_bounds().w - sprite.get_bounds().w)
            sprite.move(ACE::vector2<float>(MOVEMENT_SPEED, 0));

        if (!movement_animation[0].is_started())
            movement_animation[0].start();
        movement_animation[0].play(sprite);
    } else
        movement_animation[0].stop();
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_A)) {
        if (sprite.get_bounds().x >= 0)
            sprite.move(ACE::vector2<float>(-MOVEMENT_SPEED, 0));

        if (!movement_animation[1].is_started())
            movement_animation[1].start();
        movement_animation[1].play(sprite);
    } else
        movement_animation[1].stop();
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_W)) {
        if (sprite.get_bounds().y >= 0)
            sprite.move(ACE::vector2<float>(0, -MOVEMENT_SPEED));

        if (!movement_animation[2].is_started())
            movement_animation[2].start();
        movement_animation[2].play(sprite);
    } else
        movement_animation[2].stop();
    if (ACE::keyboard::is_key_pressed(SDL_SCANCODE_S)) {
        if (sprite.get_bounds().y <=
            window.get_bounds().h - sprite.get_bounds().h)
            sprite.move(ACE::vector2<float>(0, MOVEMENT_SPEED));

        if (!movement_animation[3].is_started())
            movement_animation[3].start();
        movement_animation[3].play(sprite);
    } else
        movement_animation[3].stop();
}

void init_animations() {
    for (int i = 0; i <= 3; i++) {
        movement_animation[i].set_time_stamp(ANIMATION_TIME_STAMP);
        movement_animation[i].start();
    }

    // Right animation
    movement_animation[0].insert_tp(ACE::vector4<int>(1, 566, 85, 130));
    movement_animation[0].insert_tp(ACE::vector4<int>(111, 561, 85, 135));
    movement_animation[0].insert_tp(ACE::vector4<int>(221, 566, 85, 130));
    movement_animation[0].insert_tp(ACE::vector4<int>(331, 561, 85, 135));

    // Left animation
    movement_animation[1].insert_tp(ACE::vector4<int>(1, 386, 85, 130));
    movement_animation[1].insert_tp(ACE::vector4<int>(116, 386, 85, 135));
    movement_animation[1].insert_tp(ACE::vector4<int>(221, 386, 85, 130));
    movement_animation[1].insert_tp(ACE::vector4<int>(331, 386, 85, 135));

    // Up animation
    movement_animation[2].insert_tp(ACE::vector4<int>(1, 201, 100, 140));
    movement_animation[2].insert_tp(ACE::vector4<int>(111, 201, 100, 150));
    movement_animation[2].insert_tp(ACE::vector4<int>(221, 201, 100, 140));
    movement_animation[2].insert_tp(ACE::vector4<int>(331, 201, 100, 150));

    // Down animation
    movement_animation[3].insert_tp(ACE::vector4<int>(6, 1, 100, 140));
    movement_animation[3].insert_tp(ACE::vector4<int>(116, 1, 100, 150));
    movement_animation[3].insert_tp(ACE::vector4<int>(226, 1, 100, 140));
    movement_animation[3].insert_tp(ACE::vector4<int>(336, 1, 100, 150));
}

int main() {
    window.create("animation", ACE::vector2<int>(800, 800));

    init_sprite_and_texture();
    init_animations();

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            if (window.quit(event))
                window.close();
        }

        character_controller();

        window.clear();
        sprite.show();
        window.display();
    }
}