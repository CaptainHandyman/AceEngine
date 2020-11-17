#include "includes.hpp"

ACE::window window;
ACE::box box;
SDL_Event event;

int main() {
    window.create("test_2", ACE::vector2<int>(800, 800));

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplOpenGL2_Init();
    ImGui_ImplSDL2_InitForOpenGL(window.translate_to_sdl(),
                                 window.get_gl_context());

    box.set_size(ACE::vector2<float>(100, 100));
    box.set_fill_color(ACE::rgba_color(255, 0, 0));

    while (window.is_open()) {
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (window.quit(event))
                window.close();
        }

        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplSDL2_NewFrame(window.translate_to_sdl());
        ImGui::NewFrame();

        window.clear();

        ImGui::ShowDemoWindow();

        box.show_filled();

        ImGui::Render();
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        window.display();
    }
}
