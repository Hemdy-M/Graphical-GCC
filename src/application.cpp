#include <application.hpp>

void App::RenderUI() noexcept {
    const int num = 64;
    ImGui::Begin("My UI");
    ImGui::TextColored(ImVec4(.0, 255.0, 255.0, 1.0), "Just a variable %d", num);
    ImGui::End();
}
