#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <application.hpp>

static void glfw_error_callback(int error, const char* description);

int main(int, char**) {
    App::InitializedGLFWAndOtherStuff(glfw_error_callback);
    auto* win = App::CreateWindow();
    App::SetupImGUI(win);

    while (!glfwWindowShouldClose(win)) {
        App::Update(win);
    }

    App::TerminateProg(win);
}

static void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW error : " << error << " : " << description << std::endl;
}