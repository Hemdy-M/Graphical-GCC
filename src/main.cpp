#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <application.hpp>

static void glfw_error_callback(int error, const char* description);

int main(int, char**) {
    App::InitializedGLFWAndOtherStuff(glfw_error_callback);
    GLFWwindow* window = glfwCreateWindow(480, 720, "ImGCC", nullptr, nullptr);
    if (!window) {
        std::cerr << "The window is not initialized" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    App::SetupImGUI(window);

    while (!glfwWindowShouldClose(window)) {
        App::Update(window);
    }

    App::TerminateProg(window);
}

static void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW error : " << error << " : " << description << std::endl;
}